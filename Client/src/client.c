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


#include <sys/socket.h>
#include <sys/types.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void client_run(client_t *cli) {
    int fd;
    int result;
    char msg[1024 + 1];
    char kb_msg[1024 + 10];
    fd_set readfds, testfds, clientfds;
    fflush(stdout);

    FD_ZERO(&clientfds);
    FD_SET(cli->tcp_sock, &clientfds);
    FD_SET(0, &clientfds);//stdin

    while (1) {
        testfds = clientfds;
        select(FD_SETSIZE, &testfds, NULL, NULL, NULL);

        for (fd = 0; fd < FD_SETSIZE; fd++) {
            if (FD_ISSET(fd, &testfds)) {
                if (fd == cli->tcp_sock) {
                    result = read(cli->tcp_sock, msg, 1024);
                    msg[result] = '\0';
                    printf("CLIENT GET : %s\n", msg);

                } else if (fd == 0) {
                    fgets(kb_msg, 1024 + 1, stdin);
                        sprintf(msg, "%s", kb_msg);
                        write(cli->tcp_sock, msg, strlen(msg));
                }
            }
        }
    }

}