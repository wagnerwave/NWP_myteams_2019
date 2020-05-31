/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** servutils
*/
#include "server.h"

static int get_dest(client_t **cli, uuid_t receiver)
{
    int i = 0;

    for (i = 0; i < 1024; i++)
        if (uuid_compare(receiver, cli[i]->user.user_id) == 0)
            break;
    return i;
}

void list_teams(server_t *serv, client_t **cli, uuid_t receiver)
{
    int dest = get_dest(cli, receiver);

    for (node_t *i = serv->teams_list->start; i ; i = i->next) {
        dprintf(cli[dest]->fd, "420 [%s:%s:%s]\n", 
            team_get_id(i->content),
            team_get_name(i->content),
            team_get_desc(i->content));
    }
}

void list_channels(team_t *team, client_t **cli, uuid_t receiver)
{
    int dest = get_dest(cli, receiver);

    for (node_t *i = team->channels_list->start; i ; i = i->next) {
        dprintf(cli[dest]->fd, "421 [%s:%s:%s]\n",
            channel_get_id(i->content),
            channel_get_name(i->content),
            channel_get_desc(i->content));
    }
}

void list_threads(channel_t *chan, client_t **cli, uuid_t receiver) 
{
    int dest = get_dest(cli, receiver);

    for (node_t *i = chan->threads_list->start; i ; i = i->next) {
        dprintf(cli[dest]->fd, "422 [%s:%s:%s:%s]\n", 
            thread_get_id(i->content),
            uuid_to_str(thread_get_author(i->content)),
            itoa((int) comment_get_timestamp(i->content)),
            thread_get_title(i->content),
            thread_get_body(i->content));
    }
}

void list_comments(thread_t *thread, client_t **cli, uuid_t receiver) 
{
    int dest = get_dest(cli, receiver);

    for (node_t *i = thread->comments_list->start; i ; i = i->next) {
        dprintf(cli[dest]->fd, "423 [%s:%s:%s]\n", 
            thread_get_id(uuid_to_str(thread->id)),
            itoa((int) comment_get_timestamp(i->content)),
            comment_get_desc(i->content));
    }
}

void print_team_infos(team_t *team, client_t **cli, uuid_t receiver)
{
    int dest = get_dest(cli, receiver);

    dprintf(cli[dest]->fd, "430 [%s:%s:%s]\n",
        team_get_id(team),
        team_get_name(team),
        team_get_desc(team));
}

void print_channel_infos(channel_t *channel, client_t **cli, uuid_t receiver)
{
    int dest = get_dest(cli, receiver);

    dprintf(cli[dest]->fd, "431 [%s:%s:%s]\n",
        channel_get_id(channel),
        channel_get_name(channel),
        channel_get_desc(channel));
}

void print_thread_infos(thread_t *thread, client_t **cli, uuid_t receiver)
{
    int dest = get_dest(cli, receiver);

    dprintf(cli[dest]->fd, "432 [%s:%s:%s]\n",
        team_get_id(thread),
        team_get_timestamp(thread),
        team_get_desc(thread));
}