# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 23:27:59 by rgallien          #+#    #+#              #
#    Updated: 2024/04/23 13:37:30 by rgallien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
LIBNAME = libft.a

SRC_DIR	= src
OBJ_DIR = obj

SRCS	=	pipex.c \

SRCS	:= $(SRCS:%=$(SRC_DIR)/%)
OBJS	=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -I include -I libft/include -I/usr/include

RM			= rm -f
RMDIR		= rmdir
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(@D)

all:	$(NAME)

$(NAME): $(OBJS)
	@if [ ! -e "$(LIBNAME)" ]; then \
		make -C libft ; \
		mv libft/libft.a . ;\
	fi
	$(CC) $(OBJS) $(LIBNAME) -o $(NAME)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
		$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		$(RM) $(OBJS); \
		$(RMDIR) $(OBJ_DIR); \
		make clean -C libft ; \
	fi


fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBNAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean fclean re
.SILENT:
