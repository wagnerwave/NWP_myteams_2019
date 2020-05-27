/*
** EPITECH PROJECT, 2020
** my_teams client
** File description:
** interpertation of code responce byserver
*/

#include <string.h>
#include "logging_client.h"
#include "../include/client.h"

void login_func(char *msg)
{
    char **arg = arg_to_array(msg);

    if (check_arg(arg, 2) == 84)
        printf("Error: not enought arguments for this option.\n");
    else
        client_event_loggedin(arg[0], arg[1]);
}

void logout_func(char *msg)
{
    char **arg = arg_to_array(msg);

    if (check_arg(arg, 2) == 84)
        printf("Error: not enought arguments for this option.\n");
    else
        client_event_loggedout(arg[0], arg[1]);
}

void receive_msg_func(char *msg)
{
    char **arg = arg_to_array(msg);

    if (check_arg(arg, 2) == 84)
        printf("Error: not enought arguments for this option.\n");
    else
        client_event_private_message_received(arg[0], arg[1]);
}

void thread_msg_receive_func(char *msg)
{
    char **arg = arg_to_array(msg);

    if (check_arg(arg, 4) == 84)
        printf("Error: not enought arguments for this option.\n");
    else
        client_event_thread_message_received(arg[0], arg[1], arg[2], arg[3]);
}