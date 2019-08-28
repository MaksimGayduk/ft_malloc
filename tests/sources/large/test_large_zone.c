/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_large_zone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 18:34:12 by maks              #+#    #+#             */
/*   Updated: 2019/08/28 16:29:12 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_tests.h"

void	test_large_zone(void)
{
	testcase(l_basic_usage, "BASIC ALLOCATION IN LARGE ZONE");
	testcase(l_realloc, "BASIC REALLOCATION IN LARGE ZONE");
	testcase(l_multi_thread_allocation, "MULTI THREAD ALLOCATION LARGE ZONE");
}
