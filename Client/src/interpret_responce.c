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
    for (i = 0; i != 3; i++)
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

    if (code_msg)
        free(code_msg);
    parsing_data_1_to_5(msg, code);
}

void parsing_data_no_command(char *msg, int code)
{
    if (code != 120 && code != 210
        && code != 101 && code != 4 && code != 5
        && code != 6 && code != 7 && code != 8
        && code != 9 && code != 10 && code != 11
        && code != 12 && code != 304 && code != 14
        && code != 15 && code != 16 && code != 17
        && code != 18 && code != 19 && code != 20 && code != 21
        && code != 22 && code != 23 && code != 24
        && code != 25 && code != 26 && code != 27
        && code != 28 && code != 29)
        printf("%s", msg);
}