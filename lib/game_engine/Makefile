##
## EPITECH PROJECT, 2022
## my_defender
## File description:
## Makefile
##

SRC	=	addon/addon.c	\
		addon/event/on_end.c	\
		addon/event/on_start.c	\
		engine/window/controller/window_on_event.c	\
		engine/window/controller/window_on_tick.c	\
		engine/window/open_game.c	\
		engine/engine.c	\
		engine/functions.c	\
		engine/time.c	\
		engine/util/get_mouse_position.c	\
		entity/entity.c	\
		object/init_object_by_list.c	\
		object/object.c	\
		object/seach_object.c	\
		print/print.c	\
		scene/init_scene/init_scene_by_list.c	\
		scene/init_scene/init_scene.c	\
		scene/scene.c	\
		text/text.c	\
		print/print_type.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS = -I../../include -Wall -Wextra -pedantic -g3

LFLAGS =	-L./lib -llibma -llist -llibjson_parser

NAME	=	game_engine.a

#------------------------------

all:	$(NAME)

$(NAME): $(OBJ)
	ar -ro $(NAME) $(OBJ)
	cp $(NAME) ../

clean:
	rm	-f $(OBJ)

fclean: clean
	rm	-f $(NAME)
	rm	-f ../$(NAME)

re: fclean all

.PHONY: re fclean clean fclean_lib clean_lib build build_lib all