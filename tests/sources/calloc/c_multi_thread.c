/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_multi_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 15:07:47 by maks              #+#    #+#             */
/*   Updated: 2019/08/28 14:41:31 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_tests.h"

static void	*thread_malloc(void *args)
{
	char *p;

	args = NULL;
	p = calloc(2, 10000);
	return (SUCCESS);
}

void		c_multi_thread_allocation(void)
{
	pthread_t threads[THREADS_NUM];
    unsigned int i;

	i = 0;
	while (i < THREADS_NUM)
	{
		if (pthread_create(&(threads[i]), NULL, thread_malloc, NULL) != SUCCESS)
		{
			ft_putendl("Thread creation error");
			exit(CREATE_THREAD_ERROR);
		}
		i++;
	}

	i = 0;
	while (i < THREADS_NUM)
	{
		if (pthread_join(threads[i], NULL) != SUCCESS)
		{
			ft_putendl("Thread join error");
			exit(JOIN_THREAD_ERROR);
		}
		i++;
	}
}
