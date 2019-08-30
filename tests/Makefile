# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/17 14:35:36 by maks              #+#    #+#              #
#    Updated: 2019/08/30 14:03:18 by maks             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_malloc_test

# Compiler
CC		:= gcc
FLAGS	:= -Wall -Wextra -Werror -pipe -O0 -g

SRC_DIR := ./sources
OBJ_DIR	:= ./objs
DEP_DIR	:= ./deps
LFT_DIR := ./libft
INC_DIR := ./includes ../includes ../libft/includes

ZONES := tiny large calloc
ZONES_DIRS := $(addprefix $(SRC_DIR)/, $(ZONES))
SRC_DIRS := $(SRC_DIR) $(ZONES_DIRS)

# Source files
SEARCH_WILCARDS := $(addsuffix /*.c,$(SRC_DIRS))
SRC := $(notdir $(wildcard $(SEARCH_WILCARDS)))

# Object files
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

#includes
INC := $(addprefix -I, $(INC_DIR))

# Libs
FT_MALLOC := ../libft_malloc.so

.PHONY = all clean fclean re

all: prepare_dirs build_ft_malloc $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(FT_MALLOC) $(INC) $^ -o $(NAME) ../libft/libft.a

dl: prepare_dirs build_ft_malloc empty

empty: main.c
	$(CC) $(FLAGS) $(INC) $^ -o $(NAME) ../libft/libft.a

prepare_dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(DEP_DIR)

build_ft_malloc:
	@make FLAGS="-O0 -g" -C ../

VPATH := $(SRC_DIRS)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(FLAGS) $(INC) -MMD -MF $(DEP_DIR)/$(notdir $(patsubst %.o,%.d,$@)) -c $< -o $@

include $(wildcard $(DEP_DIR)/*.d)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(DEP_DIR)

fclean: clean
	@make fclean -C ../
	rm -f $(NAME)

re: fclean all

debug:
	@echo $(SEARCH_WILCARDS)