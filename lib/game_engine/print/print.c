/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** print.c
*/

#include "game_engine.h"

void switch_element_sort_print(print_node_t *i, print_node_t *j)
{
    print_node_t *temp = NULL;

    if (i->order < j->order) {
        temp = i;
        i = j;
        j = temp;
    }
}

void make_bubble_sort_print(list_t *stack)
{
    node_t *traveler_a = stack->head;
    node_t *traveler_b = stack->head;

    for (int i = 0; i < stack->nb_elements; i++, traveler_a = traveler_a->next){
        for (int j = 0; j < stack->nb_elements; j++, traveler_b =
            traveler_b->next)
            switch_element_sort(traveler_a->value, traveler_b->value);
        traveler_b = stack->head;
    }
}

int print_list(engine_t *engine)
{
    node_t *current = NULL;
    print_node_t *print_node = NULL;
    entity_t *entity = NULL;

    make_bubble_sort_print(engine->print_sprites);
    if (engine == NULL)
        return 84;
    current = engine->scenes->head;
    for (int i = 0; i < engine->scenes->nb_elements; i++,
        current = current->next) {
        print_node = current->value;
        if (print_node->print_text == NULL) {
            entity = print_node->print_entity;
            sfRenderWindow_drawSprite(engine->window, entity->sprite, NULL);
            continue;
        }
        draw_text(print_node->print_text, engine);
    }
    return destroy_print_list(engine, sfFalse);
}

sfBool add_print(print_text_t *print, entity_t *entity, int order,
    engine_t *engine)
{
    print_node_t *print_node = malloc(sizeof(print_node_t));
    node_t *node = malloc(sizeof(node_t));

    if (print_node == NULL || node == NULL)
        return sfFalse;
    print_node->print_entity = print;
    print_node->print_text = entity;
    print_node->order = order;
    node->value = print_node;
    push_element(engine->print_sprites, node);
    return sfTrue;
}

int destroy_print_list(engine_t *engine, sfBool final)
{
    node_t *node = NULL;

    if (engine == NULL)
        return ERROR;
    while (engine->print_sprites->nb_elements != 0) {
        node = engine->print_sprites->head;
        free(engine->print_sprites->head->value);
        free(engine->print_sprites->head);
    }
    if (final == sfTrue)
        free(engine->print_sprites);
    return 0;
}