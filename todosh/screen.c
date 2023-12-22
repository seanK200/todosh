#include <todosh/screen.h>

int tsh_initscr() {
    WINDOW *scr = initscr();
    if (scr == NULL) {
        return 1;
    }

    start_color();
    use_default_colors();
    noecho();
    cbreak();

    return 0;
}

void tsh_endscr() {
    echo();
    nocbreak();
    endwin();
}
//
// move(2, 1);
// printw("/");
//
// int quit = 0;
// move(4, 1);
// printw("%d x %d", COLS, LINES);
//
// int ch;
// while (!quit) {
//     ch = getch();
//
//     if (ch == KEY_RESIZE) {
//         move(4, 1);
//         printw("%d x %d", COLS, LINES);
//     } else if (ch == 'q') {
//         quit = 1;
//     }
// }
