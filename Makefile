NAME	=	push_swap

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g
HDRS	=	push_swap.h
LIBFT	=	-L libft -lft
OBJ_DIR	=	objects
RM		=	rm -f

SRCS	=	main.c \
			error.c \
			check.c \
			list_functions.c \
			operations.c \
			utils.c \
			test_alg.c
			
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

$(OBJ_DIR)/%.o: %.c
			${CC} ${CFLAGS} -c $< -o $@

all:		${NAME}

$(NAME):	${OBJS} ${HDRS} ${LIBS}
			$(MAKE) -C libft
			${CC} ${CFLAGS} ${OBJS} ${LIBS} ${LIBFT} -o ${NAME}

debug:		${OBJS} ${HDRS} ${LIBS}
			$(MAKE) -C libft
			${CC} -g ${CFLAGS} ${OBJS} ${LIBS} ${LIBFT} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all build clean lftclean fclean re
