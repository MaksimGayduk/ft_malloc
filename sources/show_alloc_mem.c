/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:41:20 by maks              #+#    #+#             */
/*   Updated: 2019/08/28 15:20:15 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

char *g_zone_labels[] = {
	"TINY", "SMALL", "LARGE"
};

static void		print_zone_info(unsigned int zone_number)
{
	uintptr_t zone_start;

	zone_start = (uintptr_t)g_memory_zones[zone_number].first_block;
	ft_putstr(g_zone_labels[zone_number]);
	ft_putstr(" : ");
	zone_start ?
		ft_putnbr16(zone_start, FT_FALSE, FT_TRUE) :
		ft_putstr("not allocated");
	ft_putchar('\n');
}

static size_t	print_alloc_blocks(t_block_header *head)
{
	uintptr_t	block_start;
	size_t		allocated_size;

	allocated_size = 0;
	while (head)
	{
		if (!head->is_free)
		{
			block_start = (uintptr_t)head + sizeof(t_block_header);
			ft_putnbr16(block_start, FT_FALSE, FT_TRUE);
			ft_putstr(" - ");
			ft_putnbr16(block_start + head->data_size, FT_FALSE, FT_TRUE);
			ft_putstr(" : ");
			ft_putnbr(head->data_size);
			ft_putstr(" bytes\n");
			allocated_size += head->data_size;
		}
		head = head->next;
	}
	return (allocated_size);
}

void			show_alloc_mem(void)
{
	unsigned int	i;
	size_t			total_size;

	total_size = 0;
	i = 0;
	while (i < ZONE_QTY)
	{
		print_zone_info(i);
		total_size += print_alloc_blocks(g_memory_zones[i].first_block);
		ft_putchar('\n');
		i++;
	}
	ft_putstr("Total : ");
	ft_putnbr(total_size);
	ft_putstr(" bytes\n");
}
