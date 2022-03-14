##
## EPITECH PROJECT, 2021
## BistroMatic
## File description:
## Makefile
##

SRC	=	json_parser.c						\
		get_buffer.c						\
		stringify.c							\
		get_data.c							\
		get_key.c							\
		type_checkers/check_type.c			\
		type_checkers/check_array.c			\
		type_checkers/check_object.c		\
		type_checkers/check_double.c		\
		type_checkers/check_int.c			\
		type_checkers/check_string.c		\
		value_getters/get_value.c			\
		value_getters/get_array.c			\
		value_getters/get_object.c			\
		value_getters/get_double.c			\
		value_getters/get_int.c				\
		value_getters/get_string.c

OBJ	=	$(SRC:.c=.o)

CFLAGS = -I../../include -Wall -Wextra -pedantic

LFLAGS =	-L./lib -llist

NAME	=	libjson_parser.a

#------------------------------

all:	$(NAME)

$(NAME): $(OBJ)
	ar -ro $(NAME) $(OBJ)
	cp $(NAME) ./../

clean:
	rm	-f $(OBJ)

fclean: clean
	rm	-f $(NAME)
	rm	-f ../$(NAME)

re: fclean all

.PHONY: re fclean clean fclean_lib clean_lib build build_lib all
