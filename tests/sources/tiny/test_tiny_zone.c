/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:02:08 by maks              #+#    #+#             */
/*   Updated: 2019/08/26 13:06:36 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tiny_zone_tests.h"

void	test_tiny_zone(void)
{
	testcase(basic_usage, "BASIC USAGE: TINY ZONE");
	testcase(fragmentation, "FRAGMENTAION OF THE FIRST BLOCK IN TINY ZONE");
	testcase(defragmentation_backward, "BACKWARD DEFRAGMENTATION");
}