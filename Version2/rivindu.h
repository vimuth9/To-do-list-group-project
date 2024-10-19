#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// #include "hashan.h"
// #include "dulaj.h"

int displayFilterTask(char name[MAXLISTNAME], int color, int date);
void displayAllFilterTask(int date);

#define MAXTITLE 40
#define MAXDESCRIPTION 40

int filterByDays()
{
    int command, date;
    printf("0  -  Today\n");
    printf("1  -  Tomorrow\n");
    printf("2  -  Day after Tomorrow\n");
    printf("Command:");
    scanf("%d", &command);
    date = calculateDueDate(command);
    displayAllFilterTask(date);
    return 0;
}

int displayFilterTask(char name[MAXLISTNAME], int color, int date) // changes colour of the list when printing if the number is odd cyan and round to green
{
    FILE *fpl;
    struct Task t;
    int count = 0, found = 0;
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
            break;
        if (sizeof(fpl) == 0)
            break;
        if (count == 20) // temporay
            break;
        if (t.date == date)
        {
            if (found == 0)
            {
                color % 2 != 0 ? printf("\033[36m") : printf("\033[32m");
                printf("\n============= %s ==========================================\n", name);
                printf("| Status| ID\t| Due Date\t| Title\t\t| Description\n");
                printf("----------------------------------------------------------------------\n");
                found++;
            };
            t.status == 0 ? printf("|\t| ") : printf("|  %d \t| ", t.status);
            printf("%d \t| ", t.id);
            printf("%d \t| ", t.date);
            printf("%s", t.title);
            int sizeTitle = strlen(t.title); // calculating the length of the title string
            // printf("%d", sizeTitle);
            sizeTitle < 7 ? printf("\t\t| ") : printf("\t| ");
            printf("%s \n", t.des);
            count++;
        }
    }
    // sleep(4);
    fclose(fpl);
    printf("======================================================================\n");
    printf("Task Count = %d \033[0m\n", count);
    return count;
}

void displayAllFilterTask(int date)
{
    system("cls");
    char name[MAXLISTNAME];
    int id = 1;
    int count = displayAllList();
    while (1)
    {
        fetchListNameByID(name, id);
        printf("\nList ID : %d", id);
        displayFilterTask(name, id, date);
        if (id == count)
            break;
        id++;
    }
}

/*
void checkListDays(char name[MAXLISTNAME])
{
    system("cls");
    time_t currentTime = time(NULL);
    struct tm *tm_info = localtime(&currentTime);

    // Get today's date
    int dateToday = (tm_info->tm_year + 1900) * 10000 + (tm_info->tm_mon + 1) * 100 + tm_info->tm_mday;

    // Add one day to the current date and normalize
    tm_info->tm_mday += 1;
    mktime(tm_info);
    int dateTomorrow = (tm_info->tm_year + 1900) * 10000 + (tm_info->tm_mon + 1) * 100 + tm_info->tm_mday;

    FILE *fpl;
    struct Task t;
    int count = 0;

    fpl = fopen(name, "rb");
    if (fpl == NULL)
    {
        printf("\033[31m Error! File cannot be found! \033[0m\n");
        return; // Exit the function if the file cannot be opened
    }

    printf(".............tasks due today.............\n");
    printf("\n============= %s ==========================================\n", name);
    printf("| Status| ID\t| Due Date\t| Title\t\t| Description\n");
    printf("----------------------------------------------------------------------\n");

    // Display tasks due today
    while (1)
    {
        if (feof)
        {
            break;
        }
        fread(&t, sizeof(t), 1, fpl) == 1;
        if (t.date == dateToday)
        {
            printf("%s\t| %d \t| ", (t.status == 0) ? " " : "X", t.id);
            printf("%d \t| ", t.date);
            printf("%s", t.title);
            printf("%*s| ", (strlen(t.title) < 7) ? 10 : 0, " ");
            printf("%s\n", t.des);
        }
    }

    // Reset file pointer to the beginning of the file for the next read
    rewind(fpl);
    count = 0; // Reset count for the next section

    printf(".............tasks due tomorrow.............\n");
    printf("\n============= %s ==========================================\n", name);
    printf("| Status| ID\t| Due Date\t| Title\t\t| Description\n");
    printf("----------------------------------------------------------------------\n");

    // Display tasks due tomorrow
    while (fread(&t, sizeof(t), 1, fpl) == 1)
    {
        if (t.date == dateTomorrow)
        {
            printf("%s\t| %d \t| ", (t.status == 0) ? " " : "X", t.id);
            printf("%d \t| ", t.date);
            printf("%s", t.title);
            printf("%*s| ", (strlen(t.title) < 7) ? 10 : 0, " ");
            printf("%s\n", t.des);
        }
    }

    fclose(fpl);
    printf("======================================================================\n");
}

*/