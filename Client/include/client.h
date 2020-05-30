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
#include <stdio.h>

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
    int fd;
    fd_set clientfd;
    user_t user_info;
} client_t;

typedef struct interpert_command_by_server_s {
    const int  code;
    int (*func)(char *msg);
} inter_cmd_t;

extern const inter_cmd_t icmd[];

void client_run(client_t *cli);

/****   TOOLS   ****/

void int_handler(int i);
int running(int change);
char *get_next_line(int fd);
char **strtowordarray(char *str, char delim);
char *uuid_to_str(uuid_t out);
void free_array(char **arg);

/****   CODE FUNC   ****/

void error_unauthorized_func(void);
void error_already_exist_func(void);
void error_unknown_team_func(char *msg);
void error_unknown_channel_func(char *msg);
void error_unknown_thread_func(char *msg);
void error_unknown_user_func(char *msg);
void login_func(char *msg);
void logout_func(char *msg);
void receive_msg_func(char *msg);
void thread_msg_receive_func(char *msg);
void event_team_created_func(char *msg);
void event_channel_created_func(char *msg);
void event_thread_created_func(char *msg);
void private_message_print_messages_func(char *msg);
void print_reply_created_func(char *msg);
void print_subscribed_func(char *msg);
void print_unsubscribed_func(char *msg);
void team_print_channels_func(char *msg);
void print_channel_func(char *msg);
void print_channel_created_func(char *msg);
void print_teams_func(char *msg);
void print_team_func(char *msg);
void print_team_created_func(char *msg);
void channel_print_threads_func(char *msg);
void thread_print_replies_func(char *msg);
void print_thread_func(char *msg);
void print_thread_created_func(char *msg);
void print_users_func(char *msg);
void print_user_func(char *msg);
char **arg_to_array(char *msg);
int check_arg(char **arg, int number);
char *get_code_from_str(char *str);
void parsing_server_data(char *msg);
void parsing_data_1_to_5(char *msg, int code);
void parsing_data_6_to_10(char *msg, int code);
void parsing_data_11_to_15(char *msg, int code);
void parsing_data_16_to_19(char *msg, int code);
void parsing_data_20_to_24(char *msg, int code);
void parsing_data_25_to_29(char *msg, int code);
void parsing_data_no_command(char *msg, int code);


/****   INIT    ****/

void init_client(client_t *cli, const char *ip, unsigned short port);

/****   HELP    ****/

void display_help(char *nameprog);

/****   ****    ****/

#endif /* !CLIENT_H_ */
