/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_
    #include "game_engine.h"

int load_addons(engine_t *engine, const int (*init_addon[])(engine_t *));
int load_scenes(engine_t *engine, const int (*load_scene[])(engine_t *));
int load_game(void);
int load_fonts(engine_t *engine);

int init_main_menu(engine_t *engine);

int init_position_addons(engine_t *engine);
int init_hover_button_addons(engine_t *engine);

#endif /* !GAME_H_ */