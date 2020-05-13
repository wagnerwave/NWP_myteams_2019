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

typedef union libfunc_u {
    int (*four_param)(char const *one, char const *two, char const *three,
    char const *four);
    int (*three_param)(char const *one, char const *two, char const *three);
    int (*two_param)(char const *one, char const *two);
    int (*one_param)(char const *one);
    int (*zero_param)(void);
} libfunc_t;

typedef union func_u {
    void (*one_param)(client_t *cli);
} func_t;

typedef struct cmd_s {
    char *name;
    libfunc_t libfunc;
    func_t    func;
    char *desc;
} cmd_t;

extern const cmd_t cmd[];

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

/****   CMD     ****/

void help(client_t *cli);

/****   ERROR   ****/

void error_msg(char *msg);
void error_n_quit(char *msg);

/****   ****    ****/

#endif /* !SERVER_H_ */
