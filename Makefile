# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 15:10:14 by alemarti          #+#    #+#              #
#    Updated: 2021/10/21 15:58:29 by alemarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	push_swap.c			\
				lists.c


OBJS		= ${SRCS:.c=.o}

NAME		= push_swap

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Werror -Wextra
DBFLAGS		= -g3 -fsanitize=address


all:		${NAME}

bonus:		all

${NAME}:	${OBJS} ${LIBFT}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME} 


clean:
			@${RM} ${OBJS}


fclean:		clean
			@${RM} ${NAME}

re:			fclean all

test:		test.out
test.out:	${OBJS}
			${CC} ${CFLAGS} ${DBFLAGS} ${OBJS} -o test_push_swap.out 

retest:		fclean test

PHONY:		all bonus clean fclean re