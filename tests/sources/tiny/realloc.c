/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:32:27 by maks              #+#    #+#             */
/*   Updated: 2019/08/26 16:32:41 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tiny_zone_tests.h"

void realloc_page_end()
{
	char *p;
	char *x;

	p = malloc(64);
	p = realloc(p, 4000);
	x = malloc(32);
	x = realloc(x, 64);
}

void realloc_zone_end()
{
	char *p;
	char *x;

	p = malloc(64);
	p = realloc(p, 12192);
	x = malloc(32);
	x = realloc(x, 64);
}