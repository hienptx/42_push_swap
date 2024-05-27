# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 15:52:00 by hipham            #+#    #+#              #
#    Updated: 2024/05/27 20:18:43 by hipham           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Directories path
LIBFT_PATH = ./includes/libft
PRINTF_PATH = ./includes/printf
SRCS_PATH = ./srcs
OBJS_PATH = ./objs

# Headers path
LIBFT_INCL = ./includes/libft/includes
PRINTF_INCL = ./includes/printf/includes
PSW_INCL = ./includes

# Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_INCL) -I$(PRINTF_INCL) -I$(PSW_INCL)

# c files
SRCS = push_swap.c arg_handling.c

# Dependencies
LIBFT = $(LIBFT_PATH)/libft.a
PRINTF = $(PRINTF_PATH)/ftprintf.a
OBJS = $(addprefix $(OBJS_PATH)/, $(SRCS:.c=.o))

# Target
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@echo "Creating archive: $(NAME)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $@

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c | $(OBJS_PATH)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(PRINTF):
	make -C $(PRINTF_PATH)

clean:
	rm -rf $(OBJS) $(LIBFT) $(PRINTF)

fclean: clean
	rm -f $(NAME)

re: fclean all