/*
** EPITECH PROJECT, 2020
** my_teams client
** File description:
** interpertation of code responce byserver
*/

#include <string.h>
#include "logging_client.h"
#include "client.h"

void private_message_print_messages_func(char *msg)
{
    char **arg = arg_to_array(msg);

    if (check_arg(arg, 3) == 84)
        printf("Error: not enought arguments for this option.\n");
    else
        client_private_message_print_messages(arg[0], arg[1], arg[2]);
}

void print_reply_created_func(char *msg)
{
    char **arg = arg_to_array(msg);

    /*if (check_arg(arg, 4) == 84)
        printf("Error: not enought arguments for this option.\n");
    else
        client_print_reply_created(arg[0], arg[1],
     time_t reply_timestamp, arg[3]);*/
}

void print_subscribed_func(char *msg)
{
    char **arg = arg_to_array(msg);

    if (check_arg(arg, 2) == 84)
        printf("Error: not enought arguments for this option.\n");
    else
        client_print_subscribed(arg[0], arg[1]);
}

void print_unsubscribed_func(char *msg)
{
    char **arg = arg_to_array(msg);

    if (check_arg(arg, 2) == 84)
        printf("Error: not enought arguments for this option.\n");
    else
        client_print_unsubscribed(arg[0], arg[1]);
}