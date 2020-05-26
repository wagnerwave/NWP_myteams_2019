/*
** EPITECH PROJECT, 2020
** my_teams client
** File description:
** interpertation of code responce byserver
*/

#include <string.h>
#include "../../libs/myteams/logging_client.h"
#include "../include/client.h"

void channel_print_threads_func(char *msg)
{
    char **arg = arg_to_array(msg);

    check_arg(arg, 4);
    client_channel_print_threads((const char *)arg[0], (const char *)arg[1], arg[2], arg[3], (const char *)arg[4]);
}

void thread_print_replies_func(char *msg)
{
    char **arg = arg_to_array(msg);

    check_arg(arg, 4);
    client_thread_print_replies((const char *)arg[0], (const char *)arg[1], arg[2], (const char *)arg[3]);
}

void print_thread_func(char *msg)
{
    char **arg = arg_to_array(msg);

    check_arg(arg, 4);
    //client_print_thread(arg[0], arg[1], time_t thread_timestamp, arg[3], arg[4]);
}

void print_thread_created_func(char *msg)
{
    char **arg = arg_to_array(msg);

    check_arg(arg, 4);
    //client_print_thread_created(arg[0], arg[1], time_t thread_timestamp, arg[3], arg[4]);
}