#ifndef TSH_DB_H
#define TSH_DB_H

#include <sqlite3.h>
#include <todosh/task.h>

struct tsh_task **tsh_find_tasks();
struct tsh_task *tsh_find_task_by_id(int id);
struct tsh_task *tsh_find_task_by_name(char *name);

#endif
