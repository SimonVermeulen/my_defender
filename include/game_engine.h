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
    #define ERROR 84

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

engine_t *init_game(sfVideoMode *video, char const *title);
int open_game(engine_t *engine, int fps);
sfBool change_scene(char const *name, engine_t *engine);
int destroy_game(engine_t *engine);
int init_text(engine_t *engine);
sfBool add_font(char const *font, engine_t *engine);
sfBool print_text(char const *text, sfVector2f position, engine_t *engine);
sfBool change_font(char const *name, engine_t *engine);
int destroy_text(engine_t *engine);
int init_scene(char const *name, sfBool const_scene, engine_t *engine);
int init_scene_by_list(list_t *object, sfBool const_scene, engine_t *engine);
int destroy_scene(scene_t *scene, engine_t *engine);
int create_object(char const *name, engine_t *engine);
int create_object_by_list(list_t *object, engine_t *engine);
int destroy_object(object_t *object, engine_t *engine);
int init_entity(char const *texture, object_t *object);
int destroy_entity(object_t *object);
sfBool set_active(sfBool value, object_t *object, engine_t *engine);
sfBool add_function(event_functions_t functions, float time);
float get_delta(engine_t *engine);

#endif
