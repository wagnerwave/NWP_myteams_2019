#include <stdio.h>
#include <unistd.h>
#include <sys/queue.h>
#include <stdlib.h>

/****   STRUCTURE   ****/

typedef struct channel_s {
    int id;
    struct channel_s *next;
} channel_t;

typedef struct team_s {
    int id;
    channel_t *channel;
    struct team_s *next;
} team_t;

/****   FUNCTION    ****/

static void init_teams(team_t *teams, int id)
{
    teams->id = id;
    teams->channel = malloc(sizeof(channel_t));
    teams->channel->id = 0;
    teams->channel->next = NULL;
}

static channel_t *add_channel(int id)
{
    channel_t *new_chan = malloc(sizeof(channel_t));

    if (new_chan == NULL) {
        printf("Error: Malloc failed for creating new channel.\n");
        exit(84);
    }
    new_chan->id = id;
    new_chan->next = NULL;
    return new_chan;
}

static void add_new_channel(team_t **teams, int id)
{
    channel_t *new_chan = add_channel(id);
    channel_t *last_chan = (*teams)->channel;

    while (last_chan->next != NULL)
        last_chan = last_chan->next;
    last_chan->next = new_chan;
}

static void display_all_channel_by_teams(team_t **teams)
{
    channel_t *tmp = (*teams)->channel;

    while (tmp->next != NULL) {
        printf("ID = %d\n", tmp->id);
        tmp = tmp->next;
    }
}

/****   MAIN    ****/

int main(int ac, char **av)
{
    team_t *teams = malloc(sizeof(team_t));

    init_teams(teams, rand());
    for (int i = 0; i < 10; i++) {
        add_new_channel(&teams, rand());
    }
    display_all_channel_by_teams(&teams);
    return 0;
}