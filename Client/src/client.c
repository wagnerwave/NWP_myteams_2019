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

void str_trim_lf (char* arr, int length) {
    int i;
    for (i = 0; i < length; i++) { // trim \n
        if (arr[i] == '\n') {
            arr[i] = '\0';
            break;
        }
    }
}
void str_overwrite_stdout() {
    printf("\r%s", "> ");
    fflush(stdout);
}
/*
void recv_msg_handler() {
    char receiveMessage[LENGTH_SEND] = {};
    while (1) {
        int receive = recv(sockfd, receiveMessage, LENGTH_SEND, 0);
        if (receive > 0) {
            printf("\r%s\n", receiveMessage);
            str_overwrite_stdout();
        } else if (receive == 0) {
            break;
        } else {
            // -1
        }
    }
}

void send_msg_handler() {
    char message[LENGTH_MSG] = {};
    while (1) {
        str_overwrite_stdout();
        while (fgets(message, LENGTH_MSG, stdin) != NULL) {
            str_trim_lf(message, LENGTH_MSG);
            if (strlen(message) == 0) {
                str_overwrite_stdout();
            } else {
                break;
            }
        }
        send(sockfd, message, LENGTH_MSG, 0);
        if (strcmp(message, "exit") == 0) {
            break;
        }
    }
    catch_ctrl_c_and_exit(2);
}*/

