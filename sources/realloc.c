/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 11:15:36 by maks              #+#    #+#             */
/*   Updated: 2019/08/26 11:08:58 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_block_header	*extend_block(void *ptr, size_t size)
{
	size_t			extended_size;
	t_block_header	*start_block;
	t_block_header	*header;

	start_block = HEADER_ADDRESS(ptr);
	header = start_block;
	if (!header)
		return (NULL);
	extended_size = header->data_size;
	while ((header = header->next))
	{
		if (!(header->is_free == FT_TRUE &&
			BLOCKS_CONTINIOUS(header->prev, header)))
			return (NULL);
		extended_size += FULL_BLOCK_SIZE(header);
		if (extended_size >= size)
		{
			start_block->next = header->next;
			start_block->data_size = size;
			if (header->next)
				header->next->prev = start_block;
			return (start_block);
		}
	}
	return (NULL);
}

t_block_header	*relocate_block(void *ptr, size_t size)
{
	void *data_addr;

	data_addr = malloc(size);
	if (data_addr)
	{
		ft_memcpy(data_addr, ptr, size);
		free(ptr);
	}
	return (HEADER_ADDRESS(data_addr));
}

void			*realloc(void *ptr, size_t size)
{
	t_block_header *header;

	if (!size)
		return (NULL);
	if (pthread_mutex_lock(&g_malloc_mutex) == 0)
	{
		header = extend_block(ptr, size);
		if (header)
			fragment_block(header);
		else
			header = relocate_block(ptr, size);
		pthread_mutex_unlock(&g_malloc_mutex);
		return (DATA_ADDRESS(header));
	}
	return (NULL);
}
