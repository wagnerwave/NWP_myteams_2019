/*
** EPITECH PROJECT, 2020
** server teams
** File description:
** server teams
*/

#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include "server.h"

#include <stdio.h>
#include <string.h>

static void client_management(client_t *cli)
{
    int n = 0;
    char *buffer = malloc(sizeof(char) * 1024);

    bzero(buffer, 256);
    n = read(cli->fd, buffer, 255);
    if (n < 0)
        printf("Erreur reading from socket");
    printf("Client: %s\n", buffer);
    bzero(buffer, 256);
    fgets(buffer, 255, stdin);
    n = write(cli->fd, buffer, strlen(buffer));
    if (n < 0)
        printf("Erreur writing socket");
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

static void in_the_socket(server_t *srv, client_t *cli) {
    if (cli->fd == srv->tcp_sock) {
        connection_client(srv->tcp_sock, cli->group_fd);
    } else {
        client_management(cli);
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
                in_the_socket(srv, cli[i]);
        }
    }
}