/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** game_engine.h
*/

#ifndef GAME_ENGINE_H
    #define GAME_ENGINE_H
    #include <SFML/Graphics.h>
    #include "linked_list.h"

typedef struct scene_s {
    list_t *objects;
    list_t *canvas;
} scene_t;

typedef struct time_s {
    sfClock *delta;
    sfClock *time;
} time_t;

typedef struct text_s {
    list_t *fonts;
    sfText *text;
} text_t;

typedef struct engine_s {
    list_t *scenes;
    int actual_scene;
    scene_t *const_scene;
    sfRenderWindow *window;
    sfEvent event;
    text_t text;
    sfView *view;
    list_t *print_sprites;
    list_t *addons;
    time_t time;
    list_t *functions;
} engine_t;

typedef struct entity_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *clock;
    int order;
} entity_t;

typedef struct object_s {
    sfBool isActive;
    list_t *addons;
    entity_t *entity;
} object_t;

typedef int (*event_functions_t) (object_t *, engine_t *);

typedef struct addon_s {
    void *data;
    event_functions_t on_enable;
    event_functions_t on_disable;
    event_functions_t on_tick;
    event_functions_t event_manager;
    event_functions_t on_scene_loaded;
} addon_t;

#endif
