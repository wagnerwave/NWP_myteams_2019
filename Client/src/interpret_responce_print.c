/*
** EPITECH PROJECT, 2020
** my_teams client
** File description:
** interpertation of code responce byserver
*/

#include <string.h>
#include "../../libs/myteams/logging_client.h"
#include "../include/client.h"

void private_message_print_messages_func(char *msg)
{
    char **arg = arg_to_array(msg);

    check_arg(arg, 3);
    client_private_message_print_messages((const char *)arg[0], arg[1], (const char *)arg[2]);
}

void print_reply_created_func(char *msg)
{
    char **arg = arg_to_array(msg);

    //check_arg(arg, 4);
    //client_print_reply_created(arg[0], arg[1], time_t reply_timestamp, arg[3]);
}

void print_subscribed_func(char *msg)
{
    char **arg = arg_to_array(msg);

    check_arg(arg, 2);
    client_print_subscribed((const char *)arg[0], (const char *)arg[1]);
}

void print_unsubscribed_func(char *msg)
{
    char **arg = arg_to_array(msg);

    check_arg(arg, 2);
    client_print_unsubscribed((const char *)arg[0], (const char *)arg[1]);
}