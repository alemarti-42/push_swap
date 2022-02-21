SRCS	=	list_utils.c			\
			list_exec.c				\
			list_print.c			\
			ps_push.c				\
			ps_swap.c				\
			ps_rotate.c				\
			ps_reverse.c			\
			push_swap_interpreter.c




OBJS	= ${SRCS:.c=.o}

LIBFT		= ./libft/libft.a

NAME	= pslib.a
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra

all:		${NAME}
	
${NAME}:	${OBJS} ${LIBFT}
			ar rc	${NAME} ${OBJS} ${LIBFT}

${LIBFT}:
			make -C ./libft/ all

clean:	
			@${RM} ${OBJS}
			@make -C ./libft/ clean

fclean:		clean
			@${RM} ${NAME}
			@make -C ./libft/ fclean

re:			fclean all

