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

#include <fcntl.h>


void client_run(client_t *cli)
{
    char *buffer = malloc(sizeof(char) * 1024);
    int n = 0;

    if (buffer == NULL)
        exit(84);
    while (1) {
        bzero(buffer, 255);
        fgets(buffer, 255, stdin);
        n = write(cli->tcp_sock, buffer, strlen(buffer));
        if (n < 0)
           printf("error writing");
        bzero(buffer, 255);
        n = read(cli->tcp_sock, buffer, 255);
        if (n < 0)
            printf("error reading");
        printf("server: %s\n", buffer);
    }
}