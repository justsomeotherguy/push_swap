# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 14:18:22 by jwilliam          #+#    #+#              #
#    Updated: 2022/04/06 12:22:42 by jwilliam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

FLAGS = -Wall -Werror -Wextra -I ./includes

RM = rm -rf

FILES = push_swap.c \
		init_stack.c \
		error.c \
		presort_stack.c \
		validate_args.c \
		print_output.c \
		swap.c \
		push.c \
		rotate.c \
		reverse_rotate.c \
		is_stack_sorted.c \
		find_numbers.c \
		find_stack_positions.c \
		up_to_3.c \
		up_to_5.c \
		up_to_10.c \
		up_to_100.c \
		up_to_500.c

OBJS_NAME = $(FILES:.c=.o)

OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))
SRCS = $(addprefix $(SRC_DIR), $(FILES))
SRC_DIR = srcs/
OBJS_DIR = objs/

all: $(NAME)

$(NAME): $(OBJS)
		@$(MAKE) re -C ./libft
		@$(CC) $(FLAGS) $(SRCS) -I includes ./libft/libft.a -o $(NAME)
		@echo "\033[32m████████████████████████████"
		@echo "\033[32m█████ \033[39mpushswap created \033[32m█████"
		@echo "\033[32m████████████████████████████ \033[39m"

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
		@mkdir -p $(OBJS_DIR)
		@$(CC) $(FLAGS) -o $@ -c $< $(INC)

clean:
		@$(MAKE) clean -C ./libft
		@$(RM) $(OBJS)
		@$(RM) $(OBJS_DIR)
		@echo "\033[33m████████████████████████████"
		@echo "\033[33m█████ \033[39mcleaned pushswap \033[33m█████"
		@echo "\033[33m█████   \033[39mobject files   \033[33m█████"		
		@echo "\033[33m████████████████████████████ \033[39m"

fclean:	clean
		@$(MAKE) fclean -C ./libft		
		@$(RM) $(NAME)
		@$(RM) $(NAME).a
		@echo "\033[33m████████████████████████████"
		@echo "\033[33m█████      \033[39mcleaned     \033[33m█████"
		@echo "\033[33m█████ \033[39mpushswap.a files \033[33m█████"		
		@echo "\033[33m████████████████████████████ \033[39m"

re: fclean all

.PHONY: clean fclean all re