/*
** EPITECH PROJECT, 2020
** teams client
** File description:
** client for teams
*/

#include <unistd.h>
#include <string.h>
#include "client.h"

void client_run(client_t *cli)
{
    char *input = NULL;

    while (1) {
        input = get_next_line(cli->tcp_sock);
        if (input == NULL)
            return;
            write(cli->tcp_sock, input, strlen(input));
    }
}
