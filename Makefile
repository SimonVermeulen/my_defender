##
## EPITECH PROJECT, 2021
## B-CPE-110-TLS-1-1-BSQ-younes1.bahri
## File description:
## Makefile
##

SRC				=		src/main.c	\

OBJ 			=		$(SRC:.c=.o)

NAME 			= 		my_defender

LIBFLAG 		= 		lib/liblist.a lib/libjson_parser.a lib/libmy.a lib/libma.a lib/game_engine.a

CFLAGS 			+= 		-I ./include -g3

all:	$(NAME)

$(NAME): 	$(OBJ)
		$(MAKE) -C ./lib/game_engine
		$(MAKE) -C ./lib/my
		$(MAKE) -C ./lib/libma
		$(MAKE) -C ./lib/linked_list
		$(MAKE) -C ./lib/json_parser
		$(CC) -o $(NAME) $(OBJ) $(LIBFLAG)

clean:
		rm -f $(OBJ)

fclean:
		rm -rf $(NAME)

re: fclean all