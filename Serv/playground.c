


#include <stdio.h>
#include <unistd.h>
#include <sys/queue.h>
#include <stdlib.h>

/****   STRUCTURE   ****/

typedef struct channel_t {
    int id;
    SLIST_ENTRY(channel_s) next;
} channel_t;

typedef struct team_t {
    int id;
    SLIST_HEAD(channel_head, channel_t) channels;
    SLIST_ENTRY(team_s) next;
} team_t;

/****   FUNCTION    ****/

static void init_teams(team_t *teams, int id)
{
    SLIST_INIT(&(teams->channels));
    teams->id = id;
}

static void add_new_channel(team_t *teams, int id)
{
    channel_t *new = calloc(1, sizeof(channel_t));
    new->id = id;
    SLIST_INSERT_HEAD(&(teams->channels), new, next);
}

/*static void free_channel(team_t *head)
{
    team_t *team;
    while (!SLIST_EMPTY(head)) {
        team = SLIST_FIRST(head);
        channel_t *chan;
        while(!SLIST_EMPTY(&(team->channel))) {
            chan = SLIST_FIRST(&(team->channel));
            free(chan);
            SLIST_REMOVE(&(team->channel), chan, channel);
        }
        free(team);
    }
}*/

/****   MAIN    ****/

int main(int ac, char **av)
{
    SLIST_HEAD(team_s, team_t) teams = SLIST_HEAD_INITIALIZER(teams);
    static team_t team_build;

    init_teams(&team_build, 40);

    for (int i = 0; i < 10; i++) {
        add_new_channel(&team_build, rand());
    }
    return 0;
}