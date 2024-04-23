# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 16:19:48 by lvicino           #+#    #+#              #
#    Updated: 2024/02/06 17:37:07 by rgallien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC_DIR    	= src
OBJ_DIR		= obj

SRCS	= libc/ft_isalpha.c \
	  libc/ft_isdigit.c \
	  libc/ft_isalnum.c \
	  libc/ft_isascii.c \
	  libc/ft_isprint.c \
	  libc/ft_strlen.c \
	  libc/ft_memset.c \
	  libc/ft_bzero.c \
	  libc/ft_memcpy.c \
	  libc/ft_memmove.c \
	  libc/ft_strlcpy.c \
	  libc/ft_strlcat.c \
	  libc/ft_toupper.c \
	  libc/ft_tolower.c \
	  libc/ft_strchr.c \
	  libc/ft_strrchr.c \
	  libc/ft_strncmp.c \
	  libc/ft_memchr.c \
	  libc/ft_memcmp.c \
	  libc/ft_strnstr.c \
	  libc/ft_atoi.c \
	  libc/ft_calloc.c \
	  libc/ft_strdup.c \
	  libc/ft_substr.c \
	  libc/ft_strjoin.c \
	  libc/ft_strtrim.c \
	  libc/ft_putchar_fd.c \
	  libc/ft_putstr_fd.c \
	  libc/ft_putendl_fd.c \
	  libc/ft_putnbr_fd.c \
	  libc/ft_split.c \
	  libc/ft_itoa.c \
	  libc/ft_strmapi.c \
	  libc/ft_striteri.c \
	  gnl/get_next_line_utils.c \
	  gnl/get_next_line.c \
	  printf/ft_print_char.c \
	  printf/ft_print_hex.c \
	  printf/ft_print_nbr.c \
	  printf/ft_print_str.c \
	  printf/ft_print_unbr.c \
	  printf/ft_printf.c

BONUS = libc/ft_lstnew_bonus.c \
		libc/ft_lstadd_front_bonus.c \
		libc/ft_lstsize_bonus.c \
		libc/ft_lstlast_bonus.c \
		libc/ft_lstadd_back_bonus.c \
		libc/ft_lstdelone_bonus.c \
		libc/ft_lstclear_bonus.c \
		libc/ft_lstiter_bonus.c \
		libc/ft_lstmap_bonus.c

SRCS	:= $(SRCS:%=$(SRC_DIR)/%)
OBJS	= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC			= clang
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -I include

BONUS_OBJ = $(BONUS:.c=.o)

RM			= rm -f
RMDIR		= rmdir
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(@D)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	$(info 	CREATED $(NAME))

bonus : $(BONUS_OBJ)
	ar rc $(NAME) $(BONUS_OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		$(RM) $(OBJS); \
		rm -rf  $(OBJ_DIR); \
	fi

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean fclean re
.SILENT: