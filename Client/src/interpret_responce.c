/*
** EPITECH PROJECT, 2020
** my_teams client
** File description:
** interpertation of code responce byserver
*/

#include <string.h>
#include <stdlib.h>
#include "logging_client.h"
#include "client.h"

char *get_code_from_str(char *str)
{
    char *code = malloc(sizeof(char) * (3 + 1));
    size_t i = 0;

    if (code == NULL) {
        printf("Error: Error failed malloc to get code.\n");
        exit(84);
    }
    for (i = 0; i < 3; i++)
        code[i] = str[i];
    code[i] = '\0';
    return code;
}

int check_arg(char **arg, int number)
{
    int i = 0;

    while (arg[i] != NULL) {
        i++;
    }
    if (i != number)
        return (84);
    return 0;
}

char **arg_to_array(char *msg)
{
    char *token = NULL;
    char *delim = "[]";
    char **array = NULL;

    token = strtok(msg, delim);
    if (token == NULL)
        return NULL;
    token = strtok(NULL, delim);
    if (token == NULL)
        return NULL;
    array = strtowordarray(token, ':');
    return array;
}

void parsing_server_data(char *msg)
{
    char *code_msg = get_code_from_str(msg);
    int code = atoi(code_msg);
    size_t i = 0;

    if (code_msg)
        free(code_msg);
    for (i = 0; icmd[i].code != 0; i++)
        if (icmd[i].code == code)
            break;
    if (icmd[i].code != 0)
        icmd[i].func(msg);
    else
        printf("%s\n", msg);
}