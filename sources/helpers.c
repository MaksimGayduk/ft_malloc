/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 16:14:10 by maks              #+#    #+#             */
/*   Updated: 2019/08/30 16:08:14 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_bool	valid_data_address(void *ptr)
{
	t_counter		i;
	t_block_header	*block;

	if (!ptr)
		return (FT_FALSE);
	i = 0;
	while(i < ZONE_QTY)
	{
		block = g_memory_zones[i].first_block;
		while (block)
		{
			if (block == HEADER_ADDRESS(ptr))
				return (FT_TRUE);
			block = block->next;
		}
		i++;
	}
	return (FT_FALSE);
}

size_t		get_total_allocated_size(void)
{
	unsigned int	i;
	size_t			total_size;

	total_size = 0;
	i = 0;
	while (i < ZONE_QTY)
	{
		total_size = g_memory_zones[i].size;
		i++;
	}
	return (total_size);
}

t_bool		address_space_exceded(size_t size)
{
	struct rlimit	rlimit;

	getrlimit(RLIMIT_AS, &rlimit);
	return (size + get_total_allocated_size() >= rlimit.rlim_cur);
}
