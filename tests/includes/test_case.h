/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_case.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:21:11 by maks              #+#    #+#             */
/*   Updated: 2019/08/26 13:23:01 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_CASE_H
# define TEST_CASE_H

# include "malloc.h"

void testcase(void (*test)(void), char *title);

#endif