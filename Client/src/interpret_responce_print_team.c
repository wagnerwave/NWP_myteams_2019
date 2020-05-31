/*
** EPITECH PROJECT, 2020
** my_teams client
** File description:
** interpertation of code responce byserver
*/

#include <string.h>
#include "logging_client.h"
#include "client.h"

void print_teams_func(char *msg)
{
    char **arg = arg_to_array(msg);

    if (check_arg(arg, 3) == 84)
        printf("Error: not enought arguments for this option.\n");
    else
        client_print_teams(arg[0], arg[1], arg[2]);
    free_array(arg);
}

void print_team_func(char *msg)
{
    char **arg = arg_to_array(msg);

    if (check_arg(arg, 3) == 84)
        printf("Error: not enought arguments for this option.\n");
    else
        client_print_team(arg[0], arg[1], arg[2]);
    free_array(arg);
}

void print_team_created_func(char *msg)
{
    char **arg = arg_to_array(msg);

    if (check_arg(arg, 3) == 84)
        printf("Error: not enought arguments for this option.\n");
    else
        client_print_team_created(arg[0], arg[1], arg[2]);
    free_array(arg);
}