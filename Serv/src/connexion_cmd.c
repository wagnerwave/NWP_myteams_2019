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

static void connect_client(client_t *cli)
{
    if (cli->user.connected == true) {
        return;
    } else {
        cli->user.connected = true;
        server_event_user_loaded(uuid_to_str(cli->user.user_id), cli->user.username);
        dprintf(cli->fd, "Client connect [%s:%s]\n", uuid_to_str(cli->user.user_id), cli->user.username);
    }
}

static void create_client_user(client_t *cli, char *username)
{
    cli->user.username = strdup(username);
    cli->user.connected = true;
    uuid_generate(cli->user.user_id);
    server_event_user_created(uuid_to_str(cli->user.user_id), username);
    dprintf(cli->fd, "Client connect [%s:%s]\n", uuid_to_str(cli->user.user_id), cli->user.username);
}

void login(client_t **cli, int nb, char **txt)
{
    char *username = NULL;
    if (!txt[1])
        return;
    username = txt[1];
    if (strlen(username) > 32)
        return;
    for (int i = 0; i < FD_SETSIZE; i++) {
        if (cli[i]->user.connected == true) {
            if (strcmp(cli[i]->user.username, username) == 0) {
                connect_client(cli[i]);
                return;
            }
        }
    }
    create_client_user(cli[nb], username);
}

void logout(client_t **cli, int nb, char **txt)
{
    (void)txt;
    server_event_user_logged_out(uuid_to_str(cli[nb]->user.user_id));
    dprintf(cli[nb]->fd, "Client logged out [%s:%s]\n", cli[nb]->user.user_id, cli[nb]->user.username);
    cli[nb]->user.connected = false;
    close(cli[nb]->fd);
    FD_CLR(cli[nb]->fd, cli[nb]->group_fd);
}
