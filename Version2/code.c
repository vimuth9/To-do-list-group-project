#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// #include "vimuth.h"  // functions to create,delete,view created list (List Management)
#include "hashan.h" // functions to add ,remove task from a selected list
// #include "dulaj.h"   // Display Task List and export to a text file non binary
#include "nisindu.h" // Mark completed task and view and delete completed task
#include "rivindu.h" // Filter task by date(Today,Tommorow) every thing related time

void login();

int main()
{
    login();
    char name[MAXLISTNAME];
    int id;
    system("cls");
    displayAllList();
    int ch;
    while (1)
    {
        printf("\033[34m===============\033[1m Commands \033[0m\033[34m=========================================\n");
        printf("1. Create New List\n");
        printf("2. Delete List\n");
        printf("\n");
        printf("3. Export Selected List\n");
        printf("30. Export All Lists\n");

        printf("\n");
        printf("4. Add Task to a List\n");
        printf("5. Delete Task from a List\n");
        printf("\n");
        printf("6. View Tasks in a List\n");
        printf("60. View All Tasks Across Lists\n");
        printf("\n");
        printf("8. Mark Task as Complete\n");
        printf("80. View/Delete Completed Tasks\n");
        printf("\n");
        printf("9. View Tasks for Today/Tomorrow/Other\n");
        printf("\n");
        printf("99. Reset View\n");
        printf("0. Exit App\n");
        printf("=================================================================\033[0m\n\n");
        printf("\033[33mInsert command: \033[0m");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            newlist(0);
            system("cls");
            displayAllList();
            break;
        case 2:
            system("cls");
            delList();
            system("cls");
            displayAllList();
            break;
        case 3:
            system("cls");
            displayAllList();
            printf("\033[33mEnter List ID: \033[0m");
            scanf("%d", &id);
            fetchListNameByID(name, id);
            exportList(name, 0);
            printf("Export Successful\n");
            sleep(1);
            system("cls");
            displayAllList();
            break;
        case 30:
            exportAllLists();
            printf("Export Successful\n");
            sleep(1);
            system("cls");
            displayAllList();
            break;
        case 4:
            system("cls");
            addTask(0);
            break;
        case 5:
            system("cls");
            delTask(0);
            break;

        case 6:
            system("cls");
            displayAllList();

            printf("\033[33mEnter List ID: \033[0m");
            scanf("%d", &id);
            fetchListNameByID(name, id);
            displayTask(name, 1);
            break;
        case 60:
            system("cls");
            displayAllList(1);
            displayAllTask();
            break;
        case 8:
            markCompletedTask();
            break;
        case 80:
            // viewDeleteCompletedTasks();
            break;
        case 9:
            // filterByDays();
            break;
        case 99:
            system("cls");
            break;
        case 0:
            system("cls");
            printf("Exiting app... \n\nHave a Nice Day\n\n");
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

void login()
{
    system("cls"); // clear terminal <stdlib.h>
    const int correct_password = 1234;
    int password;
    do
    {
        printf("Enter password: ");
        scanf("%d", &password); // Removed the '/n' in the format specifier
    } while (password != correct_password);
    printf("Login Successful\n");
    sleep(1);      // Wait 1s
}