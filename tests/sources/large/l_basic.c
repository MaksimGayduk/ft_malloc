/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_basic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 18:32:07 by maks              #+#    #+#             */
/*   Updated: 2019/08/27 11:52:17 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_tests.h"

void	l_basic_usage(void)
{
	char *p;
	char *x;
	char *c;

	p = malloc(7427);
	ft_memset(p, 'p', 7427);
	x = malloc(5555);
	ft_memset(x, 'x', 5555);
	c = malloc(128753);
	ft_memset(c, 'c', 128753);
	show_alloc_mem();
	ft_putendl("Memory will be freed");
	free(x);
	x = malloc(5555);
	free(c);
	free(p);
	free(x);
}