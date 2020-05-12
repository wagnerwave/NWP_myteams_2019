/*
** EPITECH PROJECT, 2020
** Server teams
** File description:
** main of server
*/

#include "server.h"

int main(int ac, char **av)
{
    server_t *svr = malloc(sizeof(server_t));

    if (ac != 2)
        return 0;
    if (strcmp(av[1], "-help") == 0) {
        display_help(av[0]);
        return 0;
    } else {
        init_server(svr, (unsigned short)av[1]);
        teams_server(svr);
    }
    return 0;
}