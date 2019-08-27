/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_realloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 11:09:01 by maks              #+#    #+#             */
/*   Updated: 2019/08/27 14:36:25 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_tests.h"

void	l_realloc(void)
{
	char *p;
	char *x;

	p = malloc(5000);
	ft_memset(p, 'p', 5000);
	x = malloc(7777);
	ft_memset(x, 'x', 7777);
	p = realloc(p, 9000);
	p = realloc(p, 8200);
	p = realloc(p, 10000);
	x = realloc(x, 14444);
}

// void l_realloc_zone_end()
// {
// 	char *p;
// 	char *x;

// 	p = malloc(64);
// 	p = realloc(p, 12192);
// 	x = malloc(32);
// 	x = realloc(x, 64);
// }