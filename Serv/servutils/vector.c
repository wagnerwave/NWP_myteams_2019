/*
** EPITECH PROJECT, 2020
** vector.c
** File description:
** teams utils
*/

#include "vector.h"

node_t *node_create(void *content)
{
    node_t *new = malloc(sizeof(node_t)); 
    new->next = NULL;
    new->prev = NULL;
    new->content = content;
    return new;
}

void node_push_after(node_t *node, void *content) 
{
    node_t *new = node_create(content);
    node_t *tmp = NULL;

    if (!node->next) {
        node->next = new;
        new->prev = node;
    }
    else {
        tmp = node->next;
        node->next = new;
        new->next = tmp;
        tmp->prev = new;
        new->prev = node;
    }
}

void node_push_before(node_t **node, void *content)
{
    node_t *new = node_create(content);
    node_t *tmp = NULL;

    if (!(*node)->prev) {
        new->next = *node;
        (*node)->prev = new;
    }
    else {
        tmp = (*node)->prev;
        new->next = *node;
        tmp->next = new;
        new->prev = tmp;
        (*node)->prev = new;
    }
    *node = new;
}

void node_pop_me(node_t *node)
{
    if (node->next && node->prev) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        free(node);
    }
    else if (node->next) {
        node->next->prev = NULL; 
        free(node);
    }
    else if (node->prev) {
        node->prev->next = NULL;
        free(node);
    }
    else
        free(node);
}

vector_t *vector_create(void)
{
    vector_t *new = malloc(sizeof(vector_t));
    new->start = NULL;
    new->end = NULL;
    new->size = 0;
    return new;
}

void vector_push_back(vector_t *vector, void *content)
{
    if (!vector->start) {
        vector->start = node_create(content);
        vector->end = vector->start;
    }
    else {
        node_push_after(vector->end, content);
        vector->end = vector->end->next;
    }
    vector->size++;
}

void vector_push_head(vector_t *vector, void *content)
{
    if (!vector->start) {
        vector->start = node_create(content);
        vector->end = vector->start;
    }
    else
        node_push_before(&(vector)->start, content);
    vector->size++;
}

void vector_pop_me(vector_t *vector, node_t *node)
{
    if (node == vector->start) {
        vector->start = vector->start->next;
        node_pop_me(node);
    }
    else if (node == vector->end) {
        vector->end = vector->end->prev;
        node_pop_me(node);
    }
    else if (node == vector->end && node == vector->start){
        node_pop_me(node);
        vector->end = NULL;
        vector->start = NULL;
    }
    vector->size--;
}

void vector_pop_head(vector_t *vector) 
{
    vector_pop_me(vector, vector->start);
}

void vector_pop_back(vector_t *vector)
{
    vector_pop_me(vector, vector->end);
}