/*
** EPITECH PROJECT, 2020
** teams server
** File description:
** Interpret user input
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"

static void free_input(char **content)
{
    for (size_t x = 0; content[x]; x++)
        free(content[x]);
    free(content);
}

void interpert_client_input(client_t *cli, char *input)
{
    char **content = strtowordarray(input, SPACE);
    size_t i = 0;

    for (i = 0; cmd[i].name != NULL; i++)
        if (strcmp(cmd[i].name, content[0]) == 0)
            break;
    if (cmd[i].name != NULL)
        (*cmd[i].func.one_param)(cli);
    else
        printf("SERVER GET : %s\n", input);
    free_input(content);
}