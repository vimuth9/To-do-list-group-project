#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "vimuth.h" // functions to create,delete,view created list (List Management)
#include "dulaj.h"  // function to display the task separately and all

int addTask();
int delTask();
int calculateDueDate(int x); // returns a interger as a date

int addTask()
{
    int count = displayAllList(1);
    if (count == 0)
    {
        printf("\033[41m No List Detected\n Let's Create a List first \033[0m\n");
        newlist(); // Assuming newlist() creates a new list
        return 0;
    }

    FILE *fpl;
    struct Task t;

    // Fetching the file name ussing id
    char name[MAXLISTNAME];
    fetchListName(name); // ask for the id

    fpl = fopen(name, "ab");
    if (fpl == NULL)
    {
        printf("\033[41m Error! File cannot be found ! \033[0m\n");
        return 0;
    }

    t.id = displayTask( name) + 1; // calculate perfect id for the new task
    printf("New Task ID = %d", t.id);
    printf("Title: ");
    scanf("%s", &t.title);
    printf("Discription: ");
    scanf("%s", &t.des);
    int days;
    printf("Due date: ");
    scanf("%d", &days);
    t.date = calculateDueDate(days);
    t.status = 0;

    fwrite(&t, sizeof(t), 1, fpl);
    fclose(fpl);
    return 0;
}

int delTask()
{
    displayAllList(0);
    FILE *fpl;
    int id;
    struct Task t;

    // Fetching the file name from id
    char name[MAXLISTNAME];
    fetchListName(name);

    fpl = fopen(name, "ab");
    if (fpl == NULL)
    {
        printf("\033[41m Error! File cannot be found ! \033[0m\n");
        return 0;
    }
    displayTask(name);
}

int calculateDueDate(int x)
{
    int y;
    printf("return a date %d", x);
    y = x;
    return y;
}
