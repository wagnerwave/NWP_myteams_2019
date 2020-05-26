/*
** EPITECH PROJECT, 2020
** teams server
** File description:
** function tools for uuid
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <uuid/uuid.h>

char *uuid_to_str(uuid_t out)
{
    char *str = malloc(37);

    if (str == NULL)
        return NULL;
    uuid_unparse(out, str);
    return str;
}

int count_tab(char **tab)
{
    int i = 0;

    while (tab[i])
        i++;
    return i;
}