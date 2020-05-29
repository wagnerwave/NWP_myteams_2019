/*
** EPITECH PROJECT, 2020
** my_teams client
** File description:
** interpertation of code responce byserver
*/

#include <string.h>
#include "logging_client.h"
#include "client.h"

void channel_print_threads_func(char *msg)
{
    char **arg = arg_to_array(msg);

    if (check_arg(arg, 4) == 84)
        printf("Error: not enought arguments for this option.\n");
    else
        client_channel_print_threads(arg[0], arg[1], arg[2], arg[3], arg[4]);
     free_array(arg);
}

void thread_print_replies_func(char *msg)
{
    char **arg = arg_to_array(msg);

    if (check_arg(arg, 4) == 84)
        printf("Error: not enought arguments for this option.\n");
    else
        client_thread_print_replies(arg[0], arg[1], arg[2], arg[3]);
     free_array(arg);
}

void print_thread_func(char *msg)
{
    char **arg = arg_to_array(msg);

    /*if (check_arg(arg, 4) == 84)
        printf("Error: not enought arguments for this option.\n");
    else
        client_print_thread(arg[0], arg[1], time_t thread_timestamp,
     arg[3], arg[4]);*/
     free_array(arg);
}

void print_thread_created_func(char *msg)
{
    char **arg = arg_to_array(msg);

    /*if (check_arg(arg, 3) == 84)
        printf("Error: not enought arguments for this option.\n");
    else
        check_arg(arg, 4);
    client_print_thread_created(arg[0], arg[1], time_t thread_timestamp,
     arg[3], arg[4]);*/
     free_array(arg);
}