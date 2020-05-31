/*
** EPITECH PROJECT, 2020
** my_teams client
** File description:
** interpertation of code responce byserver
*/

#include <string.h>
#include "logging_client.h"
#include "client.h"

void error_unknown_team_func(char *msg)
{
    char **arg = arg_to_array(msg);

    if (check_arg(arg, 3) == 84)
        printf("Error: not enought arguments for this option.\n");
    else
        client_private_message_print_messages(arg[0], arg[1], arg[2]);
    free_array(arg);
}

void error_unknown_channel_func(char *msg)
{
    char **arg = arg_to_array(msg);

    if (check_arg(arg, 1) == 84)
        printf("Error: not enought arguments for this option.\n");
    else
        client_error_unknown_channel(arg[0]);
    free_array(arg);
}

void error_unknown_thread_func(char *msg)
{
    char **arg = arg_to_array(msg);

    if (check_arg(arg, 1) == 84)
        printf("Error: not enought arguments for this option.\n");
    else
        client_error_unknown_thread(arg[0]);
    free_array(arg);
}

void error_unknown_user_func(char *msg)
{
    char **arg = arg_to_array(msg);

    if (check_arg(arg, 1) == 84)
        printf("Error: not enought arguments for this option.\n");
    else
        client_error_unknown_user(arg[0]);
    free_array(arg);
}