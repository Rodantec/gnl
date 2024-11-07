# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 12:42:17 by rodantec          #+#    #+#              #
#    Updated: 2024/11/07 11:24:29 by rodantec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS    =

OBJS    = ${SRCS:.c=.o}
INCS    = includes
NAME    = libftprintf.a
LIBC    = ar rc
LIBR    = ranlib
CC        = gcc
RM        = rm -f
CFLAGS    = -Wall -Wextra -Werror
GNLFLAGS = -D BUFFER_SIZE=n

.c.o:
		${CC} ${CFLAGS} ${GNLFLAGS} -I ./ -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

bonus: ${OBJS} 
	${LIBC} ${NAME} ${OBJS} 

clean:
		${RM} ${OBJS} 

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY:	all bonus clean fclean re
