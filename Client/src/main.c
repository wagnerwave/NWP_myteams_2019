/*
** EPITECH PROJECT, 2020
** teams client
** File description:
** main for teams client
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"

int running(int change)
{
    static int i  = 1;

    if (change == 1)
        i = 0;
    return i;
}

void int_handler(int i)
{
    (void)i;
    running(1);
    return;
}

int main(int ac, char **av)
{
    client_t *cli = malloc(sizeof(client_t));

    if (cli == NULL)
        return 84;
    if (ac < 2 || ac > 3)
        return 84;
    if (strcmp(av[1], "-help") == 0) {
        display_help(av[0]);
        return 0;
    } else if (ac == 3) {
        init_client(cli, av[1], (unsigned short)atoi(av[2]));
        client_run(cli);
    }
    free(cli);
    return 0;
}