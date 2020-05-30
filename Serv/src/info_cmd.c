/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** info commands
*/

#include "server.h"

void info_func(client_t **cli, int nb, char **txt)
{
    switch(cli[nb]->user.status) {
        case NO_CONTEXT:
            users(cli, nb, txt);
            break;
        case TEAM:
            break;
        case CHANNEL:
            break;
        case THREAD:
            break;
    }

}