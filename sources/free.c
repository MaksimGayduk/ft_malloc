/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 16:18:46 by maks              #+#    #+#             */
/*   Updated: 2019/08/30 16:00:34 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	unallocate_memory(t_memory_zone *zone, t_block_header *header)
{
	size_t size;

	size = ALIGN_TO_PAGE_SIZE(FULL_BLOCK_SIZE(header));
	if (header == zone->first_block)
		zone->first_block = header->next;
	if (header->prev)
		header->prev->next = header->next;
	if (header->next)
		header->next->prev = header->prev;
	zone->size -= size;
	munmap(header, size);
}

void		free(void *ptr)
{
	t_block_header	*header;
	int				zone_type;

	if (!valid_data_address(ptr))
		return ;
	if (pthread_mutex_lock(&g_malloc_mutex) == 0)
	{
		header = HEADER_ADDRESS(ptr);
		zone_type = header->zone_type;
		header->is_free = FT_TRUE;
		if (zone_type == LARGE)
			unallocate_memory(&g_memory_zones[zone_type], header);
		else
			defragment_block(header);
		pthread_mutex_unlock(&g_malloc_mutex);
	}
}
