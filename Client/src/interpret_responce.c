/*
** EPITECH PROJECT, 2020
** my_teams client
** File description:
** interpertation of code responce byserver
*/

#include <string.h>
#include "../../libs/myteams/logging_client.h"
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

void parsing_server_data_part_four(char *msg, char *code)
{
    if (strcmp(code, "023") == 0)
        print_thread_func(msg);
    else if (strcmp(code, "024") == 0)
        print_team_created_func(msg);
    else if (strcmp(code, "025") == 0)
        print_channel_created_func(msg);
    else if (strcmp(code, "026") == 0)
        print_thread_created_func(msg);
    else if (strcmp(code, "027") == 0)
        print_reply_created_func(msg);
    else if (strcmp(code, "028") == 0)
        print_subscribed_func(msg);
    else if (strcmp(code, "029") == 0)
        print_unsubscribed_func(msg);
    else
        printf("%s", msg);
}

void parsing_server_data_three_part(char *msg, char *code)
{
    if (strcmp(code, "016") == 0)
        error_unknown_thread_func(msg);
    else if (strcmp(code, "017") == 0)
        error_unknown_user_func(msg);
    else if (strcmp(code, "018") == 0)
        error_unauthorized_func();
    else if (strcmp(code, "019") == 0)
        error_already_exist_func();
    else if (strcmp(code, "020") == 0)
        print_user_func(msg);
    else if (strcmp(code, "021") == 0)
        print_team_func(msg);
    else if (strcmp(code, "022") == 0)
        print_channel_func(msg);
    else
        parsing_server_data_part_four(msg, code);
}


void parsing_server_data_segond_part(char *msg, char *code)
{
    if (strcmp(code, "008") == 0)
        print_users_func(msg);
    else if (strcmp(code, "009") == 0)
        print_teams_func(msg);
    else if (strcmp(code, "010") == 0)
        team_print_channels_func(msg);
    else if (strcmp(code, "011") == 0)
        channel_print_threads_func(msg);
    else if (strcmp(code, "012") == 0)
        thread_print_replies_func(msg);
    else if (strcmp(code, "013") == 0)
        private_message_print_messages_func(msg);
    else if (strcmp(code, "014") == 0)
        error_unknown_team_func(msg);
    else if (strcmp(code, "015") == 0)
        error_unknown_channel_func(msg);
    else
        parsing_server_data_three_part(msg, code);
}

void parsing_server_data(char *msg)
{
    char *code = get_code_from_str(msg);

    if (strcmp(code, "001") == 0)
        login_func(msg);
    else if (strcmp(code, "002") == 0)
        logout_func(msg);
    else if (strcmp(code, "003") == 0)
        receive_msg_func(msg);
    else if (strcmp(code, "004") == 0)
        thread_msg_receive_func(msg);
    else if (strcmp(code, "005") == 0)
        event_team_created_func(msg);
    else if (strcmp(code, "006") == 0)
        event_channel_created_func(msg);
    else if (strcmp(code, "007") == 0)
        event_thread_created_func(msg);
    else
        parsing_server_data_segond_part(msg, code);
}