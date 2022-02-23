# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 16:16:18 by alemarti          #+#    #+#              #
#    Updated: 2022/02/23 17:09:37 by alemarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	list_utils.c			\
			list_exec.c				\
			list_print.c			\
			list_free.c				\
			ps_push.c				\
			ps_swap.c				\
			ps_rotate.c				\
			ps_reverse.c			\
			push_swap_interpreter.c	




OBJS	= ${SRCS:.c=.o}

LIBFT	= ../libft/libft.a

NAME	= pslib.a
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra

all:		${NAME}
	
${NAME}:	${OBJS} ${LIBFT}
			ar rc	${NAME} ${OBJS} ${LIBFT}

clean:	
			@${RM} ${OBJS}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

