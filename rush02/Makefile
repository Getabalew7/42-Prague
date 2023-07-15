SCRS	= srcs/main.c srcs/ft_atoi.c srcs/ft_convert_number.c  srcs/ft_count_dictionary.c srcs/ft_load_dictionary.c srcs/ft_print_str.c srcs/ft_split.c

OBJS	= ${SCRS:.c=.o}

CC		= gcc -Wall -Wextra -Werror -I includes

NAME	= rush-02

.c.o:	
	@${CC} -c $< -o ${<:.c=.o}
	@echo "compiled $< successfully"

all:${OBJS}
	@${CC} -o ${NAME} ${OBJS}
	@echo "${NAME} file is created successfully"

clean:
	@rm -f ${OBJS}
	@echo "${OBJS} are removed successfully"

fclean:	clean
	@rm -f ${NAME}
	@echo "${NAME} is removed successfully"

.PHONY:		all clean fclean
