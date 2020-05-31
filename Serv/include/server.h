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
#include <string.h>
#include <stdbool.h>

#define MAX_CONNECTION_SERVER 1024
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 521
#define MAX_NAME_LENGTH 32
#define SPACE 32

#define USER_DB "./database/user.db"
#define MSG_DB  "./database/msg.db"
#define MYTEAM_DB "./database/myteams.db"

typedef struct server_s {
    struct sockaddr_in sin;
    unsigned short port;
    int tcp_sock;
} server_t;

typedef enum context_e {
    NO_CONTEXT = 0,
    TEAM,
    CHANNEL,
    THREAD
} context_t;

typedef struct user_s {
    char *username;
    uuid_t user_id;
    bool connected;
    context_t status;
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

void teams_server(server_t *srv);
//// create functions
void create_team(team_t *team, client_t **cli, uuid_t receiver);
void create_channel(channel_t *channel, client_t **cli, uuid_t receiver);
void create_thread(thread_t *thread, client_t **cli, uuid_t receiver);
void create_comment(comment_t *comment, client_t **cli, uuid_t receiver);
//// listing functions
void list_teams(server_t *serv, client_t **cli, uuid_t receiver);
void list_channels(team_t *team, client_t **cli, uuid_t receiver);
void list_threads(channel_t *chan, client_t **cli, uuid_t receiver);
void list_comments(thread_t *thread, client_t **cli, uuid_t receiver);
//// info printing functions
void print_team(team_t *team, client_t **cli, uuid_t receiver);
void print_channel(channel_t *channel, client_t **cli, uuid_t receiver);
void print_thread(thread_t *thread, client_t **cli, uuid_t receiver);
void print_comment(comment_t *comment, client_t **cli, uuid_t receiver);

/**** TEAMS     ****/
team_t *new_team(char *name, char *desc);
char *team_get_name(team_t *t);
char *team_get_id(team_t *t);
vector_t *team_get_channels(team_t *t);
void team_set_name(team_t *t, char *name);

/**** CHANNELS     ****/

channel_t *new_channel(char *name, char *desc);
char *channel_get_name(channel_t *t);
char  *channel_get_id(channel_t *t);
vector_t *channel_get_threads(channel_t *t);
void channel_set_name(channel_t *t, char *name);

/**** THREADS    ****/

thread_t *new_thread(char *title, char *desc, uuid_t author);
char *thread_get_title(thread_t *t);
char *thread_get_body(thread_t *t);
char *thread_get_uuid(thread_t *t);
time_t thread_get_timestamp(thread_t *t);
vector_t *thread_get_comments(thread_t *t);
void thread_set_title(thread_t *t, char *title);
thread_t *get_thread_by_id(uuid_t id);

/****  COMMENTS   ****/

comment_t *new_comment(char *body, uuid_t author);
char *comment_get_author(comment_t *comment);
char *comment_get_body(comment_t *comment);
time_t comment_get_timestamp(comment_t *comment);


/****   CMD     ****/

void help(client_t **cli, int nb, char **txt);
void users(client_t **cli, int nb, char **txt);
void user(client_t **cli, int nb, char **txt);

void info_func(client_t **cli, int nb, char **txt);

void login(client_t **cli, int nb, char **txt);
void logout(client_t **cli, int nb, char **txt);

void send_func(client_t **cli, int nb, char **txt);
void messages(client_t **cli, int nb, char **txt);

/****   ERROR   ****/

void error_msg(char *msg);
void error_n_quit(char *msg);

/****     ****/

#endif /* !SERVER_H_ */