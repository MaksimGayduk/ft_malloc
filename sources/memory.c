/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:02:47 by maks              #+#    #+#             */
/*   Updated: 2019/08/30 16:19:42 by maks             ###   ########.fr       */
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

void		reset_allocations(void)
{
	t_memory_zone	*zone;
	unsigned int	i;

	i = 0;
	while (i < ZONE_QTY)
	{
		zone = &g_memory_zones[i];
		zone->first_block = NULL;
		zone->size = 0;
		i++;
	}
}