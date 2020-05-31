/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** channels
*/

#include "server.h"

channel_t *new_channel(char *name, char *desc)
{
    channel_t *channel = malloc(sizeof(channel_t));

    uuid_generate(channel->id);
    if ((strlen(name) + strlen(desc)) <= MAX_NAME_LENGTH + MAX_DESCRIPTION_LENGTH){
        strcpy(channel->name, name);
        strcpy(channel->desc, desc);
    }
    channel->threads_list = vector_create();
    return channel;
}

vector_t *channel_get_threads(channel_t *channel)
{
    return (channel->threads_list);
}

char *channel_get_name(channel_t *channel)
{
    return strdup(channel->name);
}

char *channel_get_desc(channel_t *channel)
{
    return strdup(channel->desc);
}

void channel_set_name(channel_t *channel, char *name)
{
    strcpy(channel->name, name);
}

void channel_set_desc(channel_t *channel, char *desc)
{
    strcpy(channel->desc, desc);
}

char *channel_get_id(channel_t *channel)
{
    return (uuid_to_str(channel->id));
}