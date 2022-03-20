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
						src/app/addons/tower/tower_selector.c	\
						src/app/addons/tower/load.c	\
						src/app/addons/active/active.c	\
						src/app/addons/tower/tower_level.c	\
						src/core/random.c	\
						src/app/addons/mobs_spawner/mobs_spawner.c	\
						src/app/addons/mobs/mobs_animation.c	\
						src/app/addons/mobs/mobs_movement.c	\
						src/app/addons/tower/build_selector/print_ghost.c	\
						src/app/addons/pause/pause_button.c	\
						src/app/addons/help/help.c	\
						src/app/addons/background_sound/background_sound.c	\

OBJ 			=		$(SRC:.c=.o)

NAME 			= 		my_defender

LIBFLAG 		= 		lib/game_engine.a -Lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio lib/liblist.a lib/libjson_parser.a lib/libmy.a -lm

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

fclean:	clean
		$(MAKE) -C ./lib/game_engine fclean
		$(MAKE) -C ./lib/my fclean
		$(MAKE) -C ./lib/linked_list fclean
		$(MAKE) -C ./lib/json_parser fclean
		rm -rf $(NAME)

re: fclean all
