/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:21:31 by maks              #+#    #+#             */
/*   Updated: 2019/08/26 19:12:01 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_memory_zone g_memory_zones[ZONE_QTY] = {
	{NULL, TINY, 0, TINY_BLOCK_SIZE, TINY_BLOCK_NUMBER},
	{NULL, SMALL, 0, SMALL_BLOCK_SIZE, SMALL_BLOCK_NUMBER},
	{NULL, LARGE, 0, 0, 1}
};

pthread_mutex_t		g_malloc_mutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER;

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
	return (NULL);
}

void *get_predefined_block(t_memory_zone *zone, size_t size)
{
	t_block_header *free_block;
	if (zone->first_block == NULL)
		zone->first_block = (t_block_header *)init_zone(zone);
	free_block = find_free_block(zone, size);
	if (!free_block)
	{
		append_zone(zone);
		free_block = find_free_block(zone, size);
	}
	if (!free_block)
		return (NULL);
	fragment_block(free_block);
	return (free_block);
}

void *get_separate_block(t_memory_zone *zone, size_t size)
{
	t_block_header	*header;
	t_block_header	*mem;

	zone->data_size = size;
	if (!(mem = init_zone(zone)))
		return (NULL);
	mem->is_free = 0;
	mem->data_size = size;
	if (!zone->first_block)
		zone->first_block = mem;
	else
	{
		header = zone->first_block;
		while(header->next)
			header = header->next;
		header->next = mem;
		header->next->prev = header;
	}
	return (mem);
}

void *malloc(size_t size)
{
	void *ptr;
	const int zone_type = GET_ZONE_TYPE(size);

	if (!size)
		return NULL;
	ptr = NULL;
	if (pthread_mutex_lock(&g_malloc_mutex) == 0)
	{
		if (zone_type == TINY || zone_type == SMALL)
			ptr = get_predefined_block(&g_memory_zones[zone_type], size);
		else
			ptr = get_separate_block(&g_memory_zones[zone_type], size);
		pthread_mutex_unlock(&g_malloc_mutex);
	}
	return (DATA_ADDRESS(ptr));
}