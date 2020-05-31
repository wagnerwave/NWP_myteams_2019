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

void print_users_func(char *msg)
{
    char **arg = arg_to_array(msg);

    if (check_arg(arg, 3) == 84)
        printf("Error: not enought arguments for this option.\n");
    else
        client_print_users(arg[1], arg[0], atoi(arg[2]));
     free_array(arg);
}

void print_user_func(char *msg)
{
    char **arg = arg_to_array(msg);

    if (check_arg(arg, 3) == 84)
        printf("Error: not enought arguments for this option.\n");
    else
        client_print_user(arg[1], arg[0], arg[2]);
     free_array(arg);
}