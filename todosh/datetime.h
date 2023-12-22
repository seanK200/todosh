#ifndef TSH_DATETIME_H
#define TSH_DATETIME_H

#include <stdio.h>
#include <time.h>

void tsh_fdate(time_t t, char *buffer);
void tsh_ftime(time_t t, char *buffer);

#endif
