/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 16:12:50 by maks              #+#    #+#             */
/*   Updated: 2019/08/23 15:42:38 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void init_block_header(
	t_block_header *block_header,
	size_t data_size,
	t_block_header *prev)
{
	ft_bzero(block_header, sizeof(t_block_header));
	block_header->is_free = 1;
	block_header->data_size = data_size;
	block_header->prev = prev;
}

static void fill_memory_with_blocks(
	t_memory_zone *zone,
	char *mem,
	size_t allocation_size)
{
	register unsigned int	i;
	t_block_header			*last_block;
	t_block_header			block_header;
	size_t					full_block_size;

	i = 0;
	full_block_size = FULL_BLOCK_SIZE(zone->data_size);
	last_block = zone->last_block;
	while (i <= allocation_size - full_block_size)
	{
		init_block_header(&block_header, zone->data_size, last_block);
		ft_memcpy(&mem[i], &block_header, sizeof(block_header));
		if (last_block)
			last_block->next = (t_block_header *)&mem[i];
		last_block = (t_block_header *)&mem[i];
		i += full_block_size;
		zone->last_block = last_block;
	}
}

void *init_zone(t_memory_zone *zone)
{
	size_t					full_block_size;
	size_t					allocation_size;
	char 					*mem;

	full_block_size = FULL_BLOCK_SIZE(zone->data_size);
	allocation_size = FT_ALIGN_TO(
		full_block_size * zone->block_number,
		getpagesize());
	zone->size += allocation_size;
	zone->block_number_current += allocation_size / full_block_size;
	if (!(mem = (char *)allocate_memory(zone->size)))
		return NULL;
	fill_memory_with_blocks(zone, mem, allocation_size);
	return mem;
}