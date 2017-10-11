#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/18 09:48:23 by bwaegene          #+#    #+#              #
#    Updated: 2017/10/11 13:43:06 by bwaegene         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Disable implicit rules
.SUFFIXES:

# Compiler configuration
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99
## Flags for the C preprocessor
CPPFLAGS = -I$(INCLUDE) -I$(LIB_PATH)/include
## Libraries path
LDFLAGS = -L$(LIB_PATH)
## Libraries to link into the executable
LDLIBS = $(subst lib,-l, $(LIB_NAME:.a=))
NAME = minishell

# Project related variables
SRC_PATH =  src
SRC_NAME =	builtin/env.c				\
						builtin/echo.c			\
						builtin/cd.c		 		\
						builtin/exit.c			\
						builtin/true.c			\
						builtin/false.c			\
						builtin/setenv.c		\
						builtin/unsetenv.c	\
						libft.c							\
						parse.c							\
						exec.c							\
						signals.c						\
						minishell.c
OBJ_PATH = obj
OBJ_PATHS = $(sort $(dir $(OBJ)))
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
LIB_PATH = libft
LIB_NAME = libft.a
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))
INCLUDE = inc
HEADER = $(INCLUDE)/$(NAME).h
# Debug variables
DBG_CFLAGS = -g -O0 -DDEBUG
DBG_LDLIBS = $(subst lib,-l, $(DBG_LIB_NAME:.a=))
DBG_LIB_NAME = libft-debug.a
DBG_DIR = debug
DBG_NAME = $(NAME)-debug
DBG_OBJ = $(addprefix $(DBG_DIR)/, $(OBJ_NAME))
DBG_OBJ_PATHS = $(sort $(dir $(DBG_OBJ)))
DBG_LIB = $(addprefix $(LIB_PATH)/, $(LIB_PATH)-debug.a)

all: lib $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATHS):
	mkdir -p $@

$(OBJ): | $(OBJ_PATHS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

lib:
	$(MAKE) -C ./$(LIB_PATH)

# * Debug rules
debug: lib-debug $(DBG_NAME)

$(DBG_NAME): $(DBG_LIB) $(DBG_OBJ)
	$(CC) $(CFLAGS) $(DBG_CFLAGS) $(LDFLAGS) $(DBG_LDLIBS) $^ -o $@

$(DBG_OBJ_PATHS):
	mkdir -p $@

$(DBG_OBJ): | $(DBG_OBJ_PATHS)

$(DBG_DIR)/%.o: $(SRC_PATH)/%.c $(HEADER)
	$(CC) $(CFLAGS) $(DBG_CFLAGS) $(CPPFLAGS) -c $< -o $@

lib-debug:
	$(MAKE) -C ./$(LIB_PATH) debug

# * Other rules
.PHONY: norme
norme:
	-$(MAKE) -C ./$(LIB_PATH) norme
	-norminette $(SRC) $(HEADER)

.PHONY: clean
clean:
	-$(MAKE) -C ./$(LIB_PATH) clean
	-$(RM) -r $(OBJ_PATH) $(DBG_DIR)

fclean: clean
	-$(MAKE) -C ./$(LIB_PATH) fclean
	-$(RM) -r $(NAME) $(DBG_NAME) *.dSYM

re: fclean
	$(MAKE) all
