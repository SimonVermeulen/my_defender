/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** game_engine.h
*/

#ifndef GAME_ENGINE_H
    #define GAME_ENGINE_H
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include "linked_list.h"
    #include "json_parser.h"
    #define ERROR 84

typedef struct times_s {
    sfClock *delta;
    sfClock *time;
} times_t;

typedef struct engine_s {
    list_t *scenes;
    list_t *actual_scene;
    list_t *prev_scene;
    list_t *const_scene;
    sfRenderWindow *window;
    sfEvent event;
    list_t *fonts;
    list_t *print;
    sfView *view;
    list_t *addons;
    times_t time;
    list_t *functions;
    int code;
} engine_t;

typedef struct entity_s {
    sfSprite *sprite;
    sfTexture *texture;
    int order;
} entity_t;

typedef struct object_s {
    sfBool is_pause;
    sfBool is_active;
    sfClock *clock;
    list_t *addons;
    list_t *addons_data;
    entity_t *entity;
    list_t *actual_scene;
    const char *name;
    list_t *childs;
    struct object_s *parent;
} object_t;

typedef int (*event_functions_t) (object_t *, engine_t *);

typedef struct addon_s {
    void *data;
    event_functions_t on_tick;
    event_functions_t on_event;
    event_functions_t on_enable;
    event_functions_t on_disable;
    event_functions_t on_start;
    event_functions_t on_end;
} addon_t;

engine_t *init_game(sfVideoMode video, char const *title);
int execute_game(list_t *scene, engine_t *engine);
int open_game(engine_t *engine, int fps);
int destroy_game(engine_t *engine);

void *get_addon(char const *name, int type, object_t *object);
sfBool create_addon(char const *name, addon_t *addon, engine_t *engine);
sfBool add_addon(char const *name, object_t *object, engine_t *engine);
sfBool destroy_addons(list_t *addon, sfBool boolean);

int on_end(list_t *scene, engine_t *engine);
int on_start(list_t *scene, engine_t *engine);

typedef list_t *(*init_scene_function_t) (engine_t *);

typedef struct primitive_scene_s {
    init_scene_function_t init;
} primitive_scene_t;

int init_primitive_scene(engine_t *engine, init_scene_function_t init,
    const char *name);
int change_scene(char const *name, engine_t *engine);
list_t *init_scene_by_list(list_t *scene, engine_t *engine, object_t *parent);
int destroy_scene(list_t *scene);

typedef struct print_node_s {
    void *data;
    int type;
    int order;
} print_node_t;

int print_list(engine_t *engine);
sfBool add_print(void *data, int type, int order, engine_t *engine);
int destroy_print_list(engine_t *engine, sfBool final);

sfBool add_font(char const *font, char const *name, engine_t *engine);
sfFont *get_font(char const *name, engine_t *engine);
int destroy_fonts(engine_t *engine);

object_t *create_object(char const *name, list_t *scene);
object_t *create_object_list(list_t *list, list_t *scene, engine_t *engine,
    object_t *parent);
int destroy_object(object_t *object);
object_t *seach_object(engine_t *engine, char const *name);
object_t *seek_object_scene(list_t *scene, char const *name);
sfBool set_active(sfBool value, object_t *object, engine_t *engine);
object_t **stock_object(object_t *object);

int init_entity(int order, char const *texture, object_t *object);
int init_entity_by_list(list_t *entity_list, object_t *object);
int print_entity(object_t *object, engine_t *engine);
int destroy_entity(object_t *object);
int change_texture(object_t *object, char const *path);

typedef struct execute_function_s {
    float time;
    event_functions_t function;
    object_t *object;
} execute_function_t;

sfBool add_function(event_functions_t function, float time, object_t *object,
    engine_t *engine);
int execute_functions(engine_t *engine);
int destroy_functions(engine_t *engine);

float get_delta(engine_t *engine);
int set_time(engine_t *engine);
int exit_game(engine_t *engine, int code);

sfVector2f get_mouse_position(engine_t *engine);

#endif
