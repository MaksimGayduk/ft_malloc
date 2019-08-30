/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 11:15:36 by maks              #+#    #+#             */
/*   Updated: 2019/08/30 16:09:18 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_block_header	*relink_blocks(
	t_block_header *start,
	t_block_header *end,
	size_t size)
{
	start->next = end->next;
	start->data_size = size;
	if (end->next)
		end->next->prev = start;
	return (start);
}

t_block_header	*extend_block(void *ptr, size_t size)
{
	size_t			extended_size;
	t_block_header	*start_block;
	t_block_header	*header;

	if (!ptr)
		return (NULL);
	start_block = HEADER_ADDRESS(ptr);
	header = start_block;
	extended_size = REAL_DATA_SIZE(start_block);
	if (size < extended_size)
	{
		start_block->data_size = size;
		return (start_block);
	}
	while ((header = header->next))
	{
		if (!(header->is_free == FT_TRUE &&
			BLOCKS_CONTINIOUS(header->prev, header)))
			return (NULL);
		extended_size += FULL_BLOCK_SIZE(header);
		if (extended_size >= size)
			return (relink_blocks(start_block, header, size));
	}
	return (NULL);
}

t_block_header	*relocate_block(void *ptr, size_t size)
{
	void			*data_addr;
	t_block_header	*header;

	header = HEADER_ADDRESS(ptr);
	data_addr = malloc(size);
	if (data_addr)
	{
		ft_memcpy(data_addr, ptr, header->data_size);
		free(ptr);
	}
	return (HEADER_ADDRESS(data_addr));
}

void			*realloc(void *ptr, size_t size)
{
	t_block_header *header;

	if (!valid_data_address(ptr) || !size || !address_space_exceded(size))
		return (NULL);
	if (pthread_mutex_lock(&g_malloc_mutex) == 0)
	{
		header = extend_block(ptr, size);
		if (header && header->zone_type != LARGE)
			fragment_block(header);
		else if (!header)
			header = relocate_block(ptr, size);
		pthread_mutex_unlock(&g_malloc_mutex);
		return (DATA_ADDRESS(header));
	}
	return (NULL);
}
