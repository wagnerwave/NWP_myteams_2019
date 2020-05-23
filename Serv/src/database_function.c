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
#include "server.h"

#define USER_DB "./user.db"
#define MYTEAM_DB "./myteams.db"
/*
void load_user_file(char const *file)
{
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    size_t line_size = 0;
    FILE *fp = fopen(file, "r");

    if (!fp)
        exit(84);
    line_size = getline(&line_buf, &line_buf_size, fp);
    while (line_size >= 0) {
        line_size = getline(&line_buf, &line_buf_size, fp);
    }
    fclose(fp);
}

bool file_exists(char const *file)
{
    struct stat buffer;
    bool exist = stat(file, &buffer);
    if (exist)
        return true;
    else
        return false;
}

void check_databases()
{
    if (file_exists(USER_DB) == false)
        create_file(USER_DB);
    else
        load_user_file(USER_DB);
    if (file_exists(MYTEAM_DB) == false)
        create_file(MYTEAM_DB);
}
*/

void write_user_to_db(char const *uid, char const *username)
{
    FILE *ptr = fopen(USER_DB, "a");

    if (ptr == NULL)
        exit(84);
    else
        fprintf(ptr, "%s:%s\n", uid, username);
    fclose(ptr);
}

static char *get_name_on_str_with_db(char *line)
{
    size_t i = 0;
    char *name = NULL;

    while (line != ':')
        line++;
    for (i = 0; line[i] != '\n'; i++);
    name = malloc(sizeof(char) * (i + 1));
    if (name == NULL) {
        printf("Error: malloc failed to get name on DB.\n");
        exit(84);
    }
    for (size_t x = 0; line[x] != '\n'; x++)
        name[x] = line[x];
    return name;
}

char *compare_username_with_db(char const *username)
{
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    size_t line_size = 0;
    FILE *fp = fopen(USER_DB, "r");
    char *name = NULL;
    long x = 0;

    if (!fp)
        exit(84);
    line_size = getline(&line_buf, &line_buf_size, fp);
    name = get_name_on_str_with_db(line_buf);
    if (name == username)
        return line_buf;
    else
        free(name);
    while (line_size >= 0) {
        line_size = getline(&line_buf, &line_buf_size, fp);
        name = get_name_on_str_with_db(line_buf);
        if (name == username)
            return line_buf;
        else
            free(name);
    }
    fclose(fp);
    return NULL;
}