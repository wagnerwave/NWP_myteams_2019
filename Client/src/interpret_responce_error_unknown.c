/*
** EPITECH PROJECT, 2020
** my_teams client
** File description:
** interpertation of code responce byserver
*/

#include <string.h>
#include "../../libs/myteams/logging_client.h"
#include "../include/client.h"

void error_unknown_team_func(char *msg)
{
    char **arg = arg_to_array(msg);

    check_arg(arg, 3);
    client_private_message_print_messages((const char *)arg[0], (const char *)arg[1], (const char *)arg[2]);
}

void error_unknown_channel_func(char *msg)
{
    char **arg = arg_to_array(msg);

    check_arg(arg, 1);
    client_error_unknown_channel(arg[0]);
}

void error_unknown_thread_func(char *msg)
{
    char **arg = arg_to_array(msg);

    check_arg(arg, 1);
    client_error_unknown_thread((const char *)arg[0]);
}

void error_unknown_user_func(char *msg)
{
    char **arg = arg_to_array(msg);

    check_arg(arg, 1);
    client_error_unknown_user((const char *)arg[0]);
}