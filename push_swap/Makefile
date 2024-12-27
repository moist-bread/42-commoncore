# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 12:30:07 by rduro-pe          #+#    #+#              #
#    Updated: 2024/12/27 17:16:03 by rduro-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

#	REMOVE PRINTING FTS

SOURCES =	push_swap_main.c error_check.c sorting.c \
			sort_helpers.c quick_sort.c sort_calc.c executers.c \
			swap.c push.c revrotate.c \
#			printing.c

SRCS_DIR = srcs

SRCS = $(addprefix $(SRCS_DIR)/, $(SOURCES))

OBJS_DIR = objs

OBJS = $(addprefix $(OBJS_DIR)/, $(SOURCES:.c=.o))

LIBFT = ./inc/libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(LIBFT):
	@echo "Compiling libft..."
	@make -C ./inc/libft -s

clean:
	@echo "Removing push_swap OBJS"
	@rm -rf $(OBJS_DIR)
	@make clean -C ./inc/libft -s

fclean: clean
	@echo "Removing $(NAME)"
	@rm -rf $(NAME)
	@echo "Removing libft.a"
	@rm -rf $(LIBFT)

re:	fclean all
	@echo "Re-Done!!"

.PHONY: all clean fclean re