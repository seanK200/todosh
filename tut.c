#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int exec_callback(void *first, int ncols, char **cols, char **colnames);
int tut_sqlite3();
int tut_time();
int tut_task();

typedef struct tsh_task {
    int id;
    char *name;
    time_t created_at;
    time_t modified_at;
    time_t completed_at;
    time_t due_at;
    char *category;
    char **tags;
    char *desc;
} tsh_task;

int main() {
    // Welcome
    printf("todosh v0.0.1\n");

    int rc;

    rc = tut_sqlite3();
    if (rc != 0)
        return rc;

    rc = tut_time();
    if (rc != 0)
        return rc;

    rc = tut_task();
    if (rc != 0)
        return rc;

    return 0;
}

tsh_task *init_task(const char *name, const char *category, const char *desc) {
    tsh_task *task;
    task = (tsh_task *)malloc(sizeof(tsh_task));

    task->id = 1234;
    task->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(task->name, name);

    time(&(task->created_at));
    time(&(task->modified_at));

    task->completed_at = -1;
    task->due_at = -1;

    task->category = (char *)malloc(sizeof(char) * (strlen(category) + 1));
    strcpy(task->category, category);
    task->tags = NULL;
    task->desc = (char *)malloc(sizeof(char) * (strlen(desc) + 1));
    strcpy(task->desc, desc);

    return task;
}

void print_task(tsh_task *task) {
    for (int i = 0; i < 40; i++) {
        printf("-");
    }
    printf("\n");
    printf("Viewing task: %s/%d\n\n", task->category, task->id);

    printf("Name: %s\n", task->name);
    printf("Created at: %s", ctime(&(task->created_at)));
    printf("Modified at: %s", ctime(&(task->modified_at)));

    if (task->completed_at > 0) {
        printf("Completed: YES\n");
        printf("Completed at: %s\n", ctime(&(task->completed_at)));
    } else {
        printf("Completed: NO\n");
        printf("Completed at: -\n");
    }

    printf("Tags: -\n");

    printf("Description:\n%s\n", task->desc);
    for (int i = 0; i < 40; i++) {
        printf("-");
    }
    printf("\n");
}

void free_task(tsh_task *task) {
    free(task->name);
    free(task->category);
    free(task->desc);
    free(task);
}

int tut_task() {
    tsh_task *task = init_task("say hello", "/home", "first task");

    print_task(task);

    free_task(task);

    return 0;
}

int tut_time() {
    time_t t;
    time(&t);

    struct tm *gmt_tm = gmtime(&t);
    printf("Current time: %ld\n", t);
    printf("tm_sec      %d\n", gmt_tm->tm_sec);
    printf("tm_min      %d\n", gmt_tm->tm_min);
    printf("tm_hour     %d\n", gmt_tm->tm_hour);
    printf("tm_mday     %d\n", gmt_tm->tm_mday);
    printf("tm_mon      %d\n", gmt_tm->tm_mon);
    printf("tm_year     %d\n", gmt_tm->tm_year);
    printf("tm_wday     %d\n", gmt_tm->tm_wday);
    printf("tm_yday     %d\n", gmt_tm->tm_yday);

    char ftime[256];
    strftime(ftime, 256, "%y-%m-%d %H:%M:%S", gmt_tm);
    printf("%s\n", ftime);

    return 0;
}

int tut_sqlite3() {
    sqlite3 *db;
    int rc;

    printf("sqlite3: connecting... ");
    rc = sqlite3_open(":memory:", &db);
    if (rc == SQLITE_OK) {
        printf("SUCCESS\n");
    } else {
        printf("FAILED\n");
        sqlite3_close(db);
        return 1;
    }

    char *sql = "CREATE TABLE users(id INTEGER PRIMARY KEY, name TEXT);"
                "INSERT INTO users(name) VALUES('sean');"
                "INSERT INTO users(name) VALUES('jace');"
                "INSERT INTO users(name) VALUES('sunny');";
    char *err_msg;
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        printf("sqlite3: query execution FAILED\n%s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    int last_id = sqlite3_last_insert_rowid(db);
    printf("sqlite3: last inserted row id is '%d'\n", last_id);

    char *sql2 = "SELECT * FROM users;";
    int nrows = 0;
    rc = sqlite3_exec(db, sql2, exec_callback, (void *)&nrows, &err_msg);

    printf("Found %d rows.\n", nrows);

    if (rc != SQLITE_OK) {
        printf("sqlite3: query execution FAILED\n%s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    printf("sqlite3: closing... ");
    rc = sqlite3_close(db);
    if (rc == SQLITE_OK) {
        printf("SUCCESS\n");
    } else {
        printf("FAILED\n");
        return 1;
    }

    return 0;
}

int exec_callback(void *first, int ncols, char **cols, char **colnames) {
    int nrows = *((int *)first);
    *((int *)first) = nrows + 1;

    printf("ROW [%d]: ", nrows);
    for (int i = 0; i < ncols; i++) {
        printf("%s=%s  ", colnames[i], cols[i]);
    }
    printf("\n");

    return 0; // continue exec
}
