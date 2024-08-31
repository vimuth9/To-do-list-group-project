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

int displayTask( char name[MAXLISTNAME]) // 1 to displayAllList and neglect input name
{
    FILE *fpl;
    struct Task t;
    int count = 0;
    char title[MAXTITLE];


    fpl = fopen(name, "rb");
    
    if (fpl == NULL)
    {
        // printf("file name = %s", name);
        printf("\033[41m Error! File cannot be found ! \033[0m\n");
        return 0;
    }

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
        if (count == 20) // temapaary
            break;
        printf("%d \t| ", t.status);
        printf("%d \t| ", t.id);
        printf("%d \t| ", t.date);
        printf("%s \t| ", t.title);
        printf("%s \n", t.des);
        count++;
    }
    // sleep(4);
    fclose(fpl);
    printf("================================================\n");
    printf("Task Count = %d\n", count);
    return count;
}

void displayAllTask()
{
    printf("Display all task");
}
