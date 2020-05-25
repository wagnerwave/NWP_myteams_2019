/*
** EPITECH PROJECT, 2020
** my_teams client
** File description:
** interpertation of code responce byserver
*/

#include <string.h>
#include "logging_client.h"
#include "client.h"

static char **arg_to_array(char *msg)
{
    char *token = NULL;
    char *delim = "[]";
    char **array = NULL;

    token = strtok(msg, delim);
    if (token == NULL)
        return NULL;
    token = strtok(NULL, delim);
    if (token == NULL)
        return NULL;
   array = strtowordarray(token, ':');
   return array;
}

void login_func(char *msg)
{
    char **arg = arg_to_array(msg);

    client_event_loggedin(arg[0], arg[1]);
}

void logout_func(char *msg)
{
    char **arg = arg_to_array(msg);

    client_event_loggedout(arg[0], arg[1]);
}

void receive_msg_func(char *msg)
{
    char **arg = arg_to_array(msg);

    client_event_private_message_received(arg[0], arg[1]);
}