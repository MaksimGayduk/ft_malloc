/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 16:18:46 by maks              #+#    #+#             */
/*   Updated: 2019/08/23 16:33:43 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void free(void *ptr)
{
	t_block_header *block_header;

	if (!ptr)
		return;
	block_header = (t_block_header *)HEADER_ADDRESS(ptr);
	block_header->is_free = FT_TRUE;
}