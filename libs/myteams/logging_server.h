/*
** EPITECH PROJECT, 2020
** my teams
** File description:
** Logging server
*/

#ifndef __LOGGING_SERVER_H__
#define __LOGGING_SERVER_H__

#include <stdint.h>
#include <time.h>

/*
	Because of the norme, the line can't be over 80 characteres. so :
	t = teams
	th = thread
	c = channel
	u = user
	m = message
	s = sender
	r = recever
*/
//! Handler called when a new team is created
int server_event_team_created(char const *t_id, char const *t_name,
char const *u_id);

//! Handler called when a channel is created
int server_event_channel_created(char const *t_id, char const *c_id,
char const *c_name);

//! Handler called when a thread is created
int server_event_thread_created(char const *c_id, char const *th_id,
char const *u_id, char const *m);

//! Handler called when a message is post in a thread
int server_event_thread_new_message(char const *th_id, char const *u_id,
char const *m);

//! Handler called when a user join a team
int server_event_user_join_a_team(char const *t_id, char const *u_id);

//! Handler called when a user leave a team
int server_event_user_leave_a_team(char const *t_id, char const *u_id);

//! Handler called when a user is created
int server_event_user_created(char const *u_id, char const *u_name);

//! Handler called when a user is reloaded (on server startup)
int server_event_user_loaded(char const *u_id, char const *u_name);

//! Handler called when a user is logging in
int server_event_user_logged_in(char const *u_id);

//! Handler called when a user is logging out
int server_event_user_logged_out(char const *u_id);

//! Handler called when a user send a private message to an other
int server_event_private_message_sended(char const *s_id, char const *r_id,
char const *m);

#endif /* __LOGGING_SERVER_H__ */
