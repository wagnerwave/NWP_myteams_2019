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

#define USER_DB "./user.db"
#define MYTEAM_DB "./myteams.db"

int file_exists()
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
    size_t line_size = 0;
    FILE *fp = fopen(USER_DB, "r");

    if (!fp)
        exit(84);
    line_size = getline(&line_buf, &line_buf_size, fp);
    db_info_to_struct(tmp, line_buf);
    if (strcmp(tmp->username, username) == 0) {
        fclose(fp);
        return;
    }
    while (line_size != -1) {
        line_size = getline(&line_buf, &line_buf_size, fp);
        db_info_to_struct(tmp, line_buf);
        if (strcmp(tmp->username, username) == 0) {
            fclose(fp);
            return;
        }
    }
    tmp->username = NULL;
    fclose(fp);
}