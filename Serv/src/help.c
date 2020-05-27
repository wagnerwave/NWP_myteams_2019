/*
** EPITECH PROJECT, 2020
** teams server
** File description:
** help
*/

#include <stdio.h>
#include "server.h"

void display_help(char *nameprog)
{
    printf("USAGE: %s port\n\n", nameprog);
    printf("\tport is the port number on which the server socket listens.\n");
}

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