/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 13:07:41 by maks              #+#    #+#             */
/*   Updated: 2019/08/28 12:55:45 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_tests.h"

int main(void)
{
	char *c __unused = malloc(3200);
	char *x __unused = malloc(10000);
	char *z __unused = malloc(14000);

	char *p __unused = malloc(32);
	show_alloc_mem();
	reset_allocations();
	show_alloc_mem();

	// munmap(HEADER_ADDRESS(c), 5000);

	// ft_memset(c, 'c', 42);
	// p = malloc(11);
	test_tiny_zone();
	test_large_zone();

	return (0);
}