/*
** EPITECH PROJECT, 2020
** myteams server
** File description:
** clean string for usage
*/

#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include "server.h"

static char *clean_str(char *str, char c)
{
    char *clean = NULL;
    size_t cnt = 0;

    for (size_t i = 0; str[i]; i++)
        if (str[i] != c)
            cnt++;
    clean = malloc(sizeof(char) * (cnt + 1));
    if (clean == NULL)
        exit(84);
    for (size_t i = 0, a = 0; str[i]; i++)
        if (str[i] != c) {
            clean[a] = str[i];
            a++;
        }
    clean[cnt] = '\0';
    return clean;
}

static bool good_param(char *str)
{
    if (str[0] == '"' && str[strlen(str) - 1] == '"')
        return true;
    else
        return false;
}

char *get_info_to_str(char *str)
{
    char *cleaned = NULL;

    if (str == NULL)
        return NULL;
    if (good_param(str) == false)
        return NULL;
    cleaned = clean_str(str, '"');
    return cleaned;
}

char *get_msg_to_array(char **txt)
{
    int nb_arg = count_tab(txt);
    int lenght = 0;
    char *msg = NULL;
    int x = 0;

    if (nb_arg < 2)
        return NULL;
    for (int i = 2; txt[i]; i++)
        lenght += strlen(txt[i]);
    msg = malloc(sizeof(char) * (lenght + nb_arg + 1));
    for (int i = 2; txt[i]; i++, x++) {
        for (int y = 0; txt[i][y]; y++, x++) {
            msg[x] = txt[i][y];
        }
        msg[x] = ' ';
    }
    msg[x - 1] = '\0';;
    msg = get_info_to_str(msg);
    return msg;
}