/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** open_game.c
*/

#include "game_engine.h"

int window_on_scene_loaded(list_t *scene, engine_t *engine);
int window_on_tick(list_t *scene, engine_t *engine);
int window_event_manager(list_t *scene, engine_t *engine);
int window_on_scene_loaded(list_t *scene, engine_t *engine);

int core_game(engine_t *engine)
{
    int code = 0;
    int (*event[])(list_t *, engine_t *) = {&window_on_scene_loaded,
        &window_on_tick, &window_event_manager, NULL};
    
    for (int i = 0; event[i] != NULL; i++) {
        code += (*event[i])(engine->actual_scene->objects, engine);
        code += (*event[i])(engine->actual_scene->canvas, engine);
        code += (*event[i])(engine->const_scene->objects, engine);
        code += (*event[i])(engine->const_scene->canvas, engine);
        if (code != 0)
            return 1;
    }
    execute_functions(engine);
    print_list(engine);
    return 0;
}

int open_game(engine_t *engine, int fps)
{
    if (engine == NULL || set_time(engine) == 84)
        return ERROR;
    sfRenderWindow_setView(engine->window, engine->view);
    sfRenderWindow_setFramerateLimit(engine->window, fps);
    while (sfRenderWindow_isOpen(engine->window)) {
        sfRenderWindow_clear(engine->window, sfBlack);
        core_game(engine);
        sfRenderWindow_display(engine->window);
        sfClock_restart(engine->time.delta);
    }
    sfClock_destroy(engine->time.delta);
    sfClock_destroy(engine->time.time);
    destroy_game(engine);
    return 0;
}