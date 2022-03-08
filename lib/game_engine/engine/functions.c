/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** functions.c
*/

void splice(list_t *list, int index)
{
}

#include "game_engine.h"

sfBool add_function(event_functions_t function, float time, object_t *object, engine_t *engine)
{
    execute_function_t *execute = malloc(sizeof(execute_function_t));
    node_t *node = malloc(sizeof(node_t));

    if (execute == NULL || node == NULL || engine == NULL || object == NULL || function == NULL)
        return sfFalse;
    execute->function = function;
    execute->time = time;
    execute->object = object;
    node->value = execute;
    push_element(engine->functions, node);
    return sfTrue;
}

int execute_functions(engine_t *engine)
{
    float delta = get_delta(engine);
    node_t *node = NULL;
    execute_function_t *execute = NULL;

    if (engine == NULL)
        return ERROR;
    node = engine->functions->head;
    for (int i = 0; i < engine->functions->nb_elements; i++) {
        execute = node->value;
        execute->time -= delta;
        if (execute->time <= 0) {
            execute->function(execute->object, engine);
            free(node->value);
            node = node->prev;
            splice(engine->functions, i);
            continue;
        }
        node = node->next;
    }
    return 0;
}

int destroy_functions(engine_t *engine)
{
    node_t *node = NULL;

    if (engine == NULL)
        return ERROR;
    while (engine->functions->nb_elements != 0) {
        node = engine->functions->head;
        free(node->value);
        free(node->key);
        shift_element(engine->functions);
    }
    free(engine->functions);
    return 0;
}
