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
    teams->channel = NULL;
    teams->next = NULL;struct channel_s *next;
}

static team_t *create_teams(int id)
{
    team_t *new_team = malloc(sizeof(team_t));

    if (new_team == NULL) {
        printf("Error: Malloc failed for creating new team.\n");
        exit(84);
    }
    new_team->id = id;
    new_team->channel = malloc(sizeof(channel_t));
    if (new_team->channel == NULL) {
        printf("Error: Malloc failed for creating new channel.\n");
        exit(84);
    }
    new_team->next = NULL;
    return new_team;
}

static void add_new_team(team_t **teams, int id)
{
   team_t *new_team = create_teams(id);
   team_t *last = *teams;

   if (*teams == NULL) {
       *teams = new_team;
        return;
   }
   while (last->next != NULL)
        last = last->next;
    last->next = new_team;
}

static team_t **get_team_by_id(team_t **teams, int id)
{
    team_t *tmp = *teams;

    while (tmp->next != NULL && tmp->id != id) {
        tmp = tmp->next;
    }
    return &tmp;
}

static channel_t *create_channel(int id)
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
    channel_t *new_chan = create_channel(id);
    channel_t *chan = (*teams)->channel;

    if (chan == NULL) {
        (*teams)->channel = create_channel(id);
        return;
    }
    while (chan->next != NULL)
        chan = chan->next;
    chan->next = new_chan;
}

static void display_all_channel_by_teams(team_t **teams)
{
    channel_t *tmp = (*teams)->channel;
    int i = 0;
    printf("IN TEAMS ID = %d\n", (*teams)->id);
    while (tmp->next != NULL) {
        printf("ID = %d\n", tmp->id);
        tmp = tmp->next;
        i++;
    }
    printf("===================[%d]\n", i);
}

static void display_all_teams(team_t **teams)
{
    team_t *tmp = *teams;
    while (tmp->next != NULL) {
        printf("ID Teams = %d\n", tmp->id);
        tmp = tmp->next;
    }
     printf("ID Teams = %d\n", tmp->id);
}

static void remove_channel_by_uuid(team_t **teams, int id)
{
    channel_t *tmp = (*teams)->channel, *prev;

    if (tmp != NULL && tmp->id == id) {
        (*teams)->channel = tmp->next;
        free(tmp);
        return;
    }
    while (tmp != NULL && tmp->id != id) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return;
    prev->next = tmp->next;
    free(tmp);
}

/****   MAIN    ****/

int main(int ac, char **av)
{
    team_t *teams = malloc(sizeof(team_t));

    init_teams(teams, 1);
    add_new_team(&teams, 2);
    add_new_team(&teams, 3);
    add_new_team(&teams, 4);
    display_all_teams(&teams);
    for (int i = 0; i < 5; i++)
        add_new_channel(&teams, rand());
    display_all_channel_by_teams(&teams);
    for (int i = 0; i < 5; i++);
        add_new_channel(get_team_by_id(&teams, 2), rand());
    display_all_channel_by_teams(&teams);
    display_all_channel_by_teams(get_team_by_id(&teams, 2));
    return 0;
}