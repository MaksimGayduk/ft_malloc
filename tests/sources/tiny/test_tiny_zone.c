/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tiny_zone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:02:08 by maks              #+#    #+#             */
/*   Updated: 2019/08/28 11:43:53 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_tests.h"

void	test_tiny_zone(void)
{
	testcase(t_basic_usage, "BASIC USAGE: TINY ZONE");
	testcase(t_fragmentation, "FRAGMENTAION OF THE FIRST BLOCK IN TINY ZONE");
	testcase(t_defrag_backward, "BACKWARD DEFRAGMENTATION");
	testcase(t_realloc_page_end, "REALLOC AT THE PAGE END");
	testcase(t_realloc_zone_end, "REALLOC AT THE ZONE END");
	testcase(t_multi_thread_allocation, "ALOCATION WITH 2 THREADS");
}