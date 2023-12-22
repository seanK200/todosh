#include <todosh/task.h>

struct tsh_dir *tsh_dir_init() {
    struct tsh_dir *dir;
    dir = (struct tsh_dir *)malloc(sizeof(struct tsh_dir));
    dir->id = -1;
    dir->path = NULL;
    dir->tasks = NULL;
    return dir;
}

void tsh_dir_free(struct tsh_dir *dir) {
    free(dir->path);
    free(dir);
}

struct tsh_task *tsh_task_init() {
    struct tsh_task *task;
    task = (struct tsh_task *)malloc(sizeof(struct tsh_task));
    task->id = -1;
    task->name = NULL;
    task->scheduled_at = -1;
    task->completed_at = -1;
    task->due_at = -1;
    task->dir = NULL;
    task->parent_id = -1;
    return task;
}

void tsh_task_free(struct tsh_task *task) {
    free(task->name);
    free(task);
}
