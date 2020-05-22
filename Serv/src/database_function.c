/*
** EPITECH PROJECT, 2020
** Teams Server
** File description:
** Database function
*/

#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

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
    char *user_db = "../user.db";
    char *teams_db = "../myteams.db";

    if (file_exists(user_db) == false)
        create_file(user_db);
    else
        load_user_file(user_db);
    if (file_exists(teams_db) == false)
        create_file(teams_db);
}