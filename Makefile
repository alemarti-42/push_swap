# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 15:10:14 by alemarti          #+#    #+#              #
#    Updated: 2022/02/21 19:37:42 by alemarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	push_swap.c					\
				small_stack_utils.c			\
				big_stack_utils.c			\
				more_utils.c				\
				big_sorting.c


OBJS		= ${SRCS:.c=.o}

PSLIB		= ./pslib/pslib.a
LIBFT		= ./pslib/libft/libft.a

NAME		= push_swap

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Werror -Wextra
DBFLAGS		= -g3 -fsanitize=address


all:		${NAME}

bonus:		all

${NAME}:	${OBJS} ${PSLIB}
			${CC} ${CFLAGS} ${OBJS} ${PSLIB} ${LIBFT} -o ${NAME} 

${PSLIB}:
			make -C ./pslib/ all

clean:
			@${RM} ${OBJS}
			@make -C ./pslib/ clean


fclean:		clean
			@${RM} ${NAME}
			@make -C ./pslib/ fclean

re:			fclean all

test:		test.out
test.out:	${OBJS} ${PSLIB}
			${CC} ${CFLAGS} ${DBFLAGS} ${OBJS} ${PSLIB} ${LIBFT} -o test.out 

retest:		fclean test

PHONY:		all bonus clean fclean re