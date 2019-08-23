/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:29:23 by maks              #+#    #+#             */
/*   Updated: 2019/08/23 15:36:59 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <sys/mman.h>
# include "libft.h"

# define ZONE_QTY 3

# define TINY_BLOCK_SIZE	64
# define SMALL_BLOCK_SIZE	512

# define TINY_BLOCK_NUMBER	120
# define SMALL_BLOCK_NUMBER	100

typedef	enum
{
	TINY,
	SMALL,
	LARGE
}	t_zone_types;

typedef struct				s_block_header
{
	t_bool					is_free;
	size_t					data_size;
	struct s_block_header	*prev;
	struct s_block_header	*next;
}							t_block_header;

# define DATA_ADDRESS(x) (((char *)(x)) + sizeof(t_block_header))
# define FULL_BLOCK_SIZE(x) (sizeof(t_block_header) + (x))
# define BLOCK_END(x) ((uintptr_t)DATA_ADDRESS(x) + (x->data_size))
# define PAGE_END(x) (((uintptr_t)(x)) | 0xFFF)

typedef struct				s_memory_zone
{
	t_block_header			*first_block;
	t_block_header			*last_block;
	int						type;
	size_t					size;
	size_t					data_size;
	size_t					block_number;
	size_t					block_number_current;
}							t_memory_zone;

extern t_memory_zone g_memory_zones[];

void	*malloc(size_t size);
void	*allocate_memory(size_t size);
void	*init_zone(t_memory_zone *zone);
void 	*append_zone(t_memory_zone *zone, size_t size);
void	show_alloc_mem(void);

#endif