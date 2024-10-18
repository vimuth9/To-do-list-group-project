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

int viewCompletedTask(char name[MAXLISTNAME], int color);
void viewAllCompletedTask();

void deleteAllCompletedTask();

void markCompletedTask()
{
    displayAllTask();
    int idl, idt;
    printf("\n\033[33mEnter List ID: \033[0m");
    scanf("%d", &idl);
    printf("\033[33mEnter Task ID: \033[0m");
    scanf("%d", &idt);
    char name[MAXLISTNAME];
    fetchListNameByID(name, idl);
    printf("%s", name);
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

int viewCompletedTask(char name[MAXLISTNAME], int color) // changes colour of the list when printing if the number is odd cyan and round to green
{
    FILE *fpl;
    struct Task t;
    int count = 0, line = 0;
    char title[MAXTITLE];

    fpl = fopen(name, "rb");

    if (fpl == NULL)
    {
        // printf("file name = %s", name);
        printf("\033[31m Error! File cannot be found ! \033[0m\n");
        return 0;
    }

    while (1)
    {
        fread(&t, sizeof(t), 1, fpl);
        if (feof(fpl))
        {
            fclose(fpl);
            printf(" ======================================================================\n");
            printf("Task Count = %d \033[0m\n", count);
            break;
        }
        if (sizeof(fpl) == 0)
            break;
        if (count == 20) // temporay
            break;
        if (t.status != 0)
        {
            if (line == 0)
            {
                color % 2 != 0 ? printf("\033[36m") : printf("\033[32m");
                printf("\n============= %s ==========================================\n", name);
                printf("| Status| ID\t| Due Date\t| Title\t\t| Description\n");
                printf("----------------------------------------------------------------------\n");
                line++;
            }

            printf("|  %d \t| ", t.status);
            printf("%d \t| ", t.id);
            printf("%d \t| ", t.date);
            printf("%s", t.title);
            count++;
            int sizeTitle = strlen(t.title); // calculating the length of the title string
            // printf("%d", sizeTitle);
            sizeTitle < 7 ? printf("\t\t| ") : printf("\t| ");
            printf("%s \n", t.des);
        }
    }
    // sleep(4);

    return count;
}
void viewAllCompletedTask()
{
    system("cls");
    char name[MAXLISTNAME];
    int id = 1;
    int count = displayAllList();
    while (1)
    {
        fetchListNameByID(name, id);
        printf("\nList ID : %d", id);
        viewCompletedTask(name, id);
        if (id == count)
            break;
        id++;
    }
}

int deleteCompletedTask(char *name)
{
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
            if (t.status == 1)
            {
                found++;
            }
            else if (found >= 1)
            {
                t.id = t.id - found;
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
            printf("No completed task in %s", name);
        fclose(fp);
        fclose(ft);
        if (found == 0)
            printf("\033[41mCompleted Task not founded\033[0m");
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
        remove(temp2);
        return count;
    }
    printf("successfully deleted completed task");
}

void deleteAllCompletedTask()
{
    system("cls");
    char name[MAXLISTNAME];
    int id = 1;
    int count = displayAllList();
    while (1)
    {
        fetchListNameByID(name, id);
        printf("\nList ID : %d", id);
        deleteCompletedTask(name);
        if (id == count)
            break;
        id++;
    }
}