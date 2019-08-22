/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:21:31 by maks              #+#    #+#             */
/*   Updated: 2019/08/22 11:06:20 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_memory_zone g_memory_zones[ZONE_QTY] = {
	{NULL, TINY, 0, TINY_BLOCK_SIZE, TINY_BLOCK_NUMBER},
	{NULL, SMALL, 0, SMALL_BLOCK_SIZE, SMALL_BLOCK_NUMBER},
	{NULL, LARGE, 0, 0, 0}
};

void *get_free_block(t_memory_zone *zone, size_t size)
{
	uintptr_t addr;
	t_block_header *header;

	header = zone->first_header;
	while (header)
	{
		addr = (uintptr_t)header;
		if (header->is_free && header->block_size >= size) {
			header->is_free = 0;
			header->block_size = size;
			return (char *)header + sizeof(t_block_header);
		}
		header = header->next;
	}

	return NULL;
}

void *get_predefined_block(t_memory_zone *zone, size_t size)
{
	if (zone->first_header == NULL)
		zone->first_header = (t_block_header *)init_zone(zone);

	return get_free_block(zone, size);
}

void *malloc(size_t size)
{
	void		*ptr = NULL;
	const int	zone_type = (size > TINY_BLOCK_SIZE) + (size > SMALL_BLOCK_SIZE);

	if (zone_type == TINY || SMALL)
	{
		ptr = get_predefined_block(&g_memory_zones[zone_type], size);
	}

	return ptr;
}