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
    {"/users", &users, ": get the list of all users that exist on the domain"},
    {"/user", NULL, "[\"user_uuid\"] : get information about a user"},
    {"/send", NULL, "[\"user\"] [\"message_body\"] : send a message to a user"},
    {"/messages", NULL, "[\"user_uuid\"] : list all messages exchange with an user"},
    {"/subscribe", NULL, "[\"team_uuid\"] : subscribe to the event of a team and its sub directories"},
    {"/subscribed", NULL, "?[\"team_uuid\"] : list all subscribed teams or list all users subscribed to a team"},
    {"/use", NULL, "?[\"team_uuid\"] ?[\"channel_uuid\"] ?[\"thread_uuid\"] : use specify a context team/channel/thread"},
    {"/create", NULL, ""},
    {"/list", NULL, ""},
    {"/info", NULL, ""},
    {NULL, NULL, NULL}
};