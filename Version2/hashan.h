#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "vimuth.h" // functions to create,delete,view created list (List Management)
#include "dulaj.h"  // function to display the task separately and all

int addTask();
int delTask();
int deleteTaskByID(char *name, int id);
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

    t.id = displayTask(name) + 1; // calculate perfect id for the new task
    printf("New Task ID = %d\n", t.id);
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

    // Fetching the file name
    char name[MAXLISTNAME];
    fetchListName(name); // function defined in vimuth.h

    fpl = fopen(name, "ab");
    if (fpl == NULL)
    {
        printf("\033[41m Error! File cannot be found ! \033[0m\n");
        return 0;
    }
    displayTask(name);
    printf("Enter id:");
    scanf("%d", &id);
    deleteTaskByID(name, id);
}
int deleteTaskByID(char *name, int id)
{
    FILE *fp, *ft;
    struct Task t;
    int count = 0, found = 0;
    fp = fopen("name", "rb");
    char temp2[] = "temp2.dat";
    ft = fopen(temp2, "wb");
    while (1)
    {
        fread(&t, sizeof(t), 1, fp);

        if (feof(fp))
            break;

        if (t.id == id)
        {
            found = 1;
        }
        else if (found == 1)
        {
            t.id = t.id - 1;
            fwrite(&t, sizeof(t), 1, ft);
            count++;
        }
        else
        {
            fwrite(&t, sizeof(t), 1, ft);
            count++;
        }
    }
    if (found == 0)
        printf("task not found");
    fclose(fp);
    fclose(ft);
    if (found == 0)
        printf("list not founded");
    else
    {
        fp = fopen(name, "wb");
        ft = fopen(temp2, "rb");
        while (1)
        {
            fread(&t, sizeof(t), 1, ft);
            if (feof(ft))
                break;

            fwrite(&t, sizeof(t), 1, fp);
        }
    }
    printf("\nCompleted permanantly deleting List\\s\n");
    sleep(1);
    fclose(fp);
    fclose(ft);
    return count;
}

int calculateDueDate(int days)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Add the number of days to the current date
    tm.tm_mday += days;
    // Normalize the time structure
    mktime(&tm);
    // Format the date as YYYYMMDD
    int newDate = (tm.tm_year + 1900) * 10000 + (tm.tm_mon + 1) * 100 + tm.tm_mday; // adding 1900 becouse time libery counting years from 1900
    return newDate;
}
