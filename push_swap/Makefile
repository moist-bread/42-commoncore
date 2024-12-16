# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 12:30:07 by rduro-pe          #+#    #+#              #
#    Updated: 2024/12/16 17:40:23 by rduro-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

#	CHANGE NAME BACK TO "push_swap"
#	REMOVE PRINTING FTRS FROM HELPERS

SRCS =	ft_printf.c ft_conversions.c push_swap_main.c push.c swap.c ft_atoi.c \
		revrotate.c error_check.c ft_split.c ft_substr.c ft_strlen.c ft_strdup.c \
		sorting.c make_helpers.c sort_helpers.c executers.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@echo "Removing OBJS"
	@rm -f $(OBJS)

fclean: clean
	@echo "Removing $(NAME)"
	@rm -f $(NAME)

re:	fclean all
	@echo "Re-Done!!"

.PHONY: all clean fclean re