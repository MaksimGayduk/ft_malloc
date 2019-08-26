/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fragment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 16:36:59 by maks              #+#    #+#             */
/*   Updated: 2019/08/26 16:01:15 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	fragment_block(t_block_header *header)
{
	t_block_header fragment_header;
	t_block_header *fragment_header_addr;
	size_t	size_gap;

	if (!header)
		return;
	size_gap = REAL_DATA_SIZE(header) - header->data_size;
	if (size_gap > HEADER_SIZE)
	{
		init_block_header(&fragment_header, header->zone_type,
			size_gap - HEADER_SIZE, header);
		fragment_header.next = header->next;
		fragment_header_addr = (t_block_header *)DATA_END_ADDRESS(header);
		ft_memcpy(fragment_header_addr, &fragment_header, HEADER_SIZE);
		if (header->next)
			header->next->prev = fragment_header_addr;
		header->next = fragment_header_addr;
	}
}

static t_block_header *defragment_back(t_block_header *header)
{
	t_block_header *start_block;
	size_t size;

	start_block = header;
	while ((header = header->prev) && header->is_free)
	{
		size = REAL_BLOCK_SIZE(start_block);
		size += REAL_DATA_SIZE(header);
		if (size > GET_BLOCK_ZONE(start_block).data_size ||
			!BLOCKS_CONTINIOUS(header, start_block))
			break;
		header->data_size = size;
		header->next = start_block->next;
		start_block->next->prev = header;
		start_block = header;
	}
	return (start_block);
}

static t_block_header *defragment_forward(t_block_header *header)
{
	t_block_header *start_block;
	size_t size;

	start_block = header;
	while ((header = header->next) && header->is_free)
	{
		size = REAL_DATA_SIZE(start_block);
		size += FULL_BLOCK_SIZE(header);
		if (size > GET_BLOCK_ZONE(start_block).data_size ||
			!BLOCKS_CONTINIOUS(header, start_block))
			break;
		start_block->data_size = size;
		start_block->next = header->next;
		header->next->prev = start_block;
	}
	return (start_block);
}

void	defragment_block(t_block_header *header)
{
	header = defragment_back(header);
	header = defragment_forward(header);
}