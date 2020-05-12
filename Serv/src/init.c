/*
** EPITECH PROJECT, 2020
** server teams
** File description:
** init struct of server
*/

#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include "server.h"

static void init_client_func(client_t *cli)
{
    cli->fd = -1;
    cli->group_fd = 0;
    cli->user.username = NULL;
}

void default_init_client(client_t **cli)
{
    for (int i = 0; i < FD_SETSIZE; i++) {
        cli[i] = calloc(1, sizeof(client_t));
        if (cli[i] == NULL)
            exit(84);
        init_client_func(cli[i]);
    }
}

void init_client(client_t *cli, int sock, fd_set *acv_grpfd)
{
    cli->fd = sock;
    cli->group_fd = acv_grpfd;
}

void init_server(server_t *srv, unsigned short port)
{
    int opt = 1;

    srv->port = port;
    srv->tcp_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (srv->tcp_sock < 0)
        exit(84);
    srv->sin.sin_family = AF_INET;
    srv->sin.sin_addr.s_addr = htonl(INADDR_ANY);
    srv->sin.sin_port = htons(port);
    setsockopt(srv->tcp_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    if (bind(srv->tcp_sock, (struct sockaddr *)&(srv->sin),
        sizeof(srv->sin)) < 0)
        exit(84);
    if (listen(srv->tcp_sock, MAX_CONNECTION_SERVER) < 0)
        exit(84);
}
