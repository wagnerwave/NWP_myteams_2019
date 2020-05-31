/*
** EPITECH PROJECT, 2020
** vector.h
** File description:
** teams utils
*/

#ifndef VECTOR_H_
#define VECTOR_H_

#include <unistd.h>

typedef struct node_s {
    void *content;
    struct node_s *next;
    struct node_s *prev;
} node_t;

typedef struct vector_s {
    node_t *start;
    node_t *end;
    size_t size;
} vector_t;

node_t *node_create(void *content);
void node_push_after(node_t *node, void *content);
void node_push_before(node_t **node, void *content);
void node_pop_me(node_t *node);
vector_t *vector_create(void);
void vector_push_back(vector_t *vector, void *content);
void vector_push_head(vector_t *vector, void *content);
void vector_pop_me(vector_t *vector, node_t *node);
void vector_pop_head(vector_t *vector);
void vector_pop_back(vector_t *vector);

#endif

