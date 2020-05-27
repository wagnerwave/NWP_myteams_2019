/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** user cmd
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"

static void send_users_info(client_t **cli, int usr, char *username, char *uid)
{
    int connected = 0;

    for (size_t i = 0; i < FD_SETSIZE; i++) {
        if (cli[i]->user.username == NULL)
            continue;
        if (strcmp(cli[i]->user.username, username) == 0)
            if (cli[i]->user.connected == true) {
                connected = 1;
                break;
            }
    }
    dprintf(cli[usr]->fd, "008 Users info [%s:%s:%d]\n", username, uid, connected);
}

void user(client_t **cli, int nb, char **txt)
{
    char *uuid = NULL;
    user_t tmp;

    if (!cli[nb]->user.connected) {
        dprintf(cli[nb]->fd, "Error: please login.\n");
        return;
    }
    if ((uuid = get_info_to_str(txt[1])) == NULL)
        return;
    compare_uuid_with_db(&tmp, uuid);
    if (tmp.username == NULL)
        return;
    send_users_info(cli, nb, tmp.username, uuid_to_str(tmp.user_id));
}