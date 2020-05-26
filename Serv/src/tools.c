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

char *clean_str(char *str, char c)
{
    char *clean = NULL;
    size_t cnt = 0;

    for (size_t i = 0; str[i]; i++)
        if (str[i] != c)
            cnt++;
    clean = malloc(sizeof(char) * cnt);
    if (clean == NULL)
        exit(84);
    for (size_t i = 0, a = 0; str[i]; i++)
        if (str[i] != c) {
            clean[a] = str[i];
            a++;
        }
    return clean;
}

bool good_param(char *str)
{
    if (str[0] == '"' && str[strlen(str)] == '"')
        return true;
    else
        return false;
}