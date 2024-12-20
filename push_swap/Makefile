# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 12:30:07 by rduro-pe          #+#    #+#              #
#    Updated: 2024/12/20 16:44:21 by rduro-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

#	CHANGE NAME BACK TO "push_swap"
#	REMOVE PRINTING FTS FROM HELPERS
#	ADD ALL OF LIBFT CAUSE WHY NOT

SRCS =	ft_printf.c ft_conversions.c push_swap_main.c push.c swap.c ft_atoi.c \
		revrotate.c error_check.c ft_split.c ft_substr.c ft_strlen.c ft_strdup.c \
		sorting.c make_helpers.c sort_helpers.c executers.c printing.c sort_calc.c \
		quick_sort.c

#LIBFT = ./libft/libft.a

OBJ_DIR = obj

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

#$(LIBFT):
#	@echo "Compiling libft..."
#	@make -C ./libft -s

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@echo "Removing OBJS"
	@rm -rf $(OBJ_DIR)
#@make clean -C ./libft -s

fclean: clean
	@echo "Removing $(NAME)"
	@rm -rf $(NAME)
#@make fclean -C ./libft -s

re:	fclean all
	@echo "Re-Done!!"

.PHONY: all clean fclean re