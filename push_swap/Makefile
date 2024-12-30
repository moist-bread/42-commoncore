# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 12:30:07 by rduro-pe          #+#    #+#              #
#    Updated: 2024/12/30 17:13:14 by rduro-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ★☆★-‵,┊( NAMES )┊.´-★☆★
NAME = push_swap
BONUS = checker
LIBFT = ./inc/libft/libft.a


# ★☆★-‵,┊( TO DO )┊.´-★☆★
#	REMOVE PRINTING FTS!!!!!!!
#	MAKE AN EXE RULE
#	MAKE MESSAGES PRETTY 


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
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS_MAIN) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(LIBFT):
	@echo "Compiling libft..."
	@make -C ./inc/libft -s


# ★☆★-‵,┊( BONUS RULES )┊.´-★☆★
bonus: $(OBJS) $(LIBFT) $(OBJS_BONUS)
	@echo "Compiling $(NAME) bonus $(BONUS)..."
	@$(CC) $(CFLAGS) -o $(BONUS) $(OBJS) $(OBJS_BONUS) $(LIBFT)

$(OBJS_DIR)/%.o: $(SRCS_DIR_BONUS)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@


# ★☆★-‵,┊( STANDARD RULES )┊.´-★☆★
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

.PHONY: all clean fclean re bonus


# ★☆★-‵,┊( COSMETICS )┊.´-★☆★

#-‵,┊ normal colors
GRAY		=		\033[0;30m
GREEN		=		\033[0;32m
YELLOW		=		\033[0;33m
BLUE		=		\033[0;34m
MAGENTA		=		\033[0;35m
CYAN		=		\033[0;36m
WHITE		=		\033[0;37m
DEF			=		\033[0;39m

#-‵,┊ bold colors
BGREEN		=		\033[1;32m
BYELLOW		=		\033[1;33m
BBLUE		=		\033[1;34m
BMAGENTA	=		\033[1;35m
BCYAN		=		\033[1;36m

#-‵,┊ background colors
CYNB = \e[46m

#-‵,┊ names
HEAD = head
HEAD_B = headb

#-‵,┊ messages
M_REM = @echo "$(GRAY)★☆★-‵,┊($(BLUE) Removing: $(DEF)$(CYNB) $(NAME) $(GRAY) )┊.´-★☆★$(DEF)\n"
T_CREATING	=		@echo "$(GRAY)-->|	$(BBLUE)Creating $(HEAD) at $(NAME) $(GRAY)...\n"
T_CREATING_B=		@echo "$(GRAY)-->|	$(BBLUE)Creating $(HEAD_B) at $(NAME) $(GRAY)...\n"
T_BUILDING	=		@echo "	$(GRAY)... $(BYELLOW)Building $(NAME) $(GRAY)... \n"
T_COMPILING	=		@echo "	$(GRAY)... $(YELLOW)Compiling $(WHITE)$(FLAGS) $(YELLOW)$< $(GRAY)..."
T_REMOVE_O	=		@echo "$(MAGENTA)$(HEAD): Objects Removed!$(DEF)\n"
T_REMOVE_A	=		@echo "$(BMAGENTA)$(HEAD): All Files Removed!$(DEF)\n"
T_COMPILED	=		@echo "\n$(BGREEN)	     $(HEAD) Compiled!   $(GRAY)|<--$(DEF)\n"
T_EXECUTING	=		@echo "\n$(GRAY)-->|	$(BLUE)Executing: $(BCYAN)$(NAME) - main.c $(BLUE)at $(WHITE)exe $(GRAY)...$(DEF)"
T_EXECUTED	=		@echo "$(GRAY)	...$(BGREEN)Execution Ended!   $(GRAY)|<--$(DEF)\n"

#-‵,┊ tester
test:
	$(M_REM)
	$(T_CREATING)
	$(T_CREATING_B)
	$(T_BUILDING)
	$(T_COMPILING)
	$(T_REMOVE_O)
	$(T_REMOVE_A)
	$(T_COMPILED)
	$(T_EXECUTING)
	$(T_EXECUTED)
	