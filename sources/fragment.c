/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fragment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 16:36:59 by maks              #+#    #+#             */
/*   Updated: 2019/08/24 19:29:07 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	fragment_block(t_block_header *header)
{
	t_block_header fragment_header;
	size_t	size_gap;
	uintptr_t block_end;
	uintptr_t block_start;
	uintptr_t data_addr;

	if (!header)
		return;
	block_start = (uintptr_t)header;
	data_addr = (uintptr_t)DATA_ADDRESS(header);
	if (header->next)
		block_end = (uintptr_t)header->next;
	else
		block_end = PAGE_END(BLOCK_END(header));
	size_gap = block_end - (uintptr_t)DATA_END_ADDRESS(header);
	if (size_gap > HEADER_SIZE)
	{
		init_block_header(&fragment_header, header->zone_type,
			size_gap - HEADER_SIZE, header);
		fragment_header.next = header->next;
		ft_memcpy(DATA_END_ADDRESS(header), &fragment_header, HEADER_SIZE);
		if (header->next)
			header->next->prev = (t_block_header *)DATA_END_ADDRESS(header);
		header->next = header->next->prev;
	}
}

static t_block_header *defragment_back(t_block_header *header)
{
	t_block_header *start_block;
	size_t size;

	start_block = header;
	while ((header = header->prev) && header->is_free)
	{
		size = FULL_BLOCK_SIZE(start_block->data_size);
		size += REAL_DATA_SIZE(header);
		if (!(size <= g_memory_zones[(int)start_block->zone_type].data_size
			&& BLOCKS_CONTINIOUS(header, start_block)))
			break;
		header->data_size = size;
		header->next = start_block->next;
		start_block->next->prev = header;
		start_block = header;
	}
	return (start_block);
}

void	defragment_block(t_block_header *header)
{
	header = defragment_back(header);
}