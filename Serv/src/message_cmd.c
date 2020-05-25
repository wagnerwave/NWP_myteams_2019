/*
** EPITECH PROJECT, 2020
** myteams server
** File description:
** commands messages
*/

#include <uuid/uuid.h>
#include "logging_server.h"
#include "server.h"

void send_func(client_t **cli, int nb, char **txt)
{
    uuid_t receiver;
    size_t i = 0;

    uuid_parse(txt[1], receiver);
    for (i = 0; i < 1024; i++) {
        if (uuid_compare(receiver, cli[i]->user.user_id) == 0)
            break;
    }
    dprintf(cli[i]->fd, "010 [%s:%s]\n", uuid_to_str(cli[nb]->user.user_id),
    txt[2]);
    server_event_private_message_sended(uuid_to_str(cli[nb]->user.user_id),
    txt[1], txt[2]);
}