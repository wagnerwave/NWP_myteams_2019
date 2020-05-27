/*
** EPITECH PROJECT, 2020
** my_teams client
** File description:
** interpertation of code responce byserver
*/

#include <string.h>
#include <stdlib.h>
#include "logging_client.h"
#include "client.h"

char **arg_to_array(char *msg)
{
    char *token = NULL;
    char *delim = "[]";
    char **array = NULL;

    token = strtok(msg, delim);
    if (token == NULL)
        return NULL;
    token = strtok(NULL, delim);
    if (token == NULL)
        return NULL;
    array = strtowordarray(token, ':');
    return array;
}

void parsing_server_data(char *msg)
{
    char *code = get_code_from_str(msg);

    parsing_data_one_to_eight(msg, atoi(code));
}

void parsing_data_one_to_eight(char *msg, int code)
{
    switch (code) {
        case 120:
            login_func(msg);
            break;
        case 210:
            logout_func(msg);
            break;
        case 101:
            receive_msg_func(msg);
            break;
        case 4:
            thread_msg_receive_func(msg);
            break;
        case 5:
            event_team_created_func(msg);
            break;
        case 6:
            event_channel_created_func(msg);
            break;
        case 7:
            event_thread_created_func(msg);
            break;
        case 8:
            print_users_func(msg);
            break;
    }
    parsing_data_nine_to_sixteen(msg, code);
}

void parsing_data_nine_to_sixteen(char *msg, int code)
{
    switch (code) {
        case 9:
            print_teams_func(msg);
            break;
        case 10:
            team_print_channels_func(msg);
            break;
        case 11:
            channel_print_threads_func(msg);
            break;
        case 12:
            thread_print_replies_func(msg);
            break;
        case 13:
            private_message_print_messages_func(msg);
            break;
        case 14:
            error_unknown_team_func(msg);
            break;
        case 15:
            error_unknown_channel_func(msg);
            break;
        case 16:
            error_unknown_thread_func(msg);
            break;
    }
    parsing_data_seventeen_to_twenty_four(msg, code);
}

void parsing_data_seventeen_to_twenty_four(char *msg, int code)
{
    switch (code) {
        case 17:
            error_unknown_user_func(msg);
            break;
        case 18:
            error_unauthorized_func();
            break;
        case 19:
            error_already_exist_func();
            break;
        case 20:
            print_user_func(msg);
            break;
        case 21:
            print_team_func(msg);
            break;
        case 22:
            print_channel_func(msg);
            break;
        case 23:
            print_thread_func(msg);
            break;
        case 24:
            print_team_created_func(msg);
            break;
    }
    parsing_data_twenty_five_to_twenty_nine(msg, code);
}

void parsing_data_twenty_five_to_twenty_nine(char *msg, int code)
{
    switch (code) {
        case 25:
            print_channel_created_func(msg);
            break;
        case 26:
            print_thread_created_func(msg);
            break;
        case 27:
            print_reply_created_func(msg);
            break;
        case 28:
            print_subscribed_func(msg);
            break;
        case 29:
            print_unsubscribed_func(msg);
            break;
    }
    parsing_data_no_command(msg, code);
}

void parsing_data_no_command(char *msg, int code)
{
    if (code != 1 && code != 2
        && code != 3 && code != 4 && code != 5
        && code != 6 && code != 7 && code != 8
        && code != 9 && code != 10 && code != 11
        && code != 12 && code != 13 && code != 14
        && code != 15 && code != 16 && code != 17
        && code != 18 && code != 19 && code != 20 && code != 21
        && code != 22 && code != 23 && code != 24
        && code != 25 && code != 26 && code != 27
        && code != 28 && code != 29)
        printf("%s", msg);
}