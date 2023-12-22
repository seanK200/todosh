#ifndef TSH_TASK_H
#define TSH_TASK_H

#include <stdlib.h>
#include <time.h>

struct tsh_dir {
    int id;
    char *path;
    struct tsh_task **tasks;
};

struct tsh_task {
    int id;
    char *name;
    time_t completed_at;
    time_t scheduled_at;
    time_t due_at;
    struct tsh_dir *dir;
    int parent_id;
};

struct tsh_dir *tsh_dir_init();
void tsh_dir_free(struct tsh_dir *dir);
struct tsh_task *tsh_task_init();
void tsh_task_free(struct tsh_task *task);

#endif
