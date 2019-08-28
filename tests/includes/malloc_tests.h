/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_tests.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:03:05 by maks              #+#    #+#             */
/*   Updated: 2019/08/28 16:31:16 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_TESTS_H
# define MALLOC_TESTS_H

# include "malloc.h"
# include "test_case.h"

# define THREADS_NUM			3
# define CREATE_THREAD_ERROR	-11
# define JOIN_THREAD_ERROR		-12
# define SUCCESS				0

void	test_tiny_zone(void);
void	t_basic_usage(void);
void	t_fragmentation(void);
void	t_defrag_backward(void);
void	t_realloc_page_end(void);
void	t_realloc_zone_end(void);
void	t_multi_thread_allocation(void);

void	test_large_zone(void);
void	l_basic_usage(void);
void	l_realloc(void);
void	l_multi_thread_allocation(void);

void	test_calloc(void);
void	c_basic_usage(void);
void	c_loop_usage(void);
void	c_loop_leaks(void);
void	c_multi_thread_allocation(void);

#endif
