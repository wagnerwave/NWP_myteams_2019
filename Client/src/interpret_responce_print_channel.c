/*
** EPITECH PROJECT, 2020
** my_teams client
** File description:
** interpertation of code responce byserver
*/

#include <string.h>
#include "../../libs/myteams/logging_client.h"
#include "../include/client.h"

void team_print_channels_func(char *msg)
{
    char **arg = arg_to_array(msg);

    check_arg(arg, 3);
    client_team_print_channels((const char *)arg[0], (const char *)arg[1], (const char *)arg[2]);
}

void print_channel_func(char *msg)
{
    char **arg = arg_to_array(msg);

    check_arg(arg, 3);
    client_print_channel((const char *)arg[0], (const char *)arg[1], (const char *)arg[2]);
}

void print_channel_created_func(char *msg)
{
    char **arg = arg_to_array(msg);

    check_arg(arg, 3);
    client_print_channel_created((const char *)arg[0], (const char *)arg[1], (const char *)arg[2]);
}