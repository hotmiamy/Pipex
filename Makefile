NAME 			= pipex
CC				= gcc
FLAGS			= -Wall -Wextra -Werror -g
RM				= rm -rf

SRC_F 			= main.c childs.c error.c free.c init.c treat_cmd.c
SRC				= $(addprefix ./src/, $(SRC_F))
OBJ_S			= $(SRC:.c=.o)

LIBFT = ./libft/libft.a

HEADER_F		= pipex.h
HEADER			= $(addprefix ./header/, $(HEADER_F))

#COMMANDS

all: $(NAME)

%.o: %.c $(HEADER) Makefile
	@ echo $(CURSIVE) $(YELLOW) " - Compiling $<..." $(NONE)
	@ $(CC) $(FLAGS) -c $< -o $@
	@ echo $(GREEN) " - Compiled !" $(NONE)

$(NAME): $(OBJ_S) $(OBJ_F) $(LIBFT)
	@ echo $(CURSIVE) $(YELLOW) " -Making Objects: $(OBJ_S) $(OBJ_F)" $(NONE)
	@ $(CC) $(OBJ_S) $(LIBFT) -o $(NAME)
	@ echo $(GREEN) " - Objects Created !" $(NONE)

$(LIBFT):
	@ echo $(CURSIVE) $(YELLOW) " - Compiling $(LIBFT)..." $(NONE)
	@ make all -C ./libft

valgrind:
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --log-file=log_valgrind -s ./$(NAME) file1 "cat" "tr [a-z] [A-Z]" outfile

clean:
	@ echo $(RED) " - Deleting Objects: $(OBJ_F)" $(NONE)
	@ $(RM) $(OBJ_F)
	@ echo $(RED) " - Deleting Objects: $(OBJ_S)" $(NONE)
	@ $(RM) $(OBJ_S)
	@ echo $(GREEN) " - Objects deleted !" $(NONE)

fclean: clean
	@ echo $(RED) " - Deleting $(NAME)..." $(NONE)
	@ $(RM) $(NAME)
	@ echo $(RED) " - $(NAME) Deleted !" $(NONE)

re: fclean all

.PHONY: re all fclean clean

#COLORS

NONE='\033[0m'
RED ='\033[1;31m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'