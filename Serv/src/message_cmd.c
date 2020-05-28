/*
** EPITECH PROJECT, 2020
** myteams server
** File description:
** commands messages
*/

#include <uuid/uuid.h>
#include <stdio.h>
#include "logging_server.h"
#include "server.h"

void send_func(client_t **cli, int nb, char **txt)
{
    char *dest_uid = NULL;
    char *msg = NULL;
    uuid_t receiver;
    size_t i = 0;

    if (count_tab(txt) < 2)
        return;
    if (get_info_to_str(txt[1]) == NULL)
        return;
    else {
        dest_uid = get_info_to_str(txt[1]);
        msg = get_msg_to_array(txt);
    }
    uuid_parse(dest_uid, receiver);
    for (i = 0; i < 1024; i++)
        if (uuid_compare(receiver, cli[i]->user.user_id) == 0)
            break;
    dprintf(cli[i]->fd, "101 [%s:%s]\n", uuid_to_str(cli[nb]->user.user_id),
    msg);
    server_event_private_message_sended(uuid_to_str(cli[nb]->user.user_id),
    dest_uid, msg);
}