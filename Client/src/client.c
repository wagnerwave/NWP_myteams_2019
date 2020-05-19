/*
** EPITECH PROJECT, 2020
** teams client
** File description:
** client for teams
*/

#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "client.h"

static void in_the_socket(int fd, fd_set *clientfd, int tcp_sock)
{
    int result = 0;
    char *input = NULL;
    char msg[1024];

    if (fd == tcp_sock) {
        result = read(tcp_sock, msg, 1024);
        msg[result] = '\0';
        printf("CLIENT GET : %s\n", msg);
        // interpretation de la reponse du serveur
    } else if (fd == 0) {
        input = get_next_line(0);
        printf("i enter : %s\n", input);
        if (input == NULL)
            return;
        dprintf(tcp_sock, "%s\n", input);
    }
}

void client_run(client_t *cli) {
    fd_set readfd;
    fd_set clientfd;

    FD_ZERO(&clientfd);
    FD_SET(cli->tcp_sock, &clientfd);
    FD_SET(0, &clientfd);
    while (1) {
        readfd = clientfd;
        if (select(FD_SETSIZE, &readfd ,NULL, NULL, NULL) < 0)
            exit(84);
        for (int fd = 0; fd < FD_SETSIZE; fd++) {
            if (FD_ISSET(fd, &readfd))
                in_the_socket(fd, &clientfd, cli->tcp_sock);
        }
    }
}