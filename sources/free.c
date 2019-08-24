/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 16:18:46 by maks              #+#    #+#             */
/*   Updated: 2019/08/24 16:00:00 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	__free(void *ptr)
{
	t_block_header *block_header;

	block_header = HEADER_ADDRESS(ptr);
	block_header->is_free = FT_TRUE;
}

void	free(void *ptr)
{

	if (!ptr)
		return;
	if (pthread_mutex_lock(&g_malloc_mutex) == 0)
	{
		__free(ptr);
		pthread_mutex_unlock(&g_malloc_mutex);
	}
}