#include <todosh/task.h>

struct tsh_task *tsh_init_task() {
    struct tsh_task *task;
    task = (struct tsh_task *)malloc(sizeof(struct tsh_task));

    task->id = -1;
    task->name = NULL;
    task->completed_at = -1;
    task->due_at = -1;

    return task;
}

// Draw a given task to the screen at the current cursor location
void tsh_draw_task(struct tsh_task *task) {
    // Complete marker [ ] or [x]
    char completed;

    if (task->completed_at >= 0) {
        completed = 'x';
    } else {
        completed = ' ';
    }

    printw("[%c] %s", completed, task->name);
    int cy, cx;
    getyx(stdscr, cy, cx);
    move(cy, COLS - 13);

    if (task->due_at >= 0) {
        char f_due_at[13];
        tsh_ftime(task->due_at, f_due_at);
        printw("%s", f_due_at);
    } else {
        printw("-");
    }
}

void tsh_free_task(struct tsh_task *task) {
    // if (task->name != NULL) {
    //     free(task->name);
    // }
    free(task);
}
