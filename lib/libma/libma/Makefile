##
## EPITECH PROJECT, 2021
## B-CPE-100-TLS-1-1-cpoolday10-younes1.bahri
## File description:
## Makefile
##

SRC		=		string/my_strdup.c \
				string/replace_str.c

OBJ =			$(SRC:.c=.o)

NAME = 			libma.a

all:	$(NAME)

$(NAME): 	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ../

clean:
		rm -f $(OBJ)

fclean:
		rm -rf $(NAME)
