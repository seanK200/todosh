#include <ncurses.h>
#include <time.h>
#include <todosh/screen.h>
#include <todosh/task.h>

int main() {
    int rc;
    rc = tsh_initscr();
    if (rc != 0) {
        return 1;
    }

    printw("todosh");

    // Init tasks
    struct tsh_task *task1 = tsh_init_task();
    struct tsh_task *task2 = tsh_init_task();
    task1->id = 1;
    task1->name = "First task";
    // time(&(task1->due_at));

    task2->id = 2;
    task2->name = "Call SSN office";
    time(&(task2->due_at));
    time(&(task2->completed_at));

    // Render tasks
    move(2, 0);
    tsh_draw_task(task1);
    move(3, 0);
    tsh_draw_task(task2);

    // Wait for user input
    getch();

    // Clean up
    tsh_free_task(task1);
    tsh_free_task(task2);
    tsh_endscr();
    return 0;
}
