# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 12:30:07 by rduro-pe          #+#    #+#              #
#    Updated: 2024/12/27 15:10:54 by rduro-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

#	REMOVE PRINTING FTS FROM HELPERS
#	ADD ALL OF LIBFT CAUSE WHY NOT

SRCS =	push_swap_main.c error_check.c sorting.c \
		sort_helpers.c quick_sort.c sort_calc.c executers.c \
		swap.c push.c revrotate.c \
		ft_printf.c ft_conversions.c \
		ft_atoi.c ft_substr.c ft_split.c ft_strlen.c ft_strdup.c \
		printing.c

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