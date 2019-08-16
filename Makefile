NAME = libft_malloc_$(HOSTTYPE).so

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

# Compiler
CC				:= gcc
override FLAGS	+= -Wall -Wextra -Werror -pipe

# TODO: Makefile should create symbolyc link libft_malloc.so -> libft_malloc_intel-mac.so

debug:
	echo $(NAME)