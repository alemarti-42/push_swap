# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 15:10:14 by alemarti          #+#    #+#              #
#    Updated: 2022/02/23 16:44:24 by alemarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	push_swap.c					\
				small_stack_utils.c			\
				big_stack_utils.c			\
				big_sorting.c				\
				more_utils.c


OBJS		= ${SRCS:.c=.o}

PSLIB		= ./pslib/pslib.a
LIBFT		= ./libft/libft.a

NAME		= push_swap

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Werror -Wextra


all:		${NAME}

${NAME}:	${OBJS} ${LIBFT} ${PSLIB} 
			${CC} ${CFLAGS} ${OBJS} ${PSLIB} ${LIBFT} -o ${NAME} 

${PSLIB}:
			make -C ./pslib/ all

${LIBFT}:
			make -C ./libft/ all

clean:
			@${RM} ${OBJS}
			@make -C ./pslib/ fclean
			@make -C ./libft/ fclean


fclean:		clean
			@${RM} ${NAME}

re:			fclean all

PHONY:		all clean fclean re