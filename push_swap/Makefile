# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile copy                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 12:30:07 by rduro-pe          #+#    #+#              #
#    Updated: 2024/12/28 20:59:16 by rduro-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

#	REMOVE PRINTING FTS

# SOURCES AND OBJS
MAIN    =   push_swap_main.c
SOURCES =	make_stack.c error_check.c sorting.c \
			sort_helpers.c quick_sort.c sort_calc.c executers.c \
			swap.c push.c revrotate.c \
			printing.c

SRCS_DIR = srcs
SRCS = $(addprefix $(SRCS_DIR)/, $(SOURCES))
MAIN_SRC = $(addprefix $(SRCS_DIR)/, $(MAIN))

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SOURCES:.c=.o))
OBJS_MAIN = $(addprefix $(OBJS_DIR)/, $(MAIN:.c=.o))

LIBFT = ./inc/libft/libft.a

# BONUS STUFF
BONUS = checker

SOURCES_BONUS =	checker.c
SRCS_DIR_BONUS = bonus
SRCS_BONUS = $(addprefix $(SRCS_DIR_BONUS)/, $(SOURCES_BONUS))
OBJS_BONUS = $(addprefix $(OBJS_DIR)/, $(SOURCES_BONUS:.c=.o))

# COMPILATION STUFFS
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS_MAIN) $(OBJS) $(LIBFT)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS_MAIN) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(LIBFT):
	@echo "Compiling libft..."
	@make -C ./inc/libft -s

bonus: $(OBJS) $(LIBFT) $(OBJS_BONUS)
	@echo "Compiling $(NAME) bonus $(BONUS)..."
	@$(CC) $(CFLAGS) -o $(BONUS) $(OBJS) $(OBJS_BONUS) $(LIBFT)

$(OBJS_DIR)/%.o: $(SRCS_DIR_BONUS)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removing push_swap OBJS"
	@rm -rf $(OBJS_DIR)
	@make clean -C ./inc/libft -s

fclean: clean
	@echo "Removing $(NAME)"
	@rm -rf $(NAME)
	@rm -rf $(BONUS)
	@echo "Removing libft.a"
	@rm -rf $(LIBFT)

re:	fclean all
	@echo "Re-Done!!"

.PHONY: all clean fclean re