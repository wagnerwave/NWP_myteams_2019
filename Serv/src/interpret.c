/*
** EPITECH PROJECT, 2020
** teams server
** File description:
** Interpret user input
*/

#include "server.h"

void interpert_client_input(client_t *cli, char *input)
{
    printf("SERVER GET : %s\n", input);
    write(cli->fd, "WE GET THE MSG\n", 17);
}