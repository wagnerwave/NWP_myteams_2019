/*
** EPITECH PROJECT, 2020
** server teams
** File description:
** server header
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>

#define MAX_CONNECTION_SERVER 1024
#define SPACE 32

typedef struct server_s {
    struct sockaddr_in sin;
    unsigned short port;
    int tcp_sock;
} server_t;

typedef struct user_s {
    char *username;
} user_t;

typedef struct client_s {
    fd_set *group_fd;
    user_t user;
    int fd;
} client_t;

/****   TOOLS   ****/

char *get_next_line(int fd);
char **strtowordarray(char *str, char delim);
void display_help(char *nameprog);

void interpert_client_input(client_t *cli, char *input);

/****   INIT    ****/

void init_client(client_t *cli, int sock, fd_set *acv_grpfd);
void init_server(server_t *srv, unsigned short port);
void default_init_client(client_t **cli);

/****   SERVER  ****/

void teams_server(server_t *svr);

/****   ERROR   ****/

void error_msg(char *msg);
void error_n_quit(char *msg);

/****   ****    ****/

#endif /* !SERVER_H_ */
