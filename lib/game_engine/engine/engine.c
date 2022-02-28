/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** engine.c
*/

#include "game_engine.h"

engine_t *init_game(sfVideoMode video, char const *title)
{
    engine_t *instance = malloc(sizeof(engine_t));

    if (instance == NULL)
        return NULL;
    instance->scenes = create_empty_list();
    instance->print_sprites = create_empty_list();
    instance->addons = create_empty_list();
    instance->functions = create_empty_list();
    instance->view = sfView_create();
    instance->window = sfRenderWindow_create(video, title,
        sfClose | sfResize, NULL);
    if (instance->scenes == NULL || instance->print_sprites == NULL ||
        instance->addons == NULL || instance->functions == NULL ||
        instance->view == NULL || instance->window == NULL ||
        instance->time.delta == NULL || instance->time.time == NULL ||
        init_text(instance) == ERROR || init_scene("const_scene", sfTrue,
        instance) == ERROR)
        return NULL;
    instance->actual_scene = 0;
    return instance;
}

int destroy_window(engine_t *engine)
{
    node_t *node = NULL;

    if (engine == NULL)
        return ERROR;
    while (engine->scenes->nb_elements != 0) {
        node = engine->scenes->head;
        destroy_scene(engine->scenes->head, engine);
        shift_element(engine->scenes);
    }
    free(engine->scenes);
    destroy_scene(engine->const_scene, engine);
    destroy_text(engine);
    destroy_addons(engine->addons);
    destroy_functions(engine->functions);
    destroy_print_list(engine);
    sfRenderWindow_destroy(engine->window);
    sfView_destroy(engine->view);
    free(engine);
    return 0;
}