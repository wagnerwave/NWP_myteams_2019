/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** threads
*/
#include "server.h"

thread_t *new_thread(char *title, char *body, uuid_t author)
{
    thread_t *t = malloc(sizeof(thread_t));

    uuid_generate(t->id);
    if ((strlen(title) + strlen(body)) <= MAX_NAME_LENGTH + MAX_DESCRIPTION_LENGTH ) {
        strcpy(t->title, title);
        strcpy(t->author_id, itoa(author));
        strcpy(t->body, body);
    }
    t->comments_list = vector_create();
    return t;
}

char *thread_get_title(thread_t *thread) 
{
    return (thread->title);
}

time_t thread_get_timestamp(thread_t *thread) 
{
    return (thread->timestamp);
}

char *thread_get_body(thread_t *thread) 
{
    return (thread->body);
}

char *thread_get_title(thread_t *thread) 
{
    return (thread->title);
}

char *thread_get_id(thread_t *thread)
{
    return (thread->id);
}

vector_t *thread_get_comments(thread_t *thread)
{
    return (thread->comments_list);
}