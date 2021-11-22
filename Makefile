# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 15:10:14 by alemarti          #+#    #+#              #
#    Updated: 2021/11/10 15:13:35 by alemarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	push_swap.c					\
				list_utils.c				\
				push_swap_interpreter.c		\
				small_stack_utils.c			\
				big_stack_utils.c


OBJS		= ${SRCS:.c=.o}

LIBFT		= ./libft/libft.a

NAME		= push_swap

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Werror -Wextra
DBFLAGS		= -g3 -fsanitize=address


all:		${NAME}

bonus:		all

${NAME}:	${OBJS} ${LIBFT}
			${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME} 

${LIBFT}:
			make -C ./libft/ libft.a

clean:
			@${RM} ${OBJS}
			@make -C ./libft/ clean


fclean:		clean
			@${RM} ${NAME}

re:			fclean all

test:		test.out
test.out:	${OBJS}
			${CC} ${CFLAGS} ${DBFLAGS} ${OBJS} ${LIBFT} -o test.out 

retest:		fclean test

PHONY:		all bonus clean fclean re