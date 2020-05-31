/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** comments
*/
#include "server.h"

comment_t *new_comment(char *body, uuid_t author)
{
    comment_t *comment = malloc(sizeof(comment_t));

    uuid_generate(comment->id);
    if (strlen(body) <= MAX_DESCRIPTION_LENGTH) {
        strcpy(comment->author_id, itoa(author));
        strcpy(comment->body, body);
        comment->timestamp = time(NULL);
    }
    return comment;
}

time_t comment_get_timestamp(comment_t *comment) 
{
    return (comment->timestamp);
}

char *comment_get_body(comment_t *comment) 
{
    return (comment->body);
}

char *comment_get_id(comment_t *comment)
{
    return (comment->id);
}