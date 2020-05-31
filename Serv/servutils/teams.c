/*
** EPITECH PROJECT, 2020
** teams.h
** File description:
** teams utils
*/

#include "server.h"

team_t *new_team(char *name, char *desc)
{
    team_t *t = malloc(sizeof(team_t));

    uuid_generate(t->id);
    if ((strlen(name) + strlen(desc)) <= (MAX_NAME_LENGTH + MAX_DESCRIPTION_LENGTH)) {
        strcpy(t->name, name);
        strcpy(t->desc, desc);
    }
    t->channels_list = vector_create();
    return t;
}

char *team_get_name(team_t *t) 
{
    return (t->name);
}

char *team_get_id(team_t *t)
{
    return (uuid_to_str(t->id));
}

vector_t *team_get_channels(team_t *t)
{
    return (t->channels_list);
}

void team_set_name(team_t *t, char *name)
{
    strcpy(t->name, name);
}