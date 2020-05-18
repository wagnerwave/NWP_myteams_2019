/*
** EPITECH PROJECT, 2020
** server teams
** File description:
** server teams
*/

#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "server.h"

static void client_management(client_t **cli, int nb)
{
    char *input = NULL;

    input = get_next_line(cli[nb]->fd);
    if (input == NULL) {
        close(cli[nb]->fd);
        FD_CLR(cli[nb]->fd, cli[nb]->group_fd);
        return;
    }
    interpert_client_input(cli, nb ,input);
}

static void connection_client(int sock, fd_set *activ_group_fd) {
    struct sockaddr_in client;
    socklen_t addr_size = sizeof(client);
    int new_tcp_socket = 0;

    new_tcp_socket = accept(sock, (struct sockaddr *) &client, &addr_size);
    if (new_tcp_socket < 0)
        exit(84);
    FD_SET(new_tcp_socket, activ_group_fd);
}

static void in_the_socket(server_t *srv, client_t **cli, int nb) {
    if (cli[nb]->fd == srv->tcp_sock) {
        connection_client(srv->tcp_sock, cli[nb]->group_fd);
    } else {
        client_management(cli, nb);
    }
}

void teams_server(server_t *srv) {
    client_t **cli = malloc(sizeof(client_t * ) * (FD_SETSIZE + 1));
    fd_set activ_group_fd;
    fd_set read_group_fd;

    if (cli == NULL)
        exit(84);
    default_init_client(cli);
    FD_ZERO(&activ_group_fd);
    FD_SET(srv->tcp_sock, &activ_group_fd);
    while (1) {
        read_group_fd = activ_group_fd;
        if (select(FD_SETSIZE, &read_group_fd, NULL, NULL, NULL) < 0)
            exit(84);
        for (int i = 0; i < FD_SETSIZE; i++) {
            init_client(cli[i], i, &activ_group_fd);
            if (FD_ISSET(i, &read_group_fd))
                in_the_socket(srv, cli, i);
        }
    }
}