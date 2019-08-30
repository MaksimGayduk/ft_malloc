/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:02:47 by maks              #+#    #+#             */
/*   Updated: 2019/08/30 16:17:42 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*allocate_memory(size_t size)
{
	void *mem;

	mem = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (mem == MAP_FAILED)
		return (NULL);
	return (mem);
}

static void	unallocate_zone(t_memory_zone *zone)
{
	t_block_header	*header;
	t_block_header	*start;
	t_block_header	*prev;
	size_t			size;

	size = 0;
	header = zone->first_block;
	start = header;
	prev = header;
	while ((header = header->next))
	{
		size += REAL_BLOCK_SIZE(prev);
		if (!header->next)
		{
			munmap(start, ALIGN_TO_PAGE_SIZE(size + REAL_BLOCK_SIZE(header)));
			return ;
		}
		else if (!BLOCKS_CONTINIOUS(prev, header))
		{
			munmap(start, ALIGN_TO_PAGE_SIZE(size));
			start = header;
			size = 0;
		}
		prev = header;
	}
}

void		reset_allocations(void)
{
	t_memory_zone	*zone;
	unsigned int	i;

	i = 0;
	while (i < ZONE_QTY)
	{
		zone = &g_memory_zones[i];
		if (zone->first_block)
			unallocate_zone(zone);
		zone->first_block = NULL;
		zone->size = 0;
		i++;
	}
}