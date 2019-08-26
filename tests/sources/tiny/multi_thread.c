/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:45:29 by maks              #+#    #+#             */
/*   Updated: 2019/08/26 18:47:11 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_tests.h"

#define THREADS_NUM 2
#define CREATE_THREAD_ERROR	-11
#define JOIN_THREAD_ERROR	-12
#define SUCCESS				0

static void	*thread_malloc(void *args)
{
	char *p;

	args = NULL;
	p = malloc(42);
	p = realloc(p, 142);
	free(p);
	p = malloc(24);
	return (SUCCESS);
}

void	t_multi_thread_allocation(void)
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