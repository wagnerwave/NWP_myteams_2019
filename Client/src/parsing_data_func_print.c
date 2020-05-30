/*
** EPITECH PROJECT, 2020
** my_teams client
** File description:
** parsing data func print
*/

#include <string.h>
#include <stdlib.h>
#include "logging_client.h"
#include "client.h"

void parsing_data_20_to_24(char *msg, int code)
{
    switch (code) {
        case 20:
            print_user_func(msg);
            break;
        case 21:
            print_team_func(msg);
            break;
        case 22:
            print_channel_func(msg);
            break;
        case 23:
            print_thread_func(msg);
            break;
        case 24:
            print_team_created_func(msg);
            break;
    }
    parsing_data_25_to_29(msg, code);
}

void parsing_data_25_to_29(char *msg, int code)
{
    switch (code) {
        case 25:
            print_channel_created_func(msg);
            break;
        case 26:
            print_thread_created_func(msg);
            break;
        case 27:
            print_reply_created_func(msg);
            break;
        case 28:
            print_subscribed_func(msg);
            break;
        case 29:
            print_unsubscribed_func(msg);
            break;
    }
    parsing_data_no_command(msg, code);
}