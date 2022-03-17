##
## EPITECH PROJECT, 2021
## B-CPE-110-TLS-1-1-BSQ-younes1.bahri
## File description:
## Makefile
##

SRC				=		src/main.c	\
						src/core/addons/load_addons.c	\
						src/core/scenes/load_scenes.c	\
						src/app/load_fonts.c	\
						src/app/load_game.c	\
						src/app/scenes/main_menu/main_menu.c	\
						src/app/scenes/stage_01/stage_01.c	\
						src/app/addons/position/position.c	\
						src/app/addons/hover_button/hover_button.c	\
						src/app/addons/click_button/click_button.c	\
						src/app/addons/view_drag/view_drag.c	\
						src/app/addons/responsive_window/responsive_window.c	\
						src/app/addons/origin/origin.c	\
						src/app/addons/tower/tower.c	\
						src/app/addons/tower/build_selector/build_selector.c	\
						src/app/addons/tower/build_selector/valid.c	\

OBJ 			=		$(SRC:.c=.o)

NAME 			= 		my_defender

LIBFLAG 		= 		lib/game_engine.a -Lcsfml-window -lcsfml-graphics -lcsfml-system lib/liblist.a lib/libjson_parser.a lib/libmy.a

CFLAGS 			+= 		-I ./include -g3

all:	$(NAME)

$(NAME): 	$(OBJ)
		$(MAKE) -C ./lib/game_engine
		$(MAKE) -C ./lib/my
		$(MAKE) -C ./lib/linked_list
		$(MAKE) -C ./lib/json_parser
		$(CC) -o $(NAME) $(OBJ) $(LIBFLAG)

clean:
		$(MAKE) -C ./lib/game_engine clean
		$(MAKE) -C ./lib/my clean
		$(MAKE) -C ./lib/linked_list clean
		$(MAKE) -C ./lib/json_parser clean
		rm -f $(OBJ)

fclean:
		$(MAKE) -C ./lib/game_engine fclean
		$(MAKE) -C ./lib/my fclean
		$(MAKE) -C ./lib/linked_list fclean
		$(MAKE) -C ./lib/json_parser fclean
		rm -rf $(NAME)

re: fclean all