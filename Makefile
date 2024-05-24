# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 15:52:00 by hipham            #+#    #+#              #
#    Updated: 2024/05/24 17:40:35 by hipham           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Directories path
LIBFT_PATH = ./libft
PRINTF_PATH = ./printf
SRCS_PATH = ./srcs
OBJS_PATH = ./objs

# Headers path
LIBFT_INCL = ./libft/includes
PRINTF_INCL = ./libft/includes
PSW_INCL = ./includes

# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# c files
SRCS = *.c

# Dependencies
LIBFT = $(LIBFT_PATH)/libft.a
PRINTF = $(PRINTF_PATH)/ftprintf.a
OBJS = $(addprefix $(OBJS_PATH)/, $(SRCS: .c=.o))

# Target
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -I$(LIBFT_INCL) -I$(PRINTF_INCL) $(OBJS) $(CFLAGS) -o $@ -c $<

clean:

fclean:

re: