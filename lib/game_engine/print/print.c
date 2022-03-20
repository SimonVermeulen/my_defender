/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** print.c
*/

#include "game_engine.h"

void switch_element_sort_print(node_t *i, node_t *j)
{
    print_node_t *temp_a = i->value;
    print_node_t *temp_b = j->value;

    if (temp_a->order < temp_b->order) {
        i->value = temp_b;
        j->value = temp_a;
    }
}

void make_bubble_sort_print(list_t *stack)
{
    node_t *traveler_a = stack->head;
    node_t *traveler_b = stack->head;

    for (int i = 0; i < stack->nb_elements;
        i++, traveler_a = traveler_a->next) {
        for (int j = 0; j < stack->nb_elements; j++, traveler_b =
            traveler_b->next)
            switch_element_sort_print(traveler_a, traveler_b);
        traveler_b = stack->head;
    }
}

void print_type(print_node_t *node, sfRenderWindow *win)
{
    switch (node->type) {
        case 0:
            sfRenderWindow_drawSprite(win, node->data, NULL);
            break;
        case 1:
            sfRenderWindow_drawText(win, node->data, NULL);
            break;
    }
}

int print_list(engine_t *engine)
{
    node_t *current = NULL;
    print_node_t *print_node = NULL;

    make_bubble_sort_print(engine->print);
    current = engine->print->head;
    for (int i = 0; i < engine->print->nb_elements; i++,
        current = current->next) {
        print_node = current->value;
        print_type(print_node, engine->window);
    }
    return destroy_print_list(engine, sfFalse);
}

sfBool add_print(void *data, int type, int order, engine_t *engine)
{
    print_node_t *print_node = malloc(sizeof(print_node_t));
    node_t *node = malloc(sizeof(node_t));

    if (print_node == NULL || node == NULL)
        return sfFalse;
    print_node->data = data;
    print_node->type = type;
    print_node->order = order;
    node->value = print_node;
    node->key = NULL;
    node->len = 0;
    push_element(engine->print, node);
    return sfTrue;
}

int destroy_print_list(engine_t *engine, sfBool final)
{
    if (engine == NULL)
        return ERROR;
    while (engine->print->nb_elements != 0) {
        free(engine->print->head->value);
        engine->print->head->key = NULL;
        engine->print->head->value = NULL;
        shift_element(engine->print);
    }
    if (final == sfTrue)
        free(engine->print);
    return 0;
}
