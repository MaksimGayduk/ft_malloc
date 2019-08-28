/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 13:46:36 by maks              #+#    #+#             */
/*   Updated: 2019/08/28 14:36:17 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*calloc(size_t num, size_t size)
{
	void	*ptr;
	size_t	allocation_size;

	if (pthread_mutex_lock(&g_malloc_mutex) == 0)
	{
		allocation_size = num * size;
		ptr = malloc(allocation_size);
		if (ptr)
			ft_bzero(ptr, allocation_size);
		pthread_mutex_unlock(&g_malloc_mutex);
		return (ptr);
	}
	return (NULL);
}