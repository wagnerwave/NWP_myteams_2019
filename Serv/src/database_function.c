/*
** EPITECH PROJECT, 2020
** Teams Server
** File description:
** Database function
*/

#include <uuid/uuid.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "server.h"

int file_exists(void)
{
    struct stat file_buffer;

    return (stat(USER_DB, &file_buffer));
}

void write_user_to_db(char const *uid, char const *username)
{
    FILE *ptr = fopen(USER_DB, "a");

    if (ptr == NULL)
        exit(84);
    else
        fprintf(ptr, "%s:%s\n", uid, username);
    fclose(ptr);
}

static void db_info_to_struct(user_t *tmp, char *line)
{
    char *token = NULL;
    char *delim = ":\n";

    token = strtok(line, delim);
    if (token == NULL)
        return;
    uuid_parse(token, tmp->user_id);
    token = strtok(NULL, delim);
    if (token == NULL)
        return;
    tmp->username = strdup(token);
}

void compare_username_with_db(user_t *tmp, char const *username)
{
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    int line_size = 0;
    FILE *fp = fopen(USER_DB, "r");

    if (!fp)
        exit(84);
    while ((line_size = getline(&line_buf, &line_buf_size, fp))!= -1) {
        db_info_to_struct(tmp, line_buf);
        if (strcmp(tmp->username, username) == 0) {
            if (line_buf)
                free(line_buf);
            fclose(fp);
            return;
        }
        if (line_buf)
            free(line_buf);
        line_buf = NULL;
    }
    tmp->username = NULL;
    fclose(fp);
}

void compare_uuid_with_db(user_t *tmp, char const *uuid)
{
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    int line_size = 0;
    FILE *fp = fopen(USER_DB, "r");

    if (!fp)
        exit(84);
    while ((line_size = getline(&line_buf, &line_buf_size, fp))!= -1) {
        db_info_to_struct(tmp, line_buf);
        if (strcmp(uuid_to_str(tmp->user_id), uuid) == 0) {
            if (line_buf)
                free(line_buf);
            fclose(fp);
            return;
        }
    }
    if (line_buf)
        free(line_buf);
    tmp->username = NULL;
    fclose(fp);
}