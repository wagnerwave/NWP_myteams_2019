#include <stdio.h>
#include <unistd.h>
#include <sys/queue.h>
#include <stdlib.h>

/****   STRUCTURE   ****/

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

/****   FUNCTION    ****/

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

void main(void)
{
    vector_t *list = vector_create();
    vector_push_back(list, strdup("1"));
    vector_push_back(list, strdup("2"));
    vector_push_back(list, strdup("3"));
    vector_push_back(list, strdup("4"));
    vector_push_back(list, strdup("5"));
    vector_push_back(list, strdup("6"));
    
    for (node_t *i = list->start; i ; i = i->next)
        printf("%s\n", (char*)i->content);

    printf("\n\n");
    
    for (node_t *i = list->end; i; i = i->prev)
        printf("%s\n", (char*)i->content);
}