/*
** EPITECH PROJECT, 2020
** my_teams client
** File description:
** parsing data
*/

#include <string.h>
#include <stdlib.h>
#include "logging_client.h"
#include "client.h"

void parsing_data_1_to_5(char *msg, int code)
{
    switch (code) {
        case 120:
            login_func(msg);
            break;
        case 210:
            logout_func(msg);
            break;
        case 101:
            receive_msg_func(msg);
            break;
        case 4:
            thread_msg_receive_func(msg);
            break;
        case 5:
            event_team_created_func(msg);
            break;
    }
    parsing_data_6_to_10(msg, code);
}

void parsing_data_6_to_10(char *msg, int code)
{
    switch (code) {
        case 6:
            event_channel_created_func(msg);
            break;
        case 7:
            event_thread_created_func(msg);
            break;
        case 8:
            print_users_func(msg);
            break;
        case 9:
            print_teams_func(msg);
            break;
        case 10:
            team_print_channels_func(msg);
            break;
    }
    parsing_data_11_to_15(msg, code);
}

void parsing_data_11_to_15(char *msg, int code)
{
    switch (code) {
        case 11:
            channel_print_threads_func(msg);
            break;
        case 12:
            thread_print_replies_func(msg);
            break;
        case 304:
            private_message_print_messages_func(msg);
            break;
        case 14:
            error_unknown_team_func(msg);
            break;
        case 15:
            error_unknown_channel_func(msg);
            break;
    }
    parsing_data_16_to_19(msg, code);
}

void parsing_data_16_to_19(char *msg, int code)
{
    switch (code) {
        case 16:
            error_unknown_thread_func(msg);
            break;
        case 17:
            error_unknown_user_func(msg);
            break;
        case 18:
            error_unauthorized_func();
            break;
        case 19:
            error_already_exist_func();
            break;
    }
    parsing_data_20_to_24(msg, code);
}
