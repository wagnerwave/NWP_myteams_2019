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
#include <signal.h>
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
        if (strlen(msg) == 0) {
            close(fd);
            FD_CLR(fd, clientfd);
            exit(0);
        }
        parsing_server_data(msg);
    } else {
        input = get_next_line(0);
        if (input == NULL)
            return;
        dprintf(tcp_sock, "%s\n", input);
    }
}

static int running(int change)
{
    static int i  = 1;

    if (change == 1)
        i = 0;
    return i;
}

static void int_handler(int i)
{
    (void)i;
    running(1);
    return;
}

static void close_client(int fd, fd_set *grpfd, client_t *cli)
{
    close(fd);
    dprintf(cli->tcp_sock ,"666 SIGKILL\n");
    FD_CLR(fd, grpfd);
}

void client_run(client_t *cli)
{
    fd_set clientfd;
    fd_set readfd;
    int fd = 0;

    FD_ZERO(&clientfd);
    FD_SET(cli->tcp_sock, &clientfd);
    FD_SET(0, &clientfd);
    signal(SIGINT, int_handler);
    while (running(0)) {
        readfd = clientfd;
        if (select(FD_SETSIZE, &readfd, NULL, NULL, NULL) <= 0) {
            close_client(fd, &clientfd, cli);
            return;
        }
        for (fd = 0; fd < FD_SETSIZE; fd++) {
            if (FD_ISSET(fd, &readfd)) {
                in_the_socket(fd, &clientfd, cli->tcp_sock);
            }
        }
    }
    close_client(fd, &clientfd, cli);
}