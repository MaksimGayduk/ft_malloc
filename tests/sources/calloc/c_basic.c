/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_basic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 14:04:47 by maks              #+#    #+#             */
/*   Updated: 2019/08/28 16:22:41 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_tests.h"

void	c_basic_usage(void)
{
	char *p;
	char *x;

	p = calloc(100, sizeof(short));
	ft_memset(p, 'p', 100 * sizeof(short));
	x = calloc(42, sizeof(int));
	ft_memset(x, 'x', 42 * sizeof(int));
	show_alloc_mem();
	ft_putendl("Memory will be freed");
	free(x);
	free(p);
}

void	c_loop_usage(void)
{
	unsigned int	i;
	char			*p;

	i = 0;
	while (i < 42000)
	{
		p = calloc(100, sizeof(short));
		ft_memset(p, 'p', 100 * sizeof(short));
		free(p);
		i++;
	}
}

void	c_loop_leaks(void)
{
	unsigned int	i;
	char			*p;

	i = 0;
	while (i < 21)
	{
		p = calloc(100, sizeof(short));
		if (p)
			ft_memset(p, 'p', 100 * sizeof(short));
		i++;
	}
}
