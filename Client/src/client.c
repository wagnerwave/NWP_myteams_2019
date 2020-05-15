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
    int n = 0;

    if (buffer == NULL)
        exit(84);
    while (1) {
        bzero(buffer, 1024);
        fgets(buffer, 1024, stdin);
        n = write(cli->tcp_sock, buffer, strlen(buffer));
        if (n < 0)
           printf("error writing");
    }
}