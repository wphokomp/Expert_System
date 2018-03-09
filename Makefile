# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 19:58:44 by wphokomp          #+#    #+#              #
#    Updated: 2018/01/28 03:22:16 by wphokomp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= expert_system

HEAD	= ./inc/

INC		= I $(HEAD)

SRC_P	= ./src/

SRCS	= main.c get_info.c eval_query.c rev_polish.c error_hndler.c process.c\
		  compute.c analogy.c

SRC		= $(addprefix $(SRC_P), $(SRCS))

OBJ		= $(patsubst %.c,%.o, $(SRCS))

LIB		= ./libft/

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@echo "\033[32m\tExpert_System Starting...\033[00m"
	@echo "\033[33m=============================================\033[00m"
	@echo "\033[32mMaking C Library..."
	@make -C $(LIB)
	@echo "\033[33m=============================================\033[00m"
	@echo "\033[33m#                                           #\033[00m"
	@echo "\033[33m# Creating An AI Called EXP_SYS, Be Patient #\033[00m"
	@echo "\033[33m#                                           #\033[00m"
	@echo "\033[33m=============================================\033[00m"
	@echo "\033[33m=============================================\033[00m"
	@gcc -c $(FLAGS) $(SRC)
	@gcc -g -o $(NAME) $(FLAGS) $(OBJ) libft/libft.a
	@echo "\x1b[34m\t!AI EXP_SYS is READY FOR YOU!.\x1b[0m"
	@echo "\033[33m=============================================\033[00m"

clean:
	@echo "\033[31mCleaning Project EXP_SYS...\033[00m"
	@rm -fr $(OBJ)
	@rm -fr ./src/.*.swp
	@cd $(LIB) && $(MAKE) clean
	@echo "\x1b[31mObject files cleaned.\x1b[0m"

fclean: clean
	@echo "\033[31mCleaning Everythin...\033[00m"
	@rm -fr $(NAME)
	@cd $(LIB) && $(MAKE) fclean
	@echo "\x1b[31mEverything cleaned.\x1b[0m"

re: fclean all

.PHONY: clean fclean all re
