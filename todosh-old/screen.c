#include <todosh/screen.h>

int tsh_screen_setup() {
    WINDOW *scr = initscr();
    if (scr == NULL) {
        return 1;
    }
    start_color();
    cbreak();
    noecho();
    nonl();
    intrflush(stdscr, FALSE);
    keypad(stdscr, TRUE);

    return 0;
}

void tsh_screen_cleanup() { endwin(); }
