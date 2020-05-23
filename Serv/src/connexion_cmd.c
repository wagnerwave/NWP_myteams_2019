/*
** EPITECH PROJECT, 2020
** teams server
** File description:
** function for connexion on the server
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "logging_server.h"
#include "server.h"

static void connect_client(client_t *cli, user_t *tmp)
{
    cli->user.connected = true;
    uuid_copy(cli->user.user_id, tmp->user_id);
    cli->user.username = strdup(tmp->username);
    server_event_user_loaded(uuid_to_str(cli->user.user_id),
    cli->user.username);
    dprintf(cli->fd, "Client connect [%s:%s]\n",
    uuid_to_str(cli->user.user_id), cli->user.username);
}

static void create_client_user(client_t *cli, char *username)
{
    cli->user.username = strdup(username);
    cli->user.connected = true;
    uuid_generate(cli->user.user_id);
    server_event_user_created(uuid_to_str(cli->user.user_id), username);
    dprintf(cli->fd, "Client connect [%s:%s]\n",
    uuid_to_str(cli->user.user_id), cli->user.username);
    write_user_to_db(uuid_to_str(cli->user.user_id), cli->user.username);
}

void login(client_t **cli, int nb, char **txt)
{
    user_t tmp = {NULL, 0, false};
    char *username = NULL;

    if (!txt[1])
        return;
    username = txt[1];
    if (strlen(username) > 32)
        return;
    compare_username_with_db(&tmp ,username);
    if (tmp.username == NULL)
        create_client_user(cli[nb], username);
    else
        connect_client(cli[nb], &tmp);
}

void logout(client_t **cli, int nb, char **txt)
{
    (void)txt;
    server_event_user_logged_out(uuid_to_str(cli[nb]->user.user_id));
    dprintf(cli[nb]->fd, "Client logged out [%s:%s]\n",
    cli[nb]->user.user_id, cli[nb]->user.username);
    cli[nb]->user.connected = false;
    close(cli[nb]->fd);
    FD_CLR(cli[nb]->fd, cli[nb]->group_fd);
}
