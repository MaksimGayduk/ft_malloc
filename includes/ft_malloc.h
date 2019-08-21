/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:29:23 by maks              #+#    #+#             */
/*   Updated: 2019/08/21 18:06:54 by maks             ###   ########.fr       */
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
	int						x;
	size_t					block_size;
	struct s_block_header	*prev;
	struct s_block_header	*next;
}							t_block_header;

typedef struct				s_memory_zone
{
	t_block_header			*first_header;
	int						type;
	size_t					size;
	size_t					block_size;
	size_t					block_number;
}							t_memory_zone;




void	*malloc(size_t size);
void	*allocate_memory(size_t size);
void 	*init_zone(t_memory_zone *zone);

#endif