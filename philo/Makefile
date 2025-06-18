# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 12:30:07 by rduro-pe          #+#    #+#              #
#    Updated: 2025/06/18 18:10:27 by rduro-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -->┊( NAMES )┊.´-★☆★
NAME	=	philo
LIBFT	=	./inc/libft/libft.a

# -->┊( COMMANDS AND FLAGS )┊.´-★☆★
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g
VAL		=	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s
HELFLAG	=	--tool=helgrind

# -->┊( DIRECTORIES )┊.´-★☆★
SRC_DIR	=	src
OBJ_DIR	=	obj


# -->┊( SOURCE AND OBJS )┊.´-★☆★
SOURCE	=	main.c parse.c init.c cycles.c utils.c

SRC		=	$(addprefix $(SRC_DIR)/, $(SOURCE))
OBJS	=	$(addprefix $(OBJ_DIR)/, $(SOURCE:.c=.o))


# -->┊( COMPILATION RULES )┊.´-★☆★
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(M_COMOBJS)
	$(M_COM)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@make -C ./inc/libft -s


# -->┊( EXECUTION RULES )┊.´-★☆★
exe: all
	./philo 7 700 200 300 2

val: all
	$(VAL) ./philo 7 500 200 100 6


# -->┊( STANDARD RULES )┊.´-★☆★
clean:
	@make clean -C ./inc/libft -s
	$(M_REMOBJS)
	@rm -rf $(OBJ_DIR)

fclean: clean
	$(M_REMLIB)
	@rm -rf $(LIBFT)
	$(M_REM)
	@rm -rf $(NAME)

re:	fclean all
	$(M_RE)

.PHONY: all clean fclean re


# -->┊( COSMETICS )┊.´-★☆★

#-‵,┊ normal colors
DEF	=	\e[0;39m
BLK	=	\e[0;30m
BLU	=	\e[0;34m
MAG =	\e[0;35m
GRN	=	\e[0;32m

#-‵,┊ bold colors
BCYN	=	\e[1;36m
BBLU	=	\e[1;34m

#-‵,┊ background colors
CYNB	=	\e[46m
YELB	=	\e[43m
BLUB	=	\e[44m

#-‵,┊ messages
M_COMOBJS	= @echo "$(BLK)-->┊$(GRN)  Compiling: $(BBLU)$(NAME)/objs $(BLK)$(DEF)"
M_COMLIB	= @echo "$(BLK)-->┊$(GRN)  Compiling: $(DEF)$(YELB) libft.a $(BLK)$(DEF)"
M_COM		= @echo "$(BLK)-->┊$(GRN)  Compiling: $(DEF)$(BLUB) $(NAME) $(BLK)$(DEF)\n"
M_REMOBJS	= @echo "$(BLK)-->┊$(BLU)  Removing: $(BBLU) $(NAME)/objs $(BLK)$(DEF)"
M_REMLIB	= @echo "$(BLK)-->┊$(BLU)  Removing:  $(DEF)$(YELB) libft.a $(BLK)$(DEF)"
M_REM		= @echo "$(BLK)-->┊$(BLU)  Removing:  $(DEF)$(BLUB) $(NAME) $(BLK)$(DEF)\n"
M_RE		= @echo "$(BLK)... $(BLU)  Re Done   $(DEF)$(BCYN) ($(NAME) is ready !!)$(DEF)"