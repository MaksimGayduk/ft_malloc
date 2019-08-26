/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tiny_zone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:02:08 by maks              #+#    #+#             */
/*   Updated: 2019/08/26 14:14:12 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tiny_zone_tests.h"

void	test_tiny_zone(void)
{
	testcase(basic_usage, "BASIC USAGE: TINY ZONE");
	testcase(fragmentation, "FRAGMENTAION OF THE FIRST BLOCK IN TINY ZONE");
	testcase(defrag_backward, "BACKWARD DEFRAGMENTATION");
	testcase(realloc_page_end, "REALLOC AT THE PAGE END");
	testcase(realloc_zone_end, "REALLOC AT THE ZONE END");

}