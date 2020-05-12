/*
** EPITECH PROJECT, 2020
** teams client
** File description:
** init for teams
*/

#include <arpa/inet.h>
#include <stdlib.h>
#include "client.h"

void init_client(client_t *cli, const char *ip, unsigned short port)
{
    int size_sin = 0;

    cli->ip = ip;
    cli->port = port;
    cli->tcp_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (cli->tcp_sock == -1) {
        printf("fail to tcp_sock\n");
        exit(84);
    }
    cli->sin.sin_family = AF_INET;
    cli->sin.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &cli->sin.sin_addr) <= 0) {
        printf("fail to inet_pton\n");
        exit(84);
    }
    size_sin = sizeof(cli->sin);
    if (connect(cli->tcp_sock, (struct sockaddr *)&cli->sin, size_sin) == -1) {
        printf("fail to connect\n");
        exit(84);
    }
}