# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghailema <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/28 10:05:05 by ghailema          #+#    #+#              #
#    Updated: 2023/06/28 10:05:21 by ghailema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SCRS	= main.c tools.c atoi.c process_arg.c

OBJS	= ${SCRS:.c=.o}

NAME	= ft_tail

.c.o:
		${CC} -c $< -o ${<:.c=.o}

CC		= gcc -Wall -Wextra -Werror

all:		${OBJS}
			${CC} -o ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

.PHONY:		all clean fclean

