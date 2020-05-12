/*
** EPITECH PROJECT, 2020
** teams client
** File description:
** client for teams
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "client.h"

void client_run(client_t *cli)
{
    size_t size = 1024;
    char *buffer = malloc(sizeof(char) * size);

    while (1) {
        getline(&buffer, &size, stdin);
        write(cli->tcp_sock, buffer, strlen(buffer));
    }
}
