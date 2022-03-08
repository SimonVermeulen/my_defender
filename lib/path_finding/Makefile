##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile of the pathfinding lib
##

SRC =	main.c		\
		path.c		\
		initialization_gestion.c	\

OBJ =	$(SRC:.c=.o)

BINARY =	path_finder

CFLAGS =	-I../../include/

all:	$(BINARY)

$(BINARY):	$(OBJ)
	$(MAKE) -C ../my/
	gcc -o $(BINARY) $(OBJ) -L../ -llist

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(BINARY)

re: fclean all
