# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/21 20:09:31 by cedmulle          #+#    #+#              #
#    Updated: 2024/04/24 19:29:57 by cedmulle         ###   ########.fr        #
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

# Colors
RED		= \033[1;31m
GRE		= \033[1;32m
YEL		= \033[1;33m
BLU		= \033[1;34m
MAG		= \033[1;35m
CYA		= \033[1;36m
RST		= \033[0m
D_RED	= \033[0;31m
D_GRE	= \033[0;32m
D_YEL	= \033[0;33m
D_BLU	= \033[0;34m
D_MAG	= \033[0;35m
D_CYA	= \033[0;36m
D_GRY	= \033[0;38;2;128;128;128m
CLR 	= \033c

all: $(OBJ_DIR)
	@echo "$(CLR)$(D_MAG)Building MLX...$(RST)"
	@make -C inc/mlx > /dev/null 2>&1
	@echo "$(CLR)$(D_CYA)Building Libft...$(RST)"
	@make -C inc/libft > /dev/null 2>&1
	@echo "$(CLR)$(D_GRE)Building $(NAME)...\n$(RST)"
	@make $(NAME) > /dev/null 2>&1
	@echo "$(CLR)\n$(GRE)----------------------------------------\n"
	@echo "       Executable $(NAME) created !\n"
	@echo "----------------------------------------$(RST)\n\n"
	@echo "$(YEL)Usage: ./miniRT [scene.rt]\n$(RST)"
	@echo "$(D_GRY)List of available scenes:"
	@ls -1 scenes | sed 's/^/- scenes\//'
	@echo "$(RST)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(shell dirname $(OBJ))

$(NAME): $(OBJ)
	@$(CC) $(CFL) $(MLX) -o $(NAME) $(OBJ) $(INC_DIR)libft/libft.a $(INC_DIR)mlx/libmlx.a

$(OBJ_DIR)/%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFL) -c $< -o $@ -I $(INC_DIR)
	@echo "$(CLR)-> $(D_CYAN)Compiling $<$(RST)"

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(CLR)$(D_BLU)Objects cleaned$(RST)"
	@echo "$(D_BLU)miniRT cleaned$(RST)"
	@make clean -C ./inc/libft > /dev/null 2>&1
	@echo "$(D_BLU)Libft cleaned\n$(RST)"

fclean: clean
	@make fclean -C ./inc/libft > /dev/null 2>&1
	@echo "$(D_RED)Libft deep cleaned$(RST)"
	@make clean -C ./inc/mlx > /dev/null 2>&1
	@echo "$(D_RED)MLX deep cleaned$(RST)"
	@$(RM) $(NAME) > /dev/null 2>&1
	@echo "$(D_RED)miniRT deep cleaned\n$(RST)"

re: fclean all

.PHONY: all clean fclean re
