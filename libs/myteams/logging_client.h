/*
** EPITECH PROJECT, 2020
** my teams
** File description:
** Logging client
*/

#ifndef __LOGGING_CLIENT_H__
#define __LOGGING_CLIENT_H__

#include <stdint.h>
#include <time.h>

//! Handler called when a user connect to the server (you or someone else) 001
int client_event_loggedin(char const *u_id, const char *u_name);

//! Handler called when a user disconnect from the server(youorsomeone else)002
int client_event_loggedout(char const *u_id, const char *u_name);

//! Handler called when a new private message is received 003
int client_event_private_message_received(char const *u_id,
char const *m_body);

//! Handler called when a new reply is post in a thread 004
int client_event_thread_message_received(char const *t_id, char const *th_id,
char const *u_id, char const *m);

//! Handler called when a new team is created 005
int client_event_team_created(char const *t_id, char const *t_name,
char const *t_description);

//! Handler called when a new channel is created 006
int client_event_channel_created(char const *c_id, char const *c_name,
char const *c_description);

//! Handler called when a new thread is created 007
int client_event_thread_created(char const *thread_id, char const *user_id,
time_t thread_timestamp, char const *thread_title, char const *thread_body);

//! Handler called when the user ask for the users list (/list CLI command) 008
int client_print_users(char const *user_id, char const *user_name,
int user_status);

//! Handler called when the user ask for the team list (/list CLI command), 009
int client_print_teams(char const *team_id, char const *team_name,
char const *team_description);

//! Handler called when the user select a specific team to be in 010
int client_team_print_channels(char const *channel_id,
char const *channel_name, char const *channel_description);

//! Handler called when the user select a specific channel to be in 011
int client_channel_print_threads(char const *thread_id, char const *user_id,
time_t thread_timestamp, char const *thread_title, char const *thread_body);

//! Handler called when the user ask for a specific thread 0012
int client_thread_print_replies(char const *thread_id, char const *user_id,
time_t reply_timestamp, char const *reply_body);

//! Handler called when the user ask for a specific private discussion 013
int client_private_message_print_messages(char const *sender_id,
time_t timestamp, char const *message);

//! Handler called when the user ask for an unknown specific team 014
int client_error_unknown_team(char const *team_id);

//! Handler called when the user ask for an unknown specific channel 015
int client_error_unknown_channel(char const *channel_id);

//! Handler called when the user ask for an unknown specific thread 016
int client_error_unknown_thread(char const *thread_id);

//! Handler called when the user want to chat with an unknown user 017
int client_error_unknown_user(char const *user_id);

//! Handler called when the user want to perform an action 018
int client_error_unauthorized(void);

//! Handler called when the user want to perform an action that was refused 019
int client_error_already_exist(void);

//! Handler called when the user ask for a user in particular 020
int client_print_user(char const *user_id, char const *user_name,
int user_status);

//! Handler called when the user ask for a team in particular 021
int client_print_team(char const *team_id, char const *team_name,
char const *team_description);

//! Handler called when the user ask for a channel in particular 022
int client_print_channel(char const *channel_id, char const *channel_name,
char const *channel_description);

//! Handler called when the user ask for a thread in particular 023
int client_print_thread(char const *thread_id, char const *user_id,
time_t thread_timestamp, char const *thread_title, char const *thread_body);

//! Handler called when the user create a team (/create CLI command) 024
int client_print_team_created(char const *team_id,
char const *team_name, char const *team_description);

//! Handler called when the user create a channel (/create CLI command) 025
int client_print_channel_created(char const *channel_id,
char const *channel_name, char const *channel_description);

//! Handler called when the user create a thread (/create CLI command) 026
int client_print_thread_created(char const *thread_id, char const *user_id,
time_t thread_timestamp, char const *thread_title, char const *thread_body);

//! Handler called when the user create a reply (/create CLI command) 027
int client_print_reply_created(char const *thread_id,
char const *user_id, time_t reply_timestamp, char const *reply_body);

//! Handler called when the user create a reply (/subscribe CLI command) 028
int client_print_subscribed(char const *user_id, char const *team_id);

//! Handler called when the user create a reply (/unsubscribe CLI command) 029
int client_print_unsubscribed(char const *user_id, char const *team_id);

#endif /* __LOGGING_CLIENT_H__ */
