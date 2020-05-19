/*
** EPITECH PROJECT, 2020
** teams server
** File description:
** struct of cmd client
*/

#include <unistd.h>
#include "server.h"
#include "logging_server.h"

const cmd_t cmd[] = {
    {"/help", &help, "show help"},
    {"/login", &login, "[\"username\"]: set the username used by client"},
    {"/logout", &logout, ": disconnect the client from the server"},
    {"/users", &users, ": get the list of all users"},
    {"/user", NULL, "[\"user_uuid\"] : get information about a user"},
    {"/send", NULL, "[user|message_body]: send a message to a user"},
    {"/messages", NULL, "[user]: list all messages exchange with an user"},
    {"/subscribe", NULL, "[team]: subscribe to the event of a team"},
    {"/subscribed", NULL, "[team]: list all users subscribed to a team"},
    {"/use", NULL, "[teams|channel|thread]: use specify a context"},
    {"/create", NULL, "[teams|channel|thread]: create option"},
    {"/list", NULL, "[teams|channel|thread]: list option"},
    {"/info", NULL, "[teams|channel|thread]: info option"},
    {NULL, NULL, NULL}
};