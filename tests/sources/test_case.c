/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:20:40 by maks              #+#    #+#             */
/*   Updated: 2019/08/26 13:22:31 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_case.h"

void testcase(void (*test)(void), char *title)
{
	ft_putstr("~~~");
	ft_putstr(title);
	ft_putendl("~~~");
	(*test)();
	show_alloc_mem();
	reset_allocations();
	ft_putendl("~~~~~~~~~\n");
}