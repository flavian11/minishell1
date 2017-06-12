##
## Makefile for  in /home/flavian.feugueur/PSU/bootstrap/PSU_2016_minishell1
## 
## Made by Flavian Feugueur
## Login   <flavian.feugueur@epitech.net>
## 
## Started on  Mon Jan  2 20:11:21 2017 Flavian Feugueur
## Last update Sun Jan 22 12:58:46 2017 Flavian Feugueur
##

CC	=	gcc -g

RM	=	rm -f

SRC	=	main.c	\
		my_exit.c	\
		my_ls_option.c	\
		tool.c	\
		tool2.c	\
		tool3.c	\
		my_str_to_word_tab.c	\
		my_cd.c	\
		print_env.c	\
		my_exec.c	\
		my_setenv.c	\
		old_set_env.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	+=	-I ./ -W -Wextra -Wall

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)  -L ./lib -lgnl	

clean:
	$(RM) $(OBJ)
	$(RM) $(SRC:.c=.c~)
	$(RM) $(SRC:.c=.c#)

fclean: clean
	$(RM) $(NAME)

re: fclean all

flav: re
	make clean
	@echo -e "\033[31;5m        @@@@@@           @@@@@@"
	@echo -e "      @@@@@@@@@@       @@@@@@@@@@"
	@echo -e "    @@@@@@@@@@@@@@   @@@@@@@@@@@@@@"
	@echo -e "  @@@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@"
	@echo -e " @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo -e "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo -e "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo -e "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo -e " @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo -e "  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo -e "   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo -e "    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo -e "      @@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo -e "        @@@@@@@@@@@@@@@@@@@@@@@"
	@echo -e "          @@@@@@@@@@@@@@@@@@@"
	@echo -e "            @@@@@@@@@@@@@@@"
	@echo -e "              @@@@@@@@@@@"
	@echo -e "                @@@@@@@"
	@echo -e "                  @@@"
	@echo -e "                   @\033[0m"
