/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 16:14:10 by maks              #+#    #+#             */
/*   Updated: 2019/08/26 13:10:17 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void *allocate_memory(size_t size)
{
	void *mem;
	mem = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (mem == MAP_FAILED)
		return NULL;
	return (mem);
}

void reset_allocations(void)
{
	unsigned int i;
	t_block_header *first_block;
	size_t total_size;

	first_block = g_memory_zones[0].first_block;
	i = 0;
	total_size = 0;
	while(i < ZONE_QTY)
	{
		total_size += g_memory_zones[i].size;
		g_memory_zones[i].first_block = NULL;
		g_memory_zones[i].last_block = NULL;
		g_memory_zones[i].size = 0;
		i++;
	}

	total_size = ALIGN_TO_PAGE_SIZE(total_size);
	munmap(first_block, total_size);
}