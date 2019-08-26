/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:00:56 by maks              #+#    #+#             */
/*   Updated: 2019/08/26 14:14:59 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tiny_zone_tests.h"

void	basic_usage(void)
{
	char *p;
	char *x;
	char *c;

	p = malloc(32);
	x = malloc(20);
	c = malloc(11);
	show_alloc_mem();
	ft_putendl("Memory will be freed");
	free(p);
	free(x);
	free(c);
}

void fragmentation(void)
{
	char *p;
	char *x;

	p = malloc(10);
	x = malloc(10);
}

void defrag_backward()
{
	char *p;
	char *x;

	p = malloc(10);
	x = malloc(10);
	show_alloc_mem();
	ft_putendl(
		"\nMemory will be freed and allocated"
		" in the same memory blocks");
	free(p);
	free(x);
	p = malloc(15);
	x = malloc(10);
}

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