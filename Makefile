NAME_PS	=	push_swap
NAME_CH =	checker

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
HDRS	=	push_swap.h
LIBFT	=	-L libft -lft
RM		=	rm -f

SRCS	=	error.c \
			check.c \
			split_and_align_a.c \
			filling_stack.c \
			list_functions.c \
			operations.c \
			utils.c \
			heapsort.c \
			asipes_algorithm.c \
			small_sorts.c \
			small_sorts_b.c \
			compress.c

SRCS_PS	=	main.c

SRCS_CH	=	checker_main.c

OBJS_PS = $(patsubst %.c, %.o, $(SRCS) $(SRCS_PS))

OBJS_CH = $(patsubst %.c, %.o, $(SRCS) $(SRCS_CH))

%.o: %.c ${HDRS}
			${CC} ${CFLAGS} -c $< -o $@

all:		${NAME_PS}

$(NAME_PS):	${OBJS_PS} ${HDRS} ${LIBS}
			$(MAKE) -C libft
			${CC} ${CFLAGS} ${OBJS_PS} ${LIBS} ${LIBFT} -o ${NAME_PS}

$(NAME_CH):	${OBJS_CH} ${HDRS} ${LIBS}
			$(MAKE) -C libft
			${CC} ${CFLAGS} ${OBJS_CH} ${LIBS} ${LIBFT} -o ${NAME_CH}

clean:
			${RM} ${OBJS_PS} ${OBJS_CH}

fclean:		clean
			${RM} ${NAME_PS} ${NAME_CH}

re:			fclean all

.PHONY:		all clean lftclean fclean re
