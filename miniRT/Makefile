# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/21 20:09:31 by cedmulle          #+#    #+#              #
#    Updated: 2024/04/24 17:16:22 by cedmulle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= miniRT

SRC_DIR	= ./src/
INC_DIR	= ./inc/
OBJ_DIR	= ./obj/

SRC		= $(SRC_DIR)miniRT.c \
			$(SRC_DIR)draw_utils.c \
			$(SRC_DIR)ced.c
OBJ		= $(SRC:.c=.o)

CC		= gcc
CFL		= -Wall -Wextra -Werror
MLX		= -L$(INC_DIR)mlx -lmlx -framework OpenGL -framework AppKit -O3 -ffast-math
RM		= rm -f

all:
	@make -C inc/mlx > /dev/null 2>&1
	@echo "MLX compiled"
	@make -C inc/libft > /dev/null 2>&1
	@echo "Libft compiled"
	@make $(NAME)
	@echo "miniRT compiled"

$(NAME): $(OBJ)
	@$(CC) $(CFL) $(MLX) -o $(NAME) $(OBJ) $(INC_DIR)libft/libft.a $(INC_DIR)mlx/libmlx.a

%.o: %.c
	@$(CC) $(CFL) -c $< -o $@ -I $(INC_DIR)

clean:
	@$(RM) $(OBJ)
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
