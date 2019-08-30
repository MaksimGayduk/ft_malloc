/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 13:07:41 by maks              #+#    #+#             */
/*   Updated: 2019/08/30 13:46:04 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "malloc_tests.h"

#include <stdlib.h>

int	main(void)
{
	// test_tiny_zone();
	// test_large_zone();
	// test_calloc();
	int i;
	char *addr;

	i = 0;
	while (i < 1024)
	{
		addr = (char*)malloc(1024);
		addr[0] = 42;
		// free(addr);
		i++;
	}
	return (0);
}
