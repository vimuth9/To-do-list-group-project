#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// #include "dulaj.h"
// #include "vimuth.h"
// #include "hashan.h"

void markCompletedTask();
int markCompleteByID(char *name, int id);

void markCompletedTask()
{
    displayAllTask();
    int idl, idt;
    printf("Enter List ID: ");
    scanf("%d", idl);
    printf("Enter Task ID: ");
    scanf("%d", idt);
    char name[MAXLISTNAME];
    fetchListNameByID(name, idl);
    markCompleteByID(name, idt);
}

int markCompleteByID(char *name, int id)
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
            t.status = 1;
            fwrite(&t, sizeof(t), 1, ft);
        }
        else
        {
            fwrite(&t, sizeof(t), 1, ft);
            count++;
        }
    }
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
    printf("Task successfully marked complete.\n");
    sleep(1);
    system("cls");
    fclose(fp);
    fclose(ft);
    displayAllList();
    displayTask(name, 1);
    remove(temp2);
    return count;
}