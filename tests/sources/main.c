/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 13:07:41 by maks              #+#    #+#             */
/*   Updated: 2019/08/22 15:46:28 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

int main(void)
{
	uintptr_t addr;
	char *p;

	for (int i = 0; i < 200; i++)
	{
		p = malloc(60);
	}

	p = malloc(60);
	ft_memset(p, 93, 9);

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