#include <stdio.h>
#include <unistd.h>
#include <sys/queue.h>
#include <stdlib.h>
#include <string.h>

/* typedef struct channel_s {
    int id;
    char name[15];
    struct channel_s *next;
} channel_t; */

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

typedef struct channel_s {
    int id;
    char *name;
    //vector_t *threads_list;
} channel_t;

typedef struct team_s {
    int id;
    char *name;
    vector_t *channels_list;
} team_t;

/****   STRUCTURE   ****/



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

team_t *new_team(char *name, int id)
{
    team_t *t = malloc(sizeof(team_t));
  //  if (t->id = malloc(sizeof(int)))
        t->id = id;
    if (t->name = malloc(32))
        t->name = strdup(name);
    t->channels_list = vector_create();
    return t;
}

channel_t *new_channel(char *name, int id)
{
    channel_t *c = malloc(sizeof(channel_t));
    //if (c->id = malloc(sizeof(float)))
        c->id = id;
    if (c->name = malloc(32))
        c->name = strdup(name);
   // c->threads_list = vector_create();
    return c;
}

char *team_get_name(team_t *t) 
{
    return strdup(t->name);
}

int team_get_id(team_t *t)
{
    return (t->id);
}

node_t *team_get_channels(team_t *t)
{
    return (t->channels_list->start);
}
//////////////////////////////////////
////// CHANNELS FUNCS

char *channel_get_name(channel_t *c)
{
    return strdup(c->name);
}

int channel_get_id(channel_t *c)
{
    return (c->id);
}
///////////////////////////////////////
void main(void)
{
    vector_t *list = vector_create();
    
    team_t *t = new_team("macron", 84);
    channel_t *c = new_channel("elysée", 2077);
    channel_t *c1 = new_channel("matignon", 49.3);

    team_t *t1 = new_team("josé bové", 66);
    channel_t *d = new_channel("prolétariat", 01);
    channel_t *d1 = new_channel("le bistrot", 51);

    team_t *t2 = new_team("l'ami demeuré", 23);
    channel_t *e = new_channel("neutralité", 01);
    channel_t *e1 = new_channel("centrisme", 0);

    vector_push_back(list, t);
    vector_push_back(t->channels_list, c);
    vector_push_back(t->channels_list, c1);

    vector_push_back(list, t1);
    vector_push_back(t1->channels_list, d);
    vector_push_back(t1->channels_list, d1);

    vector_push_back(list, t2);
    vector_push_back(t2->channels_list, e);
    vector_push_back(t2->channels_list, e1);

    for (node_t *i = list->start; i; i = i->next) {
        printf("\tteams:\n");
        printf("\t>>>>>> name:\t%s\n", team_get_name(i->content));
        printf("\t>>>>>> id:\t%d\n", team_get_id(i->content));
        printf("\t\tchannels:\n");
        for (node_t *j = team_get_channels(i->content); j; j = j->next) {
            printf("\t\t>>>>>>>>> name : %s\n", channel_get_name(j->content));
            printf("\t\t>>>>>>>>> id : %d\n", channel_get_id(j->content));
        }
    }
}