/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 16:12:50 by maks              #+#    #+#             */
/*   Updated: 2019/08/26 19:14:11 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void init_block_header(
	t_block_header *block_header,
	char zone_type,
	size_t data_size,
	t_block_header *prev)
{
	ft_bzero(block_header, sizeof(t_block_header));
	block_header->is_free = 1;
	block_header->zone_type = zone_type;
	block_header->data_size = data_size;
	block_header->prev = prev;
}

static void fill_memory_with_blocks(
	t_memory_zone *zone,
	char *mem,
	size_t allocation_size
	)
{
	register unsigned int	i;
	t_block_header			*header;
	t_block_header			block_header;
	size_t					full_block_size;

	i = 0;
	full_block_size = HEADER_SIZE + zone->data_size;
	header = NULL;
	while (i <= allocation_size - full_block_size)
	{
		init_block_header(&block_header, zone->type, zone->data_size, header);
		ft_memcpy(&mem[i], &block_header, sizeof(block_header));
		if (header)
			header->next = (t_block_header *)&mem[i];
		header = (t_block_header *)&mem[i];
		i += full_block_size;
	}
}

void	append_zone(t_memory_zone *zone)
{
	char 			*mem;
	t_block_header	*header;

	header = zone->first_block;
	while (header->next)
		header = header->next;
	if (!(mem = init_zone(zone)))
		return;
	header->next = (t_block_header *)mem;
	header->next->prev = header;
}

void *init_zone(t_memory_zone *zone)
{
	size_t					full_block_size;
	size_t					allocation_size;
	char 					*mem;

	full_block_size = HEADER_SIZE + zone->data_size;
	allocation_size = ALIGN_TO_PAGE_SIZE(full_block_size * zone->block_number);
	zone->size += allocation_size;
	if (!(mem = (char *)allocate_memory(zone->size)))
		return (NULL);
	fill_memory_with_blocks(zone, mem, allocation_size);
	return (mem);
}