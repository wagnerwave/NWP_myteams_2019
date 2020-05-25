/*
** EPITECH PROJECT, 2020
** teams server
** File description:
** command who display informations
*/

#include <unistd.h>
#include <stdio.h>
#include "server.h"

void help(client_t **cli, int nb, char **txt)
{
    if (!cli[nb]->user.connected) {
        dprintf(cli[nb]->fd, "Error: please login.\n");
        return;
    }
    (void)txt;
    dprintf(cli[nb]->fd, "003 HELP, list of commands :\n");
    for (size_t i = 0; cmd[i].name != NULL; i++)
        dprintf(cli[nb]->fd, "%s %s\n", cmd[i].name, cmd[i].desc);
}

static void display_user_by_db(client_t **cli, int nb)
{
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    size_t line_size = 0;
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
        dprintf(cli[nb]->fd, "username : %s | id : %s\n", username, uid);
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
    dprintf(cli[nb]->fd, "004 Get list of all users on the domain :\n");
    display_user_by_db(cli, nb);
}