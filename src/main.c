/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** main.c
*/

#include "../include/game_engine.h"

int addon_on_disable(object_t *object, engine_t *engine)
{
    change_scene("scene1", engine);
    return 0;
}

int addon_event_manager(object_t *object, engine_t *engine)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(engine->window);
    sfFloatRect position = sfSprite_getLocalBounds(object->entity->sprite);

    if (sfFloatRect_contains(&position, mouse.x, mouse.y) == sfTrue) {
        add_function(addon_on_disable, 10000, object, engine);
    }
    char *string = get_addon("lol", 4, object);
    print_text(string, (sfVector2f) {200, 200}, 5, engine);
    return 0;
}

addon_t *init_addon()
{
    addon_t *addon = malloc(sizeof(addon_t));

    addon->on_enable = NULL;
    addon->on_disable = addon_on_disable;
    addon->on_tick = addon_event_manager;
    addon->event_manager = NULL;
    addon->on_scene_loaded = NULL;
    return addon;
}

int main(int argc, char **argv)
{
    list_t *scene = launch_parsing("./src/json/scene.json");
    list_t *scene1 = launch_parsing("./src/json/scene1.json");
    engine_t *engine = init_game((sfVideoMode) {1980, 1080, 32}, "bonjour");
    create_addon("base", init_addon(), engine);
    init_scene_by_list(scene, sfFalse, engine);
    init_scene_by_list(scene1, sfTrue, engine);
    add_font("./img/outfit.ttf", "outfit", engine);
    change_font("outfit", engine);
    sfText_setCharacterSize(engine->text.text, 25);
    sfText_setColor(engine->text.text, sfBlack);
    change_scene("scene1", engine);
    return open_game(engine, 60);
}