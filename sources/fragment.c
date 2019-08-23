/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fragment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 16:36:59 by maks              #+#    #+#             */
/*   Updated: 2019/08/23 18:06:08 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void fragment_block(t_block_header *header)
{
	t_block_header fragment_header;
	size_t	size_offset;
	uintptr_t block_end;
	uintptr_t block_start;
	uintptr_t data_addr;

	block_start = (uintptr_t)header;
	data_addr = (uintptr_t)DATA_ADDRESS(header);
	if (header->next)
		block_end = (uintptr_t)header->next;
	else
		block_end = PAGE_END(BLOCK_END(header));
	size_offset = block_end - (uintptr_t)DATA_END_ADDRESS(header);
	if (size_offset > HEADER_SIZE)
	{
		init_block_header(&fragment_header, size_offset - HEADER_SIZE, header);
		fragment_header.next = header->next;
		ft_memcpy(DATA_END_ADDRESS(header), &fragment_header, HEADER_SIZE);
		if (header->next)
			header->next->prev = (t_block_header *)DATA_END_ADDRESS(header);
		header->next = header->next->prev;
	}
}