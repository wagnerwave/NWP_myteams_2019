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
////////////////////////////
typedef struct thread_s {
    int id;
    char *title;
} thread_t;

typedef struct channel_s {
    int id;
    char *name;
    vector_t *threads_list;
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
    t->id = id;
    if (t->name = malloc(32))
        t->name = strdup(name);
    t->channels_list = vector_create();
    return t;
}

channel_t *new_channel(char *name, int id)
{
    channel_t *c = malloc(sizeof(channel_t));
    c->id = id;
    if (c->name = malloc(strlen(strdup(name))))
        c->name = strdup(name);
    c->threads_list = vector_create();
    return c;
}

thread_t *new_thread(char *title, int id)
{
    thread_t *thread = malloc(sizeof(channel_t));
    thread->id = id;
    if (thread->title = malloc(strlen(strdup(title))))
        thread->title = strdup(title);
    //thread->comments_list = vector_create();
    return thread;
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

node_t *channel_get_threads(channel_t *chan)
{
    return (chan->threads_list->start);
}

void team_set_name(team_t *t, char *name)
{
    t->name = strdup(name);
}

void team_set_id(team_t *t, int id)
{
    t->id = id;
}
//////////////////////////////////////
////// CHANNELS FUNCS

char *channel_get_name(channel_t *chan)
{
    return strdup(chan->name);
}

void channel_set_name(channel_t *chan, char *name)
{
    chan->name = strdup(name);
}

void channel_set_id(channel_t *chan, int id)
{
    chan->id = id;
}

int channel_get_id(channel_t *chan)
{
    return (chan->id);
}
///////////////////////////////////////
//////// THREADS FUNCS

char *thread_get_title(thread_t *thread) 
{
    return (thread->title);
}

int thread_get_id(thread_t *thread)
{
    return (thread->id);
}
///////////////////////////////////////
void main(void)
{
    vector_t *server = vector_create();
    
    team_t *t = new_team("macron", 100);
    channel_t *c = new_channel("#elysée", 10000);
    channel_t *c1 = new_channel("#matignon", 10001);
    thread_t *lundi = new_thread("OUUUIIIII AVEC MES AMIS", 1000001);
    thread_t *monday = new_thread("LE MECHANT CORONA", 1000002);

    team_t *t1 = new_team("josé bové", 200);
    channel_t *d = new_channel("#prolétariat", 20001);
    channel_t *d1 = new_channel("#le_bistrot", 20002);
    thread_t *mardi = new_thread("C'EST LA LUTTE FINALE!!", 2000002);
    thread_t *tuesday = new_thread("C'EST QUI CELLE LA ?!", 2000009);

    team_t *t2 = new_team("l'ami demeuré", 300);
    channel_t *e = new_channel("#neutralité ", 30003);
    channel_t *e1 = new_channel("#centrisme",  30004);
    thread_t *mercredi = new_thread("LES DEMEURES VAINCRONT",  3000005);
    thread_t *wednesday = new_thread("RESTEZ CHEZ VOUS",  3000008);

    vector_push_back(server, t);
    vector_push_back(t->channels_list, c);
    vector_push_back(t->channels_list, c1);
    vector_push_back(c->threads_list, lundi);
    vector_push_back(c->threads_list, monday);
    vector_push_back(c1->threads_list, monday);

    vector_push_back(server, t1);
    vector_push_back(t1->channels_list, d);
    vector_push_back(t1->channels_list, d1);
    vector_push_back(d->threads_list, mardi);
    vector_push_back(d1->threads_list, tuesday);

    vector_push_back(server, t2);
    vector_push_back(t2->channels_list, e);
    vector_push_back(t2->channels_list, e1);
    vector_push_back(e->threads_list, mercredi);
    vector_push_back(e1->threads_list, wednesday);

    printf("teams:\n");
    for (node_t *i = server->start; i; i = i->next) {
        printf("\tname:\t%s\n", team_get_name(i->content));
        printf("\tid:\t%d\n", team_get_id(i->content));
        printf("\t\tchannels:\n");
        
        for (node_t *j = team_get_channels(i->content); j; j = j->next)
        {
            printf("\t\t\tchan name : %s\n", channel_get_name(j->content));
            printf("\t\t\tid : %d\n", channel_get_id(j->content));
            printf("\t\t\tthreads:\n");
            for (node_t *k = channel_get_threads(j->content); k; k = k->next)
            {   
                printf("\t\t\t\tid : %d\n", thread_get_id(k->content));
                printf("\t\t\t\tthread name : %s\n\n", thread_get_title(k->content));
            }
        }
    }
}