/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:21:31 by maks              #+#    #+#             */
/*   Updated: 2019/08/24 16:06:04 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_memory_zone g_memory_zones[ZONE_QTY] = {
	{NULL, NULL, TINY, 0, TINY_BLOCK_SIZE, TINY_BLOCK_NUMBER, 0},
	{NULL, NULL, SMALL, 0, SMALL_BLOCK_SIZE, SMALL_BLOCK_NUMBER, 0},
	{NULL, NULL, LARGE, 0, 0, 0, 0}
};

pthread_mutex_t		g_malloc_mutex = PTHREAD_MUTEX_INITIALIZER;

void *find_free_block(t_memory_zone *zone, size_t size)
{
	t_block_header	*header;

	header = zone->first_block;
	while (header)
	{
		if (header->is_free && header->data_size >= size) {
			header->is_free = 0;
			header->data_size = size;
			return header;
		}
		header = header->next;
	}
	return NULL;
}

void *get_predefined_block(t_memory_zone *zone, size_t size)
{
	t_block_header *free_block;
	if (zone->first_block == NULL)
		zone->first_block = (t_block_header *)init_zone(zone);
	free_block = find_free_block(zone, size);
	if (!free_block)
	{
		zone->last_block->next = (t_block_header *)init_zone(zone);
		free_block = find_free_block(zone, size);
	}
	if (!free_block)
		return NULL;
	fragment_block(free_block);
	return (free_block);
}

void * __malloc(size_t size)
{
	void		*ptr;
	const int	zone_type = GET_ZONE_TYPE(size);

	ptr = NULL;
	if (zone_type == TINY || zone_type == SMALL)
	{
		ptr = get_predefined_block(&g_memory_zones[zone_type], size);
	}
	return (DATA_ADDRESS(ptr));
}

void *malloc(size_t size)
{
	void *ptr;

	if (!size)
		return NULL;
	if (pthread_mutex_lock(&g_malloc_mutex) == 0)
	{
		ptr = __malloc(size);
		pthread_mutex_unlock(&g_malloc_mutex);
		return (ptr);
	}
	return (NULL);
}