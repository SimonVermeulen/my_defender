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
int load_scenes(engine_t *engine, char **name,
    init_scene_function_t *function);
int load_game(void);
int load_fonts(engine_t *engine);

list_t *init_main_menu(engine_t *engine);
list_t *init_stage_01(engine_t *engine);

int init_position_addons(engine_t *engine);
int init_hover_button_addons(engine_t *engine);
int init_click_button_addons(engine_t *engine);
int init_view_drag_addons(engine_t *engine);
int init_responsive_window_addons(engine_t *engine);
int init_tower_builder_addons(engine_t *engine);
int init_origin_addons(engine_t *engine);
int init_builder_selector_addons(engine_t *engine);
int init_valid_build_addons(engine_t *engine);
int init_tower_build_addons(engine_t *engine);

#endif /* !GAME_H_ */