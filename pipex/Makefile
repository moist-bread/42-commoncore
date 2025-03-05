# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 12:30:07 by rduro-pe          #+#    #+#              #
#    Updated: 2025/03/05 20:38:45 by rduro-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ★☆★-‵,┊( NAMES )┊.´-★☆★
NAME = pipex
LIBFT = ./inc/libft/libft.a


# ★☆★-‵,┊( TO DO )┊.´-★☆★
#	bonus


# ★☆★-‵,┊( SOURCES AND OBJS )┊.´-★☆★
MAIN    =  pipex_main.c
SOURCES =  pipex_utils.c destroyers.c command_parsing.c

SRCS_DIR = srcs
SRCS = $(addprefix $(SRCS_DIR)/, $(SOURCES))
MAIN_SRC = $(addprefix $(SRCS_DIR)/, $(MAIN))

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SOURCES:.c=.o))
OBJS_MAIN = $(addprefix $(OBJS_DIR)/, $(MAIN:.c=.o))


# ★☆★-‵,┊( BONUS SOURCES AND OBJS )┊.´-★☆★
SOURCES_BONUS =	bonus_pipex_main.c
SRCS_DIR_BONUS = bonus
SRCS_BONUS = $(addprefix $(SRCS_DIR_BONUS)/, $(SOURCES_BONUS))
OBJS_BONUS = $(addprefix $(OBJS_DIR)/, $(SOURCES_BONUS:.c=.o))


# ★☆★-‵,┊( COMMANDS AND FLAGS )┊.´-★☆★
CC = cc
CFLAGS = -Wall -Wextra -Werror
VAL = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s
FDFLAGS = --trace-children=yes --track-fds=yes


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
	@$(CC) $(CFLAGS) $(OBJS) $(OBJS_BONUS) $(LIBFT) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR_BONUS)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@


# ★☆★-‵,┊( EXECUTION RULES )┊.´-★☆★
exe_setup: exe_clean all
	cat Makefile > infile_1
	cat srcs/destroyers.c | grep // > infile_2

exe_clean:
	rm -rf infile_1 
	rm -rf infile_2 
	rm -rf outfile_1 
	rm -rf outfile_2 
	rm -rf outfile_3 
	
# cat with existing infile
exe1: all
	./pipex infile_1 "cat" "cat" outfile_1

# basic grep
exe2: all
	./pipex infile_1 "cat" "grep BONUS" outfile_2

# cats with no infile
exe3: all
	./pipex i_dont_exist "cat" "cat" outfile_2

# sleeping
exe4: all
	./pipex infile_1 "sleep 4" "sleep 2" outfile_1

# sleeping with no infile
exe5: all
	$(VAL) $(FDFLAGS) ./pipex i_dont_exist "sleep 500" "sleep 2" outfile_1

# spaces in between ''
exe6: all
	./pipex infile_1 "ls -la" "cut -d ' ' -f 1" outfile_3

# first cmd doesnt exist
exe7: all
	$(VAL) $(FDFLAGS) ./pipex infile_1 "cato" "sleep 3" outfile_3

# second cmd doesnt exist
exe8: all
	$(VAL) $(FDFLAGS) ./pipex infile_1 "sleep 3" "i_dont_exist" outfile_3

# command with just spaces
exe9: all
	$(VAL) $(FDFLAGS) ./pipex infile_1 "  " "sleep 3" outfile_3


# ★☆★-‵,┊( STANDARD RULES )┊.´-★☆★
clean: exe_clean
	@make clean -C ./inc/libft -s
	$(M_REMOBJS)
	@rm -rf $(OBJS_DIR)

fclean: clean
	$(M_REMLIB)
	@rm -rf $(LIBFT)
	$(M_REM)
	@rm -rf $(NAME)

re:	fclean all
	@echo "Re-Done!!"

.PHONY: all clean fclean re bonus exe_setup exe_clean exe1 exe2 exe3 exe4 exe5 exe6 exe7 exe8


# ★☆★-‵,┊( COSMETICS )┊.´-★☆★

#-‵,┊ normal colors
DEF	=	\e[0;39m
GRY	=	\e[0;30m
BLU	=	\e[0;34m
GRN	=	\e[0;32m
YEL =	\e[0;33m

#-‵,┊ bold colors
BCYN	=	\e[1;36m
BHMAG	=	\e[1;95m
BBLU	=	\e[1;34m

#-‵,┊ background colors
CYNB	=	\e[46m
YELB	=	\e[43m
MAGHB	=	\e[0;105m
BLUB	=	\e[44m

#-‵,┊ names
PH = placeholder

#-‵,┊ messages
M_COMOBJS = @echo "$(GRY)-->┊$(GRN)  Compiling: $(BCYN) $(NAME)/objs $(GRY)$(DEF)"
M_COMLIB = @echo "$(GRY)-->┊$(GRN)  Compiling: $(DEF)$(YELB) libft.a $(GRY)$(DEF)"
M_COM = @echo "$(GRY)-->┊$(GRN)  Compiling: $(DEF)$(BLUB) $(NAME) $(GRY)$(DEF)"
M_COMBONUS = @echo "$(GRY)-->┊$(GRN)  Compiling: $(DEF)$(CYNB) $(NAME)/bonus $(NAME) $(GRY)$(DEF)"
M_REMOBJS = @echo "$(GRY)-->┊$(BLU)  Removing: $(BBLU) $(NAME)/objs $(GRY)$(DEF)"
M_REMLIB = @echo "$(GRY)-->┊$(BLU)  Removing: $(DEF)$(YELB) libft.a $(GRY)$(DEF)"
M_REM = @echo "$(GRY)-->┊$(BLU)  Removing: $(DEF)$(BLUB) $(NAME) $(GRY)$(DEF)"


#-‵,┊ tester
test:
	$(M_COMOBJS)
	$(M_COMLIB)
	$(M_COM)
	$(M_COMBONUS)
	$(M_REMOBJS)
	$(M_REMLIB)
	$(M_REM)
	$(M_COMMLXOBJS)
	$(M_ARCMLX)
	$(M_REMMLX)
	$(M_REMMLXOBJS)	