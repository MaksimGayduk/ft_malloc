/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:32:27 by maks              #+#    #+#             */
/*   Updated: 2019/08/28 16:28:12 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_tests.h"

void	t_realloc_page_end(void)
{
	char *p;
	char *x;

	p = malloc(64);
	p = realloc(p, 4000);
	x = malloc(32);
	x = realloc(x, 64);
}

void	t_realloc_zone_end(void)
{
	char *p;
	char *x;

	p = malloc(64);
	p = realloc(p, 12192);
	x = malloc(32);
	x = realloc(x, 64);
}
