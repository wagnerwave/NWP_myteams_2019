/*
** EPITECH PROJECT, 2020
** teams server
** File description:
** command who display informations
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"

void help(client_t **cli, int nb, char **txt)
{
    if (!cli[nb]->user.connected) {
        dprintf(cli[nb]->fd, "Error: please login.\n");
        return;
    }
    (void)txt;
    dprintf(cli[nb]->fd, "$ 420 help display list of commands\n");
    for (size_t i = 0; cmd[i].name != NULL; i++)
        dprintf(cli[nb]->fd, "%s %s\n\0", cmd[i].name, cmd[i].desc);
}

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

static void display_user_by_db(client_t **cli, int nb)
{
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    int line_size = 0;
    char *uid = NULL;
    char *username = NULL;
    char *delim = ":\n";
    FILE *fp = fopen(USER_DB, "r");

    if (!fp)
        exit(84);
    while (line_size != -1) {
        line_size = getline(&line_buf, &line_buf_size, fp);
        uid = strtok(line_buf, delim);
        if (uid == NULL)
            break;
        username = strtok(NULL, delim);
        if (username == NULL)
            break;
       send_users_info(cli, nb, username, uid);
    }
    fclose(fp);
}

void users(client_t **cli, int nb, char **txt)
{
    (void)txt;
    if (!cli[nb]->user.connected) {
        dprintf(cli[nb]->fd, "Error: please login.\n");
        return;
    }
    display_user_by_db(cli, nb);
}