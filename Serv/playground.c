


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/queue.h>
#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255

/*typedef struct comment_s {
    char body[MAX_BODY_LENGTH];
} comment_t;

typedef struct thread_s {
    char *title;
    char *msg;
    uuid_t id;
    SLIST_ENTRY(struct comment_s) comments_list;
} thread_t ;

typedef struct channel_s {
    char  name[MAX_NAME_LENGTH];
    char desc[MAX_DESCRIPTION_LENGTH];
    uuid_t id;
    SLIST_ENTRY(struct thread_s) threads_list;
} channel_t;

*/
typedef struct channel_s {
    char str[MAX_NAME_LENGTH];
    SLIST_ENTRY(channel_s) next;
} channel_t;

typedef struct team_s {
    int id;
    SLIST_ENTRY(team_s) next;
    SLIST_ENTRY(channel_s) channels;
} team_t;


int main(int ac, char **av)
{
    SLIST_HEAD(, teams_t) head;
//    SLIST_HEAD(, channel_t) c_head;
    team_t *b = NULL;
    channel_t *c =NULL;
    SLIST_INIT(&head);

    for (int a = 0; a <= 20 ; a++) {
        b = malloc(sizeof(team_t));
        if (a == 3) {
            b->id = 42;
            SLIST_INSERT_HEAD(&head, b, next);
            continue;
        }
        b->id = a;

    //     for (int a = 0; a <= 5; a++) {
  //          c = malloc(sizeof(channel_t));
      //      c->str =  strdup(strcat("tutu", itoa(a));
//            SLIST_INSERT_HEAD(&c_head , c, next);
    //     }
         SLIST_INSERT_HEAD(&head, b, next);
    }


    SLIST_FOREACH(b, &head, next) {
        printf("Team #%d\n", b->id);

        SLIST_FOREACH(c, &c_head, next) {
            printf("\tstr ==> %s", b->channels->str)
        }
    }
    return (88);
}










