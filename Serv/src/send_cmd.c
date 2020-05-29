/*
** EPITECH PROJECT, 2020
** myteams server
** File description:
** commands messages
*/

#include <uuid/uuid.h>
#include <stdio.h>
#include <stdlib.h>
#include "logging_server.h"
#include "server.h"

static void write_to_msg_db(client_t **cli, int nb, char *msg, char *dest_uid)
{
    FILE *ptr = fopen(MSG_DB, "a");

    if (ptr == NULL)
        exit(84);
    else {
        fprintf(ptr, "%s:%s:%lu:%s\n", dest_uid,
        uuid_to_str(cli[nb]->user.user_id), (unsigned long)time(NULL), msg);
    }
    fclose(ptr);
}

static int get_dest(client_t **cli, uuid_t receiver)
{
    int i = 0;

    for (i = 0; i < 1024; i++)
        if (uuid_compare(receiver, cli[i]->user.user_id) == 0)
            break;
    return i;
}

static void send_msg(client_t **cli, char *send_uid, char *msg, uuid_t receiver,
char *dest_uid)
{
    int i = get_dest(cli, receiver);

    dprintf(cli[i]->fd, "101 [%s:%s]\n", send_uid, msg);
    server_event_private_message_sended(send_uid, dest_uid, msg);
}

void send_func(client_t **cli, int nb, char **txt)
{
    char *dest_uid = NULL;
    char *msg = NULL;
    uuid_t receiver;
    size_t i = 0;

    if (count_tab(txt) < 2 || cli[nb]->user.username == NULL)
        return;
    if (get_info_to_str(txt[1]) == NULL)
        return;
    else {
        dest_uid = get_info_to_str(txt[1]);
        msg = get_msg_to_array(txt);
    }
    uuid_parse(dest_uid, receiver);
    send_msg(cli, uuid_to_str(cli[nb]->user.user_id), msg, receiver, dest_uid);
    write_to_msg_db(cli, nb, msg, dest_uid);
}