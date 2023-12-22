#include <todosh/datetime.h>

char MONTHS[12][3] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN",
                      "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};

void pad_num(char *buf, int n) {
    if (n < 10) {
        sprintf(buf, "0%d", n);
    } else {
        sprintf(buf, "%d", n);
    }
}

// Format the given time `t`, and store the formatted string at `buffer`
void tsh_fdate(time_t t, char *buffer) {
    struct tm *tt = localtime(&t);

    char f_mday[3] = "";
    pad_num(f_mday, tt->tm_mday);

    sprintf(buffer, "%s %s", MONTHS[tt->tm_mon], f_mday);
}

// Format the given time 't' as 'month-date hour:minute'
void tsh_ftime(time_t t, char *buffer) {
    struct tm *tt = localtime(&t);
    char f_mday[3] = "";
    pad_num(f_mday, tt->tm_mday);

    sprintf(buffer, "%s %d %d:%d", MONTHS[tt->tm_mon], tt->tm_mday, tt->tm_hour,
            tt->tm_min);
}
