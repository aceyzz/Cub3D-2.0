# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/21 20:09:31 by cedmulle          #+#    #+#              #
#    Updated: 2024/04/24 18:44:48 by cedmulle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = miniRT

SRC_DIR = ./src/
INC_DIR = ./inc/
OBJ_DIR = ./obj/

SRC     = $(shell find $(SRC_DIR) -type f -name '*.c')
OBJ     = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

CC      = gcc
CFL     = -Wall -Wextra -Werror
MLX     = -L$(INC_DIR)mlx -lmlx -framework OpenGL -framework AppKit -O3 -ffast-math
RM      = rm -rf

all: $(OBJ_DIR)
	@make -C inc/mlx > /dev/null 2>&1
	@echo "MLX compiled"
	@make -C inc/libft > /dev/null 2>&1
	@echo "Libft compiled"
	@make $(NAME)
	@echo "miniRT compiled"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(shell dirname $(OBJ))

$(NAME): $(OBJ)
	@$(CC) $(CFL) $(MLX) -o $(NAME) $(OBJ) $(INC_DIR)libft/libft.a $(INC_DIR)mlx/libmlx.a

$(OBJ_DIR)/%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFL) -c $< -o $@ -I $(INC_DIR)

clean:
	@find $(OBJ_DIR) -type f -name '*.o' -delete
	@$(RM) $(OBJ_DIR)
	@echo "miniRT cleaned"
	@make clean -C ./inc/libft > /dev/null 2>&1
	@echo "Libft cleaned"

fclean: clean
	@$(RM) $(NAME)
	@echo "miniRT deep cleaned"
	@make clean -C ./inc/mlx > /dev/null 2>&1
	@echo "MLX cleaned"
	@make fclean -C ./inc/libft > /dev/null 2>&1
	@echo "Libft deep cleaned"

re: fclean all

.PHONY: all clean fclean re
