# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 12:30:07 by rduro-pe          #+#    #+#              #
#    Updated: 2024/11/07 15:30:20 by rduro-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	 ft_printf.c \

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "Archiving OBJS into $(NAME)"
	@ar rcs $(NAME) $(OBJS)

clean:
	@echo "Removing OBJS"
	@rm -f $(OBJS)

fclean: clean
	@echo "Removing $(NAME)"
	@rm -f $(NAME)

re:	fclean all
	@echo "Re-Done!!"

.PHONY: all clean fclean re