/*
** EPITECH PROJECT, 2020
** teams client
** File description:
** header client
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <uuid/uuid.h>
#include <stdbool.h>

typedef struct user_s {
    char *username;
    uuid_t user_id;
    bool connected;
} user_t;

typedef struct client_s {
    struct sockaddr_in sin;
    int tcp_sock;
    const char *ip;
    unsigned short port;
    user_t user_info;
} client_t;

void client_run(client_t *cli);

/****   TOOLS   ****/

char *get_next_line(int fd);
char **strtowordarray(char *str, char delim);
char *uuid_to_str(uuid_t out);

/****   CODE FUNC   ****/

void login_func(char *msg);
void logout_func(char *msg);
void receive_msg_func(char *msg);

/****   INIT    ****/

void init_client(client_t *cli, const char *ip, unsigned short port);

/****   HELP    ****/

void display_help(char *nameprog);

/****   ****    ****/

#endif /* !CLIENT_H_ */
