#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// #include "vimuth.h"
// #include "dulaj.h"

#define MAXTITLE 40
#define MAXDESCRIPTION 40

void filterByDays(char name[MAXLISTNAME]) {  
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
    if (fpl == NULL) {
        printf("\033[31m Error! File cannot be found! \033[0m\n");
        return; // Exit the function if the file cannot be opened
    }

    printf(".............tasks due today.............\n");
    printf("\n============= %s ==========================================\n", name);
    printf("| Status| ID\t| Due Date\t| Title\t\t| Description\n");
    printf("----------------------------------------------------------------------\n");

    // Display tasks due today
    while (fread(&t, sizeof(t), 1, fpl) == 1) {
        if (t.date == dateToday) {
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
    while (fread(&t, sizeof(t), 1, fpl) == 1) {
        if (t.date == dateTomorrow) {
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