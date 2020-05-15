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
    (void)txt;
    for (size_t i = 0; cmd[i].name != NULL; i++)
        dprintf(cli[nb]->fd,"%s %s\n", cmd[i].name, cmd[i].desc);
}