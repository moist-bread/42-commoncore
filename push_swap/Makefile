# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 12:30:07 by rduro-pe          #+#    #+#              #
#    Updated: 2025/01/02 15:03:20 by rduro-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ★☆★-‵,┊( NAMES )┊.´-★☆★
NAME = push_swap
BONUS = checker
LIBFT = ./inc/libft/libft.a


# ★☆★-‵,┊( TO DO )┊.´-★☆★
#	REMOVE PRINTING FTS!!!!!!!


# ★☆★-‵,┊( SOURCES AND OBJS )┊.´-★☆★
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


# ★☆★-‵,┊( BONUS SOURCES AND OBJS )┊.´-★☆★
SOURCES_BONUS =	checker.c
SRCS_DIR_BONUS = bonus
SRCS_BONUS = $(addprefix $(SRCS_DIR_BONUS)/, $(SOURCES_BONUS))
OBJS_BONUS = $(addprefix $(OBJS_DIR)/, $(SOURCES_BONUS:.c=.o))


# ★☆★-‵,┊( COMMANDS AND FLAGS )┊.´-★☆★
CC = cc
CFLAGS = -Wall -Wextra -Werror


# ★☆★-‵,┊( MAIN RULES )┊.´-★☆★
all: $(NAME)

$(NAME): $(OBJS_MAIN) $(OBJS) $(LIBFT)
	$(M_COM)
	@$(CC) $(CFLAGS) $(OBJS_MAIN) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(LIBFT):
	@make -C ./inc/libft -s


# ★☆★-‵,┊( BONUS RULES )┊.´-★☆★
bonus: $(OBJS) $(LIBFT) $(OBJS_BONUS)
	$(M_COMBONUS)
	@$(CC) $(CFLAGS) -o $(BONUS) $(OBJS) $(OBJS_BONUS) $(LIBFT)

$(OBJS_DIR)/%.o: $(SRCS_DIR_BONUS)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@


# ★☆★-‵,┊( STANDARD RULES )┊.´-★☆★
clean:
	@make clean -C ./inc/libft -s
	$(M_REMOBJS)
	@rm -rf $(OBJS_DIR)

fclean: clean
	$(M_REMLIB)
	@rm -rf $(LIBFT)
	$(M_REM)
	@rm -rf $(NAME)
	@rm -rf $(BONUS)

re:	fclean all
	@echo "Re-Done!!"

.PHONY: all clean fclean re bonus


# ★☆★-‵,┊( COSMETICS )┊.´-★☆★

#-‵,┊ normal colors
DEF	=	\e[0;39m
GRY	=	\e[0;30m
BLU	=	\e[0;34m
GRN	=	\e[0;32m

#-‵,┊ bold colors
BCYN	=	\e[1;36m

#-‵,┊ background colors
CYNB	=	\e[46m
YELB	=	\e[43m

#-‵,┊ names
PH = placeholder

#-‵,┊ messages
M_COMOBJS = @echo "$(GRY)-->┊$(GRN)  Compiling: $(BCYN) $(NAME)/objs $(GRY)$(DEF)"
M_COMLIB = @echo "$(GRY)-->┊$(GRN)  Compiling: $(DEF)$(YELB) libft.a $(GRY)$(DEF)"
M_COM = @echo "$(GRY)-->┊$(GRN)  Compiling: $(DEF)$(CYNB) $(NAME) $(GRY)$(DEF)"
M_COMBONUS = @echo "$(GRY)-->┊$(GRN)  Compiling: $(DEF)$(CYNB) $(NAME)/bonus $(BONUS) $(GRY)$(DEF)"
M_REMOBJS = @echo "$(GRY)-->┊$(BLU)  Removing: $(BCYN) $(NAME)/objs $(GRY)$(DEF)"
M_REMLIB = @echo "$(GRY)-->┊$(BLU)  Removing: $(DEF)$(YELB) libft.a $(GRY)$(DEF)"
M_REM = @echo "$(GRY)-->┊$(BLU)  Removing: $(DEF)$(CYNB) $(NAME) $(GRY)$(DEF)"

#-‵,┊ tester
test:
	$(M_COMOBJS)
	$(M_COMLIB)
	$(M_COM)
	$(M_COMBONUS)
	$(M_REMOBJS)
	$(M_REMLIB)
	$(M_REM)
	