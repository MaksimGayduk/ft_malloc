/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_zone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 16:12:50 by maks              #+#    #+#             */
/*   Updated: 2019/08/21 16:26:20 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void init_block_header(
	t_block_header *block_header,
	size_t block_size,
	t_block_header *prev)
{
	ft_bzero(block_header, sizeof(block_header));
	block_header->is_free = 1;
	block_header->block_size = block_size;
	block_header->prev = prev;

	// delete
	block_header->x = i;
}

void *init_zone(t_memory_zone *zone)
{
	register unsigned int	i;
	size_t					chunk_size;
	t_block_header			block_header;
	t_block_header			*last_block;

	chunk_size = zone->block_size + sizeof(t_block_header);
	zone->size = chunk_size * zone->block_number;
	zone->size = FT_ALIGN_TO(zone->size, getpagesize());
	zone->block_number = zone->size / zone->block_size;

	char *mem = (char *)allocate_memory(zone->size);

	i = 0;
	last_block = NULL;
	while (i <= zone->size - chunk_size)
	{
		init_block_header(&block_header, zone->block_size, last_block);
		ft_memcpy(&mem[i], &block_header, sizeof(block_header));
		if (last_block)
			last_block->next = (t_block_header *)&mem[i];
		last_block = (t_block_header *)&mem[i];
		i += chunk_size;
	}
	last_block->next = NULL;

	return mem;
}