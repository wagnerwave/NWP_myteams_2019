/*
** EPITECH PROJECT, 2020
** my_teams client
** File description:
** interpertation of code responce byserver
*/

#include <string.h>
#include "../../libs/myteams/logging_client.h"
#include "../include/client.h"

void print_teams_func(char *msg)
{
    char **arg = arg_to_array(msg);

    check_arg(arg, 3);
    client_print_teams((const char *)arg[0], (const char *)arg[1], (const char *)arg[2]);
}

void print_team_func(char *msg)
{
    char **arg = arg_to_array(msg);

    check_arg(arg, 3);
    client_print_team((const char *)arg[0], (const char *)arg[1], (const char *)arg[2]);
}

void print_team_created_func(char *msg)
{
    char **arg = arg_to_array(msg);

    check_arg(arg, 3);
    client_print_team_created((const char *)arg[0], (const char *)arg[1], (const char *)arg[2]);
}