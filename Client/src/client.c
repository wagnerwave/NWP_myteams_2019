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
    char *buffer = malloc(sizeof(char) * 1024);

    if (buffer == NULL)
        exit(84);
    while (1) {
        bzero(buffer, strlen(buffer));
        for (int i = 0; (buffer[i] = getchar()) != '\n'; i++);
        write(cli->tcp_sock, buffer, strlen(buffer));
        bzero(buffer, strlen(buffer));
    }
}
