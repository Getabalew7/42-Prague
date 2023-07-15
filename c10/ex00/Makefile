# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghailema <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/28 10:09:16 by ghailema          #+#    #+#              #
#    Updated: 2023/06/28 10:09:18 by ghailema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./ft_display_file.c
OBJS = ${SRCS:.c = .o}
NAME = ft_display_file
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all : ${NAME}

clean:
	${RM} ${NAME}
fclean: clean
	${RM} ${NAME}

.PHONY: all clean fclean re .c.o