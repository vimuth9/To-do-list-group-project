#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// #include "vimuth.h"  // functions to create,delete,view created list (List Management)
#include "hashan.h" // functions to add ,remove task from a selected list
// #include "dulaj.h"   // Display Task List and export to a text file non binary
#include "rivindu.h" // Filter task by date(Today,Tommorow) every thing related time
#include "nisindu.h" // Mark completed task and view and delete completed task

int main()
{

    int ch;
    while (1)
    {
        // system("cls");
        displayAllList(0);
        printf("\033[34m===============\033[1m List Management \033[0m\033[34m=================\n");
        printf("1. Create New List\n");
        printf("2. Delete List\n");
        printf("\033[34m===============\033[1m Task Related Commands \033[0m\033[34m=================\n");
        printf("3. Add Task\n");
        printf("4. Delete Task\n");

        printf("\n");
        printf("5. View Task List\n");
        printf("6. View All Task Lists\n");
        printf("\n");
        printf("7. Mark completed task\n");
        printf("8. View Completed task\n");
        printf("8. Delete Completed task\n");
        printf("\n");
        printf("9. by today/tommorow\n");
        printf("10. Filter by today/tommorow\n");

        printf("\n");
        printf("0. exit app\n");
        printf("==============================================\033[0m\n\n");
        printf("\033[33mInsert command: \033[0m");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            newlist(0);
            system("cls");
            break;
        case 2:
            system("cls");
            delList();
            system("cls");
            break;
        case 3:
            system("cls");
            addTask(0);
            break;
        case 4:
            system("cls");
            delTask(0);
            break;
        case 5:
            system("cls");
            displayAllList(1);
            char name[MAXLISTNAME];
            fetchListName(name);
            printf("file name returned %s", name);
            displayTask(name);
            break;
        case 6:
            system("cls");
            displayAllTask();
            break;
        case 0:
            system("cls");
            printf("Exitting app... \n\nHave a Nice Day\n\n");
            sleep(1);
            system("cls");
            return 0;
        default:
            printf("Command Not identified");
            sleep(1);
            system("cls");
            break;
        }
    }
}
