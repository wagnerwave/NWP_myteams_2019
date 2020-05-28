/*
** EPITECH PROJECT, 2020
** myteams server
** File description:
** messages command
*/

#include <uuid/uuid.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "server.h"

static void get_msg_by_uuid(char **uuid, char *line, client_t **cli, int nb)
{
    char *dest_uuid = NULL;
    char *delim = ":\n";
    char *sender_id = NULL;
    char *timestamp = NULL;
    char *msg = NULL;

    dest_uuid = strtok(line, delim);
    if (dest_uuid == NULL)
        return;
    if ((sender_id = strtok(NULL, delim)) == NULL)
            return;
    if ((timestamp = strtok(NULL, delim)) == NULL)
            return;
    if ((msg = strtok(NULL, delim)) == NULL)
        return;
    dprintf(cli[nb]->fd ,"304 message get [%s:%s:%s]\n", sender_id,
    timestamp, msg);
}

static void read_msg_db(char *uuid, client_t **cli, int nb)
{
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    int line_size = 0;
    FILE *ptr = fopen(MSG_DB, "r");

    if (ptr == NULL)
        return;
    while (line_size != -1) {
        line_size = getline(&line_buf, &line_buf_size, ptr);
        if (strstr(line_buf, uuid) != NULL)
            get_msg_by_uuid(uuid, line_buf, cli, nb);
    }
    fclose(ptr);

}

void messages(client_t **cli, int nb, char **txt)
{
    char *uuid = NULL;
    user_t tmp;

    if ((uuid = get_info_to_str(txt[1])) == NULL)
        return;
    compare_uuid_with_db(&tmp, uuid);
    if (tmp.username == NULL) {
        printf("Erreur: user not existe or not found.\n");
        return;
    }
    read_msg_db(uuid_to_str(tmp.user_id), cli, nb);
}