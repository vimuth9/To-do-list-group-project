#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "vimuth.h" // functions to create,delete,view created list (List Management)
#include "dulaj.h"  // function to display the task separately and all

int addTask();
void delTask();
int deleteTaskByID(char *name, int id);
int calculateDueDate(int x); // returns a integer as a date

int addTask()
{
    int count = displayAllList();
    if (count == 0)
    {
        printf("\033[41m No List Detected\n Let's Create a List first \033[0m\n");
        newlist(); // newlist() creates a new list
        return 0;
    }

    FILE *fpl;
    struct Task t;

    // Fetching the file name using id
    char name[MAXLISTNAME];
    int id;
    printf("\033[33mEnter List ID: \033[0m");
    scanf("%d", &id);
    fetchListNameByID(name, id); // ask for the id

    fpl = fopen(name, "ab");
    if (fpl == NULL)
    {
        printf("\033[41m Error! File cannot be found ! \033[0m\n");
        return 0;
    }

    t.id = displayTask(name, 1) + 1; // calculate perfect id for the new task
    printf("New Task ID = %d\n", t.id);
    printf("\033[33mTitle: \033[0m");
    scanf("%s", &t.title);
    printf("\033[33mDescription: \033[0m");
    scanf("%s", &t.des);
    int days;
    printf("\033[33mDue date: \033[0m");
    scanf("%d", &days);
    t.date = calculateDueDate(days);
    t.status = 0;
    fwrite(&t, sizeof(t), 1, fpl);
    fclose(fpl);
    system("cls");
    displayAllList();
    displayTask(name, 1);
    return 0;
}

void delTask()
{
    displayAllList();
    // FILE *fpl;
    struct Task t;
    char name[MAXLISTNAME];
    int idl;
    printf("\033[33mEnter List ID: \033[0m");
    scanf("%d", &idl);
    fetchListNameByID(name, idl); // function defined in vimuth.h
    // printf("File name returned is%s", name);
    int id;
    displayTask(name, 1);
    printf("Enter Task id:");
    scanf("%d", &id);
    deleteTaskByID(name, id);
}

int deleteTaskByID(char *name, int id)
{
    FILE *fp, *ft;
    struct Task t;
    int count = 0, found = 0;
    fp = fopen(name, "rb");
    if (fp == NULL)
    {
        printf("Error opening file %s\n", name);
        return -1;
    }
    char temp2[10] = "temp2.dat";
    ft = fopen(temp2, "wb");
    while (1)
    {
        fread(&t, sizeof(t), 1, fp);

        if (feof(fp))
        {
            break;
        }
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
        printf("\033[41mTask not founded\033[0m");
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
    printf("Successfully Deleted\n");
    sleep(1);
    system("cls");
    fclose(fp);
    fclose(ft);
    displayAllList();
    displayTask(name, 1);

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
    int newDate = (tm.tm_year + 1900) * 10000 + (tm.tm_mon + 1) * 100 + tm.tm_mday; // adding 1900 because time libary counting years from 1900
    return newDate;
}
