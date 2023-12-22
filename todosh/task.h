#ifndef TSH_TASK_H
#define TSH_TASK_H

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <todosh/datetime.h>

struct tsh_task {
    int id;
    char *name;
    time_t completed_at;
    time_t due_at;
};

struct tsh_task *tsh_init_task();
void tsh_draw_task(struct tsh_task *task);
void tsh_free_task(struct tsh_task *task);

#endif
