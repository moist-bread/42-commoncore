# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 12:30:07 by rduro-pe          #+#    #+#              #
#    Updated: 2024/12/27 16:28:28 by rduro-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

LST	=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
		ft_lstlast.c ft_lstnew.c ft_lstsize.c \
		ft_lstmap.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(LST:.c=.o)

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
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@echo "Removing $(NAME)"
	@rm -f $(NAME)

re:	fclean all
	@echo "Re-Done!!"

bonus: $(OBJS) $(BONUS_OBJS)
	@echo "Archiving OBJS and BONUS into $(NAME)"
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS) 

.PHONY: all clean fclean re bonus