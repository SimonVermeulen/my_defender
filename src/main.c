/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** main.c
*/

#include "../include/game_engine.h"

int addon_on_disable(object_t *object, engine_t *engine)
{
    write(1, "bonjour le s", 13);
    return 0;
}

int addon_event_manager(object_t *object, engine_t *engine)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(engine->window);
    sfFloatRect position = sfSprite_getGlobalBounds(object->entity->sprite);

    if (sfFloatRect_contains(&position, mouse.x, mouse.y) == sfTrue) {
        set_active(sfFalse, object, engine);
    }
    return 0;
}

addon_t *init_addon()
{
    addon_t *addon = malloc(sizeof(addon_t));

    addon->on_enable = NULL;
    addon->on_disable = addon_on_disable;
    addon->on_tick = NULL;
    addon->event_manager = addon_event_manager;
    addon->on_scene_loaded = NULL;
    return addon;
}

int main(int argc, char **argv)
{
    list_t *scene = launch_parsing("./src/json/scene.json");
    engine_t *engine = init_game((sfVideoMode) {1980, 1080, 32}, "bonjour");
    create_addon("base", init_addon(), engine);
    init_scene_by_list(scene, sfTrue, engine);
    return open_game(engine, 30);
}