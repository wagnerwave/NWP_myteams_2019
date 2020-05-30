/*
** EPITECH PROJECT, 2020
** myteams_client
** File description:
** structure
*/

#include "client.h"

const inter_cmd_t icmd[] = {
    {120, &login_func},
    {210, &logout_func},
    {101, &receive_msg_func},
    {4, &thread_msg_receive_func},
    {5, &event_team_created_func},
    {6, &event_channel_created_func},
    {7, &event_thread_created_func},
    {8, &print_users_func},
    {9, &print_teams_func},
    {10, &team_print_channels_func},
    {11, &channel_print_threads_func},
    {12, &thread_print_replies_func},
    {304, &private_message_print_messages_func},
    {14, &error_unknown_team_func},
    {20, &print_user_func},
    {21, &print_team_func},
    {22, &print_channel_func},
    {23, &print_thread_func},
    {24, &print_team_created_func},
    {25, &print_channel_created_func},
    {26, &print_thread_created_func},
    {27, &print_reply_created_func},
    {28, &print_subscribed_func},
    {29, &print_unsubscribed_func},
    {500 ,&error_unknown_channel_func},
    {500, &error_unknown_thread_func},
    {500, &error_unknown_user_func},
    {500, &error_unauthorized_func},
    {500, &error_already_exist_func},
    {0, NULL}
};