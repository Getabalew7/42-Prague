# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbouillo <pbouillo@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 21:47:45 by pibouill          #+#    #+#              #
#    Updated: 2023/06/28 23:41:18 by pbouillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= bsq
CFLAGS 		= -Wall -Werror -Wextra
CC 			= cc
RM			= rm
SRC_DIR 	= srcs
INC			= includes/
BIN_DIR 	= bin

################################################################################
## COLORS

RED			= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
END_COLOR	= \033[0;38m

################################################################################
## SOURCES

SRC_FILES	=	count_lines\
				ft_load_map\
				main\
				ft_helpers\
				ft_atoi

OBJ				= $(addprefix $(BIN_DIR)/, $(addsuffix .o, $(SRC_FILES)))
SRC				= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))

################################################################################
## RULES

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ)
	@echo "$(GREEN)$(NAME) compiled $(END_COLOR)"

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c Makefile | $(BIN_DIR)
	@$(CC) -c $(CFLAGS) -I $(INC) $< -o $@
	@echo "$(BLUE)Compiling... $(notdir $<)$(END_COLOR)"

$(BIN_DIR):
	@mkdir $(BIN_DIR)
	@echo "$(YELLOW)Created $(BIN_DIR)/ directory in $(NAME)/$(END_COLOR)"

clean:
	@rm -rf $(BIN_DIR)
	@echo "$(YELLOW)$(NAME) object files cleaned.$(END_COLOR)"

fclean: clean
	@rm -f $(NAME) $(CZ_NAME)
	@echo "$(YELLOW)$(NAME) executable file cleaned.$(END_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned everything and rebuilt $(NAME) $(END_COLOR)"
