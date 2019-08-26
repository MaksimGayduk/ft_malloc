/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_large.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 18:32:07 by maks              #+#    #+#             */
/*   Updated: 2019/08/26 18:48:41 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_tests.h"

void	l_basic_usage(void)
{
	char *p;
	char *x;

	p = malloc(7427);
	x = malloc(4097);
	show_alloc_mem();
	ft_putendl("Memory will be freed");
	free(p);
	free(x);
}