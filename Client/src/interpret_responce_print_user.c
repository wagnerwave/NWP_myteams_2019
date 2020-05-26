/*
** EPITECH PROJECT, 2020
** my_teams client
** File description:
** interpertation of code responce byserver
*/

#include <string.h>
#include "../../libs/myteams/logging_client.h"
#include "../include/client.h"

void print_users_func(char *msg)
{
    char **arg = arg_to_array(msg);

    check_arg(arg, 3);
    client_print_users((const char *)arg[0], (const char *)arg[1], (char *)arg[2]);
}

void print_user_func(char *msg)
{
    char **arg = arg_to_array(msg);

    check_arg(arg, 3);
    client_print_user((const char *)arg[0], (const char *)arg[1], (char *)arg[2]);
}