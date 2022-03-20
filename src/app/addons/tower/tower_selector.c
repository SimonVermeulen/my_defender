/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** tower_build
*/

#include "game.h"

int event_tower_selector(object_t *object, engine_t *engine)
{
    double *position_x = get_addon("PositionX", 2, object);
    double *position_y = get_addon("PositionY", 2, object);
    object_t *selector = seek_object_scene(object->childs, "BuildSelector");
    sfFloatRect rect = (sfFloatRect) {(*position_x - 50), (*position_y - 50),
        100, 100};
    sfVector2f mouse = get_mouse_position(engine);

    if (engine->event.type == sfEvtMouseButtonPressed
        && engine->event.mouseButton.button == sfMouseLeft &&
        sfFloatRect_contains(&rect, mouse.x, mouse.y) == sfTrue) {
        set_active(sfTrue, selector, engine);
    }
}
