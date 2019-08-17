# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/17 12:13:33 by maks              #+#    #+#              #
#    Updated: 2019/08/17 13:06:19 by maks             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_malloc_$(HOSTTYPE).so
LINK_NAME := libft_malloc.so

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

# Compiler
CC				:= gcc
override FLAGS	+= -Wall -Wextra -Werror -pipe

SRC_DIR := ./sources
OBJ_DIR	:= ./objs
DEP_DIR	:= ./deps
LFT_DIR := ./libft
INC_DIR := ./includes $(LFT_DIR)/includes


# Source files
SEARCH_WILCARDS := $(addsuffix /*.c,$(SRC_DIR))
SRC := $(notdir $(patsubst %.c,%.o,$(wildcard $(SEARCH_WILCARDS))))

# Object files
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

#includes
INC := $(addprefix -I, $(INC_DIR))

# Libs
LFT := $(LFT_DIR)/libft.a

.PHONY = all clean fclean re

all: prepare_dirs build_lib $(NAME) $(LINK_NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -shared $^ -o $(NAME) $(LFT)

$(LINK_NAME):
	ln -sf $(NAME) $(LINK_NAME)

prepare_dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(DEP_DIR)

build_lib:
	@make -s -C $(LFT_DIR)

VPATH := $(SRC_DIR)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(FLAGS) $(INC) -MMD -MF $(DEP_DIR)/$(notdir $(patsubst %.o,%.d,$@)) -c $< -o $@

clean:
	@make -s -C $(LFT_DIR) clean
	rm -rf $(OBJ_DIR)
	rm -rf $(DEP_DIR)

fclean: clean
	rm -f $(LFT)
	rm -f $(NAME)
	rm -f $(LINK_NAME)

re: fclean all
