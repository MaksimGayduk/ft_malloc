/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 13:07:41 by maks              #+#    #+#             */
/*   Updated: 2019/08/26 11:27:18 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	basic_usage_tiny(void)
{
	char *p;
	char *x;
	char *c;

	p = malloc(32);
	x = malloc(20);
	c = malloc(11);
	show_alloc_mem();
	free(p);
	free(x);
	free(c);
	show_alloc_mem();
}

void	test_defragment_forward()
{
	char *p;
	p = malloc(10);
	free(p);
}

int main(void)
{
	uintptr_t addr;
	char *p;
	// char *x;
	// char *c;

	basic_usage_tiny();
	test_defragment_forward();

	// for (int i = 0; i < 200; i++)
	// {
	// 	p = malloc(60);
	// }

	p = malloc(32);
	// p = realloc(p, 200);

	ft_memset(p, 93, 9);

	// free(p);

	addr = (uintptr_t)p;

	p = malloc(10);
	addr = (uintptr_t)p;
	ft_memset(p, 94, 9);

	p = malloc(230);
	addr = (uintptr_t)p;
	ft_memset(p, 94, 9);

	show_alloc_mem();

	return (0);
}