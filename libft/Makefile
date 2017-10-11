#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/18 09:48:23 by bwaegene          #+#    #+#              #
#    Updated: 2017/10/11 13:39:51 by bwaegene         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Disable implicit rules
.SUFFIXES:

# Compiler configuration
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99
## Flags for the C preprocessor
CPPFLAGS = -I$(INCLUDE)
NAME = libft.a

# Project related variables
SRC_PATH =  src
SRC_NAME =	ctype/ft_isalnum.c					\
						ctype/ft_isalpha.c					\
						ctype/ft_isascii.c					\
						ctype/ft_isdigit.c					\
						ctype/ft_islower.c					\
						ctype/ft_isprint.c					\
						ctype/ft_isspace.c					\
						ctype/ft_isupper.c					\
						ctype/ft_itoa.c							\
						ctype/ft_tolower.c					\
						ctype/ft_toupper.c					\
						ft/get_next_line.c					\
						list/ft_lstadd.c						\
						list/ft_lstdel.c						\
						list/ft_lstdelone.c					\
						list/ft_lstiter.c						\
						list/ft_lstmap.c						\
						list/ft_lstnew.c						\
						malloc/ft_memalloc.c				\
						math/ft_nbrlen.c						\
						math/ft_range.c							\
						math/ft_sqrt.c							\
						misc/ft_basename.c					\
						misc/ft_getopt.c						\
						misc/ft_pathjoin.c					\
						misc/ft_isdir.c							\
						misc/ft_isregfile.c					\
						stdio/ft_putchar.c					\
						stdio/ft_putchar_fd.c				\
						stdio/ft_putendl.c					\
						stdio/ft_putendl_fd.c				\
						stdio/ft_putnbr.c						\
						stdio/ft_putnbr_fd.c				\
						stdio/ft_putstr.c						\
						stdio/ft_putstr_fd.c				\
						stdlib/ft_atoi.c						\
						stdlib/ft_abs.c							\
						stdlib/ft_environ.c					\
						stdlib/ft_getenv.c					\
						stdlib/ft_putenv.c					\
						stdlib/ft_setenv.c					\
						stdlib/ft_unsetenv.c				\
						stdlib/ft_realpath.c				\
						string/ft_bzero.c						\
						string/ft_memchr.c					\
						string/ft_memcmp.c					\
						string/ft_memcpy.c					\
						string/ft_memdel.c					\
						string/ft_memmove.c					\
						string/ft_memset.c					\
						string/ft_reverse.c					\
						string/ft_swap.c						\
						string/ft_strcat.c					\
						string/ft_strchr.c					\
						string/ft_strclr.c					\
						string/ft_strcmp.c					\
						string/ft_stpcpy.c					\
						string/ft_strcpy.c					\
						string/ft_strdel.c					\
						string/ft_strdup.c					\
						string/ft_strequ.c					\
						string/ft_striter.c					\
						string/ft_striteri.c				\
						string/ft_strjoin.c					\
						string/ft_strjoinf.c				\
						string/ft_strlcat.c					\
						string/ft_strlen.c					\
						string/ft_strmap.c					\
						string/ft_strmapi.c					\
						string/ft_strncat.c					\
						string/ft_strncmp.c					\
						string/ft_strncpy.c					\
						string/ft_strnequ.c					\
						string/ft_strnew.c					\
						string/ft_strnstr.c					\
						string/ft_strrchr.c					\
						string/ft_strsplit.c				\
						string/ft_strstr.c					\
						string/ft_strsub.c					\
						string/ft_strswap.c					\
						string/ft_strtrim.c					\
						search/ft_lfind.c
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ_PATH =  obj
OBJ_PATHS = $(sort $(dir $(OBJ)))
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INCLUDE = include
HEADER = $(INCLUDE)/$(NAME:.a=.h)
# Debug variables
DBG_CFLAGS = -g -O0 -DDEBUG
DBG_DIR = debug
DBG_NAME = libft-debug.a
DBG_OBJ = $(addprefix $(DBG_DIR)/, $(OBJ_NAME))
DBG_OBJ_PATHS = $(sort $(dir $(DBG_OBJ)))

DEBUG ?= 0
ifeq ($(DEBUG), 1)
    CFLAGS += -g
endif

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $?
	ranlib $@

$(OBJ_PATHS):
	mkdir -p $@

$(OBJ): | $(OBJ_PATHS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# * Debug rules
debug: $(DBG_NAME)

$(DBG_NAME): $(DBG_OBJ)
	ar rc $@ $?
	ranlib $@

$(DBG_OBJ_PATHS):
	mkdir -p $@

$(DBG_OBJ): | $(DBG_OBJ_PATHS)

$(DBG_DIR)/%.o: $(SRC_PATH)/%.c $(HEADER)
	$(CC) $(CFLAGS) $(DBG_CFLAGS) $(CPPFLAGS) -c $< -o $@

# * Other rules
.PHONY: test
test:
	$(MAKE) -C test test

.PHONY: norme
norme:
	-norminette $(SRC) $(HEADER)

.PHONY: clean
clean:
	-$(MAKE) -C lib/libunit clean
	-$(MAKE) -C test clean
	-$(RM) -r $(OBJ_PATH) $(DBG_DIR)

fclean: clean
	-$(MAKE) -C lib/libunit fclean
	-$(MAKE) -C test fclean
	-$(RM) -r $(NAME) $(DBG_NAME) *.dSYM

re: fclean
	-$(MAKE) all
