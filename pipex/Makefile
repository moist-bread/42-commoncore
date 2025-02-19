# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 12:30:07 by rduro-pe          #+#    #+#              #
#    Updated: 2025/02/19 15:38:00 by rduro-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ★☆★-‵,┊( NAMES )┊.´-★☆★
NAME = pipex
LIBFT = ./inc/libft/libft.a


# ★☆★-‵,┊( TO DO )┊.´-★☆★
#	start


# ★☆★-‵,┊( SOURCES AND OBJS )┊.´-★☆★
MAIN    =  pipex_main.c
SOURCES =  pipex_utils.c

SRCS_DIR = srcs
SRCS = $(addprefix $(SRCS_DIR)/, $(SOURCES))
MAIN_SRC = $(addprefix $(SRCS_DIR)/, $(MAIN))

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SOURCES:.c=.o))
OBJS_MAIN = $(addprefix $(OBJS_DIR)/, $(MAIN:.c=.o))


# ★☆★-‵,┊( COMMANDS AND FLAGS )┊.´-★☆★
CC = cc
CFLAGS = -Wall -Wextra -Werror


# ★☆★-‵,┊( MAIN RULES )┊.´-★☆★
all: $(NAME)

$(NAME): $(OBJS_MAIN) $(OBJS) $(LIBFT) $(MLX)
	$(M_COM)
	@$(CC) $(CFLAGS) $(OBJS_MAIN) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(LIBFT):
	@make -C ./inc/libft -s

exe1: all cl1
	./pipex text1.txt "cat" "cat" text2.txt
	
ex1: cl1
	< text1.txt "cat" | "cat" > text2.txt

cl1:
	echo "" > text2.txt

cl3:
	echo "" > text3.txt

exe2: all
	rm -rf text3.txt
	./pipex text1.txt "cat" "cat" text3.txt
	cat text3.txt

exe3: all
	./pipex srcs "ls -la" "cat" text2.txt

exe4: all
	./pipex text1.txt "grep COPY" "wc -l" text3.txt

ex4: cl3
	< text1.txt grep COPY | wc -l  > text3.txt

exe5: all
	./pipex text1.txt "cat" "wc -l" outfile

exe6: all
	./pipex text1.txt "cato" "ls" text3.txt

exe7: all
	valgrind --track-origins=yes -s ./pipex text1.txt "cato" "ls" text3.txt
	
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

re:	fclean all
	@echo "Re-Done!!"

.PHONY: all clean fclean re bonus


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
M_COMBONUS = @echo "$(GRY)-->┊$(GRN)  Compiling: $(DEF)$(CYNB) $(NAME)/bonus $(BONUS) $(GRY)$(DEF)"
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