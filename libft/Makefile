# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alisa <alisa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/06 18:44:53 by alisa             #+#    #+#              #
#    Updated: 2021/08/10 08:48:59 by alisa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEAD = libft.h

OBJ_DIR = objects

SRC =	ft_putchar.c ft_putstr.c ft_strlen.c ft_putnbr.c ft_strcmp.c \
		ft_strncmp.c ft_swap.c ft_strnstr.c ft_strchr.c ft_strrchr.c \
		ft_strlcpy.c ft_strlcat.c ft_bzero.c ft_memset.c ft_memcpy.c \
		ft_memmove.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_isalpha.c \
		ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
		ft_tolower.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_printclst.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstmap.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c

SRC_GNL = get_next_line.c get_next_line_utils.c

OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC) $(SRC_GNL))

FLAGS = -Wall -Wextra -Werror

all:
	$(MAKE) $(NAME) -j 8

$(NAME): $(OBJ) $(HEAD)
	ar rcs $(NAME) $?

$(OBJ_DIR)/%.o: %.c
	gcc -I. $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
