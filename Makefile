# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taelee <taelee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/02 21:59:40 by taelee            #+#    #+#              #
#    Updated: 2020/04/02 22:15:50 by taelee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = factorization
SRC = factorization.c
OBJ = factorization.o
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all : ${NAME}

${NAME} :  ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

${OBJ} : ${SRC}
	${CC} ${CFLAGS} -c ${SRC} -o ${OBJ}

clean :
	${RM} ${OBJ}

fclean :
	${RM} ${NAME}

re :	fclean all

.PHONY : all clean fclean re
