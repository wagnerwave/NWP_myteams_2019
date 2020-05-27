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
#include <sys/queue.h>
#include <uuid/uuid.h>
#include <stdbool.h>

#define MAX_CONNECTION_SERVER 1024
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 521
#define MAX_NAME_LENGTH 32
#define SPACE 32

#define USER_DB "./user.db"
#define MYTEAM_DB "./myteams.db"

typedef struct server_s {
    struct sockaddr_in sin;
    unsigned short port;
    int tcp_sock;
} server_t;

typedef struct teams_s {
    char name[MAX_NAME_LENGTH];
    char desc[MAX_DESCRIPTION_LENGTH];
    uuid_t id;
} teams_t;

typedef struct channel_s {
    char  name[MAX_NAME_LENGTH];
    char desc[MAX_DESCRIPTION_LENGTH];
    uuid_t id;
} channel_t;

typedef struct thread_s {
    char *title;
    char *msg;
    uuid_t id;
} thread_t ;

typedef struct comment_s {
    char body[MAX_BODY_LENGTH];
} comment_t;

typedef struct user_s {
    char *username;
    uuid_t user_id;
    bool connected;
} user_t;

typedef struct client_s {
    fd_set *group_fd;
    user_t user;
    int fd;
} client_t;

typedef struct cmd_s {
    const char *name;
    void (*func)(client_t **cli, int nb, char **txt);
    const char *desc;
} cmd_t;

extern const cmd_t cmd[];

/****   TOOLS   ****/

char *get_next_line(int fd);
char **strtowordarray(char *str, char delim);
void display_help(char *nameprog);

void interpert_client_input(client_t **cli, int nb, char *input);

char *uuid_to_str(uuid_t out);
char *get_info_to_str(char *str);
char *get_msg_to_array(char **txt);
int count_tab(char **tab);

/****   DB_FUNC ****/

int file_exists();
void write_user_to_db(char const *uid, char const *username);
void compare_username_with_db(user_t *tmp, char const *username);
void compare_uuid_with_db(user_t *tmp, char const *uuid);

/****   INIT    ****/

void init_client(client_t *cli, int sock, fd_set *acv_grpfd);
void init_server(server_t *srv, unsigned short port);
void default_init_client(client_t **cli);

/****   SERVER  ****/

void teams_server(server_t *svr);

/****   CMD     ****/

void help(client_t **cli, int nb, char **txt);
void users(client_t **cli, int nb, char **txt);
void user(client_t **cli, int nb, char **txt);

void login(client_t **cli, int nb, char **txt);
void logout(client_t **cli, int nb, char **txt);

void send_func(client_t **cli, int nb, char **txt);

/****   ERROR   ****/

void error_msg(char *msg);
void error_n_quit(char *msg);

/****   ****    ****/

#endif /* !SERVER_H_ */
