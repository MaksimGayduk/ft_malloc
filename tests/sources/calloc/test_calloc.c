/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 14:07:00 by maks              #+#    #+#             */
/*   Updated: 2019/08/28 14:41:05 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_tests.h"

void	test_calloc(void)
{
	testcase(c_basic_usage, "BASIC USAGE OF CALLOC");
	testcase(c_loop_usage, "LOOPED CALLOC USAGE");
	testcase(c_loop_leaks, "LOOPED CALLOC USAGE WITH LEAKS");
	testcase(c_multi_thread_allocation, "MULTITHREADS CALLOC USAGE");
}