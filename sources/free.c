/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 16:18:46 by maks              #+#    #+#             */
/*   Updated: 2019/08/26 10:46:23 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	free(void *ptr)
{
	t_block_header *block_header;

	if (!ptr)
		return;
	if (pthread_mutex_lock(&g_malloc_mutex) == 0)
	{
		block_header = HEADER_ADDRESS(ptr);
		block_header->is_free = FT_TRUE;
		defragment_block(block_header);
		pthread_mutex_unlock(&g_malloc_mutex);
	}
}