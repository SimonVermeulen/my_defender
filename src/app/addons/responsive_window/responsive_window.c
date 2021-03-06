/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** responsive_window.c
*/

#include "game.h"

int change_view_for_responsive_window(engine_t *engine, int x, int y)
{
    sfView *view = NULL;

    sfView_setCenter(engine->view, (sfVector2f) {(x / 2), (y / 2)});
    sfView_setSize(engine->view, (sfVector2f) {x, y});
    sfRenderWindow_setView(engine->window, engine->view);
    return 0;
}

int check_resize(object_t *object, engine_t *engine, int *x, int *y)
{
    int *width = get_addon("MaxWidth", 3, object);
    int *height = get_addon("MaxHeight", 3, object);
    int *min_width = get_addon("MinWidth", 3, object);
    int *min_height = get_addon("MinHeight", 3, object);

    if (!width || !height || !min_height || !min_width)
        return exit_game(engine, 84);
    if (*x > *width || *y > *height || *x < *min_width || *y < *min_height) {
        *x = (*x > *width || *x < *min_width) ? *width : *x;
        *y = (*y > *height || *x < *min_height) ? *height : *y;
        sfRenderWindow_setSize(engine->window, (sfVector2u) {*x, *y});
    }
    return 0;
}

int event_responsive_window(object_t *object, engine_t *engine)
{
    sfFloatRect visible_area;
    int x = 0;
    int y = 0;

    if (engine->event.type == sfEvtResized) {
        x = engine->event.size.width;
        y = engine->event.size.height;
        check_resize(object, engine, &x, &y);
        change_view_for_responsive_window(engine, x, y);
    }
    return 0;
}

int init_responsive_window_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = NULL;
    addon->on_event = event_responsive_window;
    addon->on_tick = NULL;
    if (create_addon("responsive_window", addon, engine) == sfFalse)
        return 84;
    return 0;
}
