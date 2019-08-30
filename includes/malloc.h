/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:29:23 by maks              #+#    #+#             */
/*   Updated: 2019/08/30 13:34:46 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <sys/mman.h>
# include <pthread.h>
# include <sys/resource.h>
# include "libft.h"

# define ZONE_QTY 3

# define TINY_BLOCK_SIZE	64
# define SMALL_BLOCK_SIZE	1024

# define TINY_BLOCK_NUMBER	120
# define SMALL_BLOCK_NUMBER	160

extern pthread_mutex_t		g_malloc_mutex;

typedef	enum
{
	TINY,
	SMALL,
	LARGE
}	t_zone_types;

typedef struct				s_block_header
{
	t_bool					is_free;
	char					zone_type;
	size_t					data_size;
	struct s_block_header	*prev;
	struct s_block_header	*next;
}							t_block_header;

# define ALIGN_TO_PAGE_SIZE(x) (FT_ALIGN_TO(x, getpagesize()))

/*
** Converts address int pointer to scalar value
*/
# define TO_SCALAR(x) ((uintptr_t)(x))
# define HEADER_SIZE (sizeof(t_block_header))

/*
** Header address of specified data memory
*/
# define __HEADER_ADDR(x) ((t_block_header *)(((char *)(x)) - HEADER_SIZE))
# define HEADER_ADDRESS(x) ((x) ? (__HEADER_ADDR(x)) : (NULL))

/*
** Data address of specified block header
*/
# define DATA_ADDRESS(x) ((x) ? ((char *)(x)) + HEADER_SIZE : (NULL))
# define DATA_END_ADDRESS(x) (DATA_ADDRESS(x) + (x->data_size))
# define FULL_BLOCK_SIZE(x) ((HEADER_SIZE) + (x->data_size))
# define BLOCK_END(x) (TO_SCALAR(DATA_ADDRESS(x)) + (x->data_size))

/*
** Page part of specified address
*/
# define PAGE(x) ((TO_SCALAR(x) >> 12) << 12)

/*
** Page limit address. Address of the first byte of the next page
*/
# define PAGE_LIMIT(x) ((TO_SCALAR(x) | 0xFFF) + 1)

/*
** Offest ftom start of one block to start of another
*/
# define BLOCKS_OFFSET(x, y) ((TO_SCALAR(y) - TO_SCALAR(x)))

# define _PBE(x) (PAGE_LIMIT(BLOCK_END(x) - 1) - TO_SCALAR(x))

/*
** Block has next element and it on the same or next page
*/
# define NOT_ALONE(x) (x->next && BLOCKS_CONTINIOUS(x, x->next))

/*
** Size of block with gap to next the block
*/
# define REAL_BLOCK_SIZE(x) (NOT_ALONE(x) ? BLOCKS_OFFSET(x, x->next) : _PBE(x))

/*
** Size of data section with gap to the next block
*/
# define REAL_DATA_SIZE(x) (REAL_BLOCK_SIZE(x) - HEADER_SIZE)

/*
** Two blocks are continious if the last byte of firts block is
** on the same or nearby page with first byte of second block
*/
# define BLOCKS_CONTINIOUS(x, y) (((PAGE(y) - PAGE(BLOCK_END(x))) >> 12) <= 1)
# define GET_ZONE_TYPE(x) ((x > TINY_BLOCK_SIZE) + (x > SMALL_BLOCK_SIZE))
# define GET_BLOCK_ZONE(x) (g_memory_zones[((int)(x->zone_type))])

typedef struct				s_memory_zone
{
	t_block_header			*first_block;
	int						type;
	size_t					size;
	size_t					data_size;
	size_t					block_number;
}							t_memory_zone;

extern t_memory_zone g_memory_zones[];

void						*malloc(size_t size);
void						*realloc(void *ptr, size_t size);
void						free(void *ptr);
void						show_alloc_mem(void);

void						*allocate_memory(size_t size);
void						reset_allocations(void);
void						*init_zone(t_memory_zone *zone);
void						append_zone(t_memory_zone *zone);
void						fragment_block(t_block_header *header);
void						defragment_block(t_block_header *header);
void						init_block_header(
								t_block_header *block_header,
								char zone,
								size_t data_size,
								t_block_header *prev);
size_t						get_total_allocated_size(void);

#endif
