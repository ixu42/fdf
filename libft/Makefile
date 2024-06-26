# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 15:42:20 by ixu               #+#    #+#              #
#    Updated: 2024/04/02 13:55:15 by ixu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the library
NAME := libft.a

# Compiler and flags
cc := CC
CFLAGS := -Wall -Wextra -Werror

SRCS := nbr/ft_atoi.c \
		nbr/ft_atoi_base.c \
		nbr/ft_itoa.c \
		\
		mem/ft_bzero.c \
		mem/ft_calloc.c \
		mem/ft_memchr.c \
		mem/ft_memcmp.c \
		mem/ft_memcpy.c \
		mem/ft_memmove.c \
		mem/ft_memset.c \
		\
		char/ft_isalnum.c \
		char/ft_isalpha.c \
		char/ft_isascii.c \
		char/ft_isdigit.c \
		char/ft_isprint.c \
		char/ft_tolower.c \
		char/ft_toupper.c \
		\
		str/ft_split.c \
		str/ft_split_charset.c \
		str/ft_split_pipex.c \
		str/ft_strchr.c \
		str/ft_strdup.c \
		str/ft_striteri.c \
		str/ft_strjoin.c \
		str/ft_strlcat.c \
		str/ft_strlcpy.c \
		str/ft_strlen.c \
		str/ft_strmapi.c \
		str/ft_strcmp.c \
		str/ft_strncmp.c \
		str/ft_strnstr.c \
		str/ft_strrchr.c \
		str/ft_strtrim.c \
		str/ft_substr.c \
		\
		file/ft_putchar_fd.c \
		file/ft_putendl_fd.c \
		file/ft_putnbr_fd.c \
		file/ft_putstr_fd.c \
		file/get_next_line.c \
		file/get_next_line_utils.c \
		\
		lst/ft_lstnew.c \
		lst/ft_lstadd_front.c \
		lst/ft_lstsize.c \
		lst/ft_lstlast.c \
		lst/ft_lstadd_back.c \
		lst/ft_lstdelone.c \
		lst/ft_lstclear.c \
		lst/ft_lstiter.c \
		lst/ft_lstmap.c

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "\nBuilt $(NAME)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling libft...\r\c"

clean:
	@rm -f $(OBJS)
 
fclean: clean
	@rm -f $(NAME)
	
re: fclean all