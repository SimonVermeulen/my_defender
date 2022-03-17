/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** load_game
*/

#include "game.h"

const init_scene_function_t scenes[] = {init_main_menu, init_stage_01, NULL};
const char *name_scenes[] = {"MainMenu", "Stage01", NULL};

const int (*load_addon[])(engine_t *) = {init_position_addons,
    init_hover_button_addons, init_click_button_addons,
    init_view_drag_addons, init_responsive_window_addons,
    init_origin_addons, init_tower_addons, init_build_selector_addons,
    init_build_valid_selector, NULL};

const int width = 1920;
const int height = 1080;
const int fps = 60;
const char title[] = "titre";

int load_game(void)
{
    engine_t *engine = init_game((sfVideoMode) {width, height, 32}, title);

    if (engine == NULL || load_addons(engine, load_addon) == 84 ||
        load_scenes(engine, name_scenes, scenes) == 84 ||
        load_fonts(engine) == 84)
        return 84;
    sfView_setCenter(engine->view, (sfVector2f) {(width / 2), (height / 2)});
    sfView_setSize(engine->view, (sfVector2f) {width, height});
    sfView_zoom(engine->view, 0.98);
    sfRenderWindow_setView(engine->window, engine->view);
    if (!change_scene("MainMenu", engine))
        return 84;
    return open_game(engine, fps);
}