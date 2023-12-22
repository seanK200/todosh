# Todosh: Task Manager for the CLI gurus

## Contents

## Features

Todosh uses UNIX-like commands to manage todo lists. Think of `tasks` as files, and `categories` as directories.

- Categorize tasks
- Assign tags for searching, bulk management, stats
- Date/time settings for each task

## Usage

```
todo [<command>] [<options>] [--] [<path>]

Options:
    --today


    -e<timestr>, --end<timestr>, --before<timestr>


    -s<timestr>, --start<timestr>, --after<timestr>
        

```


```
todo [<command>] [<options>] [--] [<path>]

Arguments:
    [<path>]
        Limit search to given path

Commands:
    list        List existing tasks. (Default)
    ls          (Alias to `list`)
    create      Create a new task
    edit        Modify one or more existing task(s).
    delete      Remove one or more existing task(s).
    rm          (Alias to `delete`)

Options:
    -s, --scheduled
        Only display scheduled tasks

    -u, --unscheduled
        Only display unscheduled tasks

    -a, --all
        Display all tasks, including completed tasks.

    -f<query>, --find<query>
        Search existing tasks by id, name and description with <query>

    -n --name <query>
        Search existing tasks by name

    --desc <query>
        Search existing tasks by description

    -I --id <query>
        Search existing tasks by id

    -B <timestring>, --before <timestring>
        Filter scheduled tasks that are scheduled before <timestring>

    -A <timestring>, --after <timestring>
        Filter scheduled tasks that are scheduled after <timestring>

    -L[<limit>] --limit[=<limit>]
        Limit the total number of results found. Defaults to 50.

    --one
        Equivalent to `-L 1`

    -U[<timerange>] --urgent[=<timerange>]
        Filter tasks that have a due date that is less than <timerange> left. <timerange> defaults to "6h".

    -S<fields>, --sort=<fields>
        Sort by <fields>. <fields> should be a comma-separated list of valid task "fields", and the sort order (optional, defaults to ASC). Defaults to: "schedule,due DESC,id"

    -p --plain
        Output result to stdout in plain text (no control characters)

    --no-screen
        Equivalent to '-p'

    -v --verbose
        Output all task attributes, including descriptions

    --vim
        Use vim-like keyboard mappings in screen mode

    --char
        Do not use any special characters
```

## Notes

### Task Properties

- ID
- Name
- Completed at
- Created at
- Modified at
- Due at
- Category
- Tags
- Description

