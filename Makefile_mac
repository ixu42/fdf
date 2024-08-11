# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 19:44:04 by ixu               #+#    #+#              #
#    Updated: 2024/08/11 17:26:08 by ixu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program
NAME := fdf

# Compiler and flags
cc := CC
CFLAGS := -Wall -Wextra -Werror
MLX_FLAGS := -framework Cocoa -framework OpenGL -framework IOKit

# Color scheme
COLOR_BLUE := \033[0;34m
COLOR_BRIGHT_GREEN := \033[0;92m
COLOR_END := \033[0m

# Directory locations
SRCS_DIR := srcs/
OBJS_DIR := objs/
LIBFT_DIR := libft/
MLX42_DIR := MLX42/build/
GLFW_DIR := /Users/ixu/.brew/opt/glfw/lib/

# Source file names
SRCS := fdf.c \
		read_file.c \
		color.c \
		rgba.c \
		gradient.c \
		init.c \
		hooks.c \
		free.c \
		error.c \
		projection.c \
		transform.c \
		draw.c

# Object files with paths
OBJS := $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

# Libraries with paths
LIBFT := $(LIBFT_DIR)libft.a
MLX := $(MLX42_DIR)libmlx42.a

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS) $(LIBFT) $(MLX)
	@$(CC) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -Iinclude -lglfw -L$(GLFW_DIR) -L$(MLX42_DIR) -lmlx42 -L$(LIBFT_DIR) -lft
	@echo "$(COLOR_BRIGHT_GREEN)Built $(NAME)$(COLOR_END)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo "Built $(OBJS_DIR) directory"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Building $@"

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

$(MLX):
	@cd MLX42 && cmake -B build && cmake --build build -j4
	@$(MAKE) -s -C $(MLX42_DIR)

clean:
	@rm -fr $(OBJS_DIR)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(MLX42_DIR) clean
	@echo "$(COLOR_BLUE)Removed fdf object files$(COLOR_END)"
	@echo "$(COLOR_BLUE)Cleaned up libft and MLX42$(COLOR_END)"
 
fclean: clean
	@rm -f $(NAME)
	@echo "$(COLOR_BLUE)Removed $(NAME)$(COLOR_END)"

re: fclean all