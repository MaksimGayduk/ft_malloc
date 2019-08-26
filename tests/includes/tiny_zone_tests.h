/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_zone_tests.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:03:57 by maks              #+#    #+#             */
/*   Updated: 2019/08/26 13:28:21 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TINY_ZONE_TESTS_H
# define TINY_ZONE_TESTS_H

# include "malloc.h"
# include "test_case.h"

void	basic_usage(void);
void	fragmentation(void);
void 	defragmentation_backward();

#endif