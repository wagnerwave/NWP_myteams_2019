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
    {"/help", NULL, &help, "show help"},
    {"/login", NULL, &login, "[\"username\"]: set the username used by client"},
    {"/logout", NULL, &logout, ": disconnect the client from the server"},
    {"/users", NULL, NULL, ": get the list of all users that exist on the domain"},
    {"/user", NULL, NULL, "[\"user_uuid\"] : get information about a user"},
    {"/send", NULL, NULL, "[\"user\"] [\"message_body\"] : send a message to a user"},
    {"/messages", NULL, NULL, "[\"user_uuid\"] : list all messages exchange with an user"},
    {"/subscribe", NULL, NULL, "[\"team_uuid\"] : subscribe to the event of a team and its sub directories"},
    {"/subscribed", NULL, NULL, "?[\"team_uuid\"] : list all subscribed teams or list all users subscribed to a team"},
    {"/use", NULL, NULL, "?[\"team_uuid\"] ?[\"channel_uuid\"] ?[\"thread_uuid\"] : use specify a context team/channel/thread"},
    {"/create", NULL, NULL, ""},
    {"/list", NULL, NULL, ""},
    {"/info", NULL, NULL, ""},
    {NULL, NULL, NULL, NULL}
};