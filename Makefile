# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile0                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 19:58:44 by wphokomp          #+#    #+#              #
#    Updated: 2018/01/11 20:17:23 by wphokomp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = expert_system

SRC = main.c

OBJ = $(SRC:%.c=%.o)

LIB = ./libft/

FLAGS = #-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRC)
	@make -C $(LIB)
	@gcc -c $(FLAGS) $(SRC)
	gcc -g -o $(NAME) $(FLAGS) $(OBJ) -L$(LIB)libft.a
	@echo "\x1b[31mCompiled...\x1b[0m"

clean:
	@rm -fr $(OBJ)
	@cd $(LIB) && $(MAKE) clean
	@echo "\x1b[31mObject files cleaned.\x1b[0m"

fclean: clean
	@rm -fr $(NAME)
	@cd $(LIB) && $(MAKE) fclean
	@echo "\x1b[31mEverything cleaned.\x1b[0m"

re: fclean all
