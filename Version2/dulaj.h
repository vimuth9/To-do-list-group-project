#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAXTITLE 40
#define MAXDISCRIPTION 40


struct Task
{
    int id;
    char title[MAXTITLE];
    int date;
    int status; // 1 for completed 0 for
    char des[MAXDISCRIPTION];
};

int displayTask(char name[MAXLISTNAME], int color);
void displayAllTask();
int exportList(char name[MAXLISTNAME], int x);
void exportAllLists();

int displayTask(char name[MAXLISTNAME], int color) // changes colour of the list when printing if the number is odd cyan and round to green
{
    FILE *fpl;
    struct Task t;
    int count = 0;
    char title[MAXTITLE];

    fpl = fopen(name, "rb");

    if (fpl == NULL)
    {
        // printf("file name = %s", name);
        printf("\033[31m Error! File cannot be found ! \033[0m\n");
        return 0;
    }
    color % 2 != 0 ? printf("\033[36m") : printf("\033[32m");
    printf("\n============= %s ==========================================\n", name);
    printf("| Status| ID\t| Due Date\t| Title\t\t| Description\n");
    printf("----------------------------------------------------------------------\n");
    while (1)
    {
        fread(&t, sizeof(t), 1, fpl);
        if (feof(fpl))
            break;
        if (sizeof(fpl) == 0)
            break;
        if (count == 20) // temporay
            break;
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
    // sleep(4);
    fclose(fpl);
    printf("======================================================================\n");
    printf("Task Count = %d \033[0m\n", count);
    return count;
}

void displayAllTask()
{
    system("cls");
    char name[MAXLISTNAME];
    int id = 1;
    int count = displayAllList();
    while (1)
    {
        fetchListNameByID(name, id);
        printf("List ID : %d\n",id);
        displayTask(name, id);
        if (id == count)
            break;
        id++;
    }
}
int exportList(char name[MAXLISTNAME], int x) // 0 to overwrite any othernumber to append
{
    FILE *fpl, *fe;
    struct Task t;
    int count = 0;
    char title[MAXTITLE];
    fpl = fopen(name, "rb");
    char fename[20] = "./Export/Export.txt";
    if (x == 0)
    {
        printf("\n\033[31m Overwriting \"Export.txt\" file.\033[0m\n");
        fe = fopen(fename, "w");
    }
    else
    {
        fe = fopen(fename, "a");
    }
    if (fpl == NULL)
    {
        // printf("file name = %s", name);
        printf("\033[31m Error! File cannot be found ! \033[0m\n");
        return 0;
    }
    fprintf(fe, "\n============= %s ============================================\n", name);
    fprintf(fe, "| Status| ID\t| Due Date\t| Title\t\t| Description\n");
    fprintf(fe, "----------------------------------------------------------------------\n");
    while (1)
    {
        fread(&t, sizeof(t), 1, fpl);
        if (feof(fpl))
            break;
        if (sizeof(fpl) == 0)
            break;
        if (count == 20) // temporay
            break;
        t.status == 0 ? fprintf(fe, "|\t\t| ") : fprintf(fe, "|  %d \t| ", t.status);
        fprintf(fe, "%d \t| ", t.id);
        fprintf(fe, "%d \t| ", t.date);
        fprintf(fe, "%s", t.title);
        int sizeTitle = strlen(t.title); // calculating the length of the title string
        // printf("%d", sizeTitle);
        sizeTitle < 7 ? fprintf(fe, "\t\t| ") : fprintf(fe, "\t| ");
        fprintf(fe, "%s \n", t.des);
        count++;
    }
    fprintf(fe, "======================================================================\n");
    fprintf(fe, "Task Count = %d \n", count);
    fclose(fpl);
    fclose(fe);
    return 0;
}
void exportAllLists()
{
    system("cls");
    char name[MAXLISTNAME];
    int id = 1;
    int count = displayAllList(1);
    while (1)
    {
        fetchListNameByID(name, id);
        exportList(name, id - 1);
        if (id == count)
            break;
        id++;
    }
}