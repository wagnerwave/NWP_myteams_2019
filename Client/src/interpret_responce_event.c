/*
** EPITECH PROJECT, 2020
** my_teams client
** File description:
** interpertation of code responce byserver
*/

#include <string.h>
#include "../../libs/myteams/logging_client.h"
#include "../include/client.h"

void login_func(char *msg)
{
    char **arg = arg_to_array(msg);

    check_arg(arg, 2);
    client_event_loggedin((const char *)arg[0], (const char *)arg[1]);
}

void logout_func(char *msg)
{
    char **arg = arg_to_array(msg);

    check_arg(arg, 2);
    client_event_loggedout((const char *)arg[0], (const char *)arg[1]);
}

void receive_msg_func(char *msg)
{
    char **arg = arg_to_array(msg);

    check_arg(arg, 2);
    client_event_private_message_received((const char *)arg[0], (const char *)arg[1]);
}

void thread_msg_receive_func(char *msg)
{
    char **arg = arg_to_array(msg);

    check_arg(arg, 4);
    client_event_thread_message_received((const char *)arg[0],
    (const char *)arg[1], (const char *)arg[2], (const char *)arg[3]);
}