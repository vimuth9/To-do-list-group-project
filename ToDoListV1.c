#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>

/*User Defined Functions Included in this project*/
void login();
void guide_text1();
void command_identifier();
void add_task();
void remove_task();
void new_task_list();
void Mark_Completed();
void view_completed();
void view_today();
void view_tommorow();

/* Function to handle Login*/
void login()
{
    const int correct_password = 1234;
    int password;
    do
    {
        printf("Enter password: ");
        scanf("%d", &password); // Removed the '/n' in the format specifier
    } while (password != correct_password);
    printf("Login Successful\n");
    sleep(1);      // Wait 1s
    system("cls"); // clear terminal
    guide_text1();
    command_identifier();
}

/* Function to Print guide text */
void guide_text1()
{
    system("cls");
    printf("\033[31m //////////////// Guide ////////////////\n");
    printf(" -------------------------------------- \n");
    printf(" Command \t| Task \n");
    printf(" -------------------------------------- \n");
    printf(" add \t\t| Add task to list \n");
    printf(" remove  \t| Remove task from list \n");
    printf("\n");
    printf(" NewList  \t| Create New task list \n");
    printf("\n");
    printf(" MC \t\t| mark complete task from list \n");
    printf(" VC \t\t| View Completed task\n");
    printf("\n");
    printf(" Tod \t\t| View task to do today \n");
    printf(" Tom \t\t| View task to do Tommorow \n");
    printf("\n");
    printf(" logout \t| Logout from task \n");
    printf(" exit \t\t| Exit from task list \n");
    printf("\n");
    printf(" /////////////////////////////////////// \033[0m\n\n");
}

/* Function to handle command identification */
void command_identifier()
{
    char command[20];                           // Changed to an array to store command strings
    printf("\033[33m Insert Command: \033[0m"); // Changed to yellow text
    scanf("%s", command);                       // Changed to %s to read a string

    if (strcmp(command, "add") == 0)
    { // Use strcmp to compare strings
        printf("Add task to list\n");
        add_task();
    }
    else if (strcmp(command, "remove") == 0)
    { // Use strcmp to compare strings
        printf("Remove task from List\n");
        remove_task();
    }
    else if (strcmp(command, "NewList") == 0)
    { // Use strcmp to compare strings
        printf("create new list file\n");
        new_task_list();
    }
    else if (strcmp(command, "MC") == 0)
    { // Use strcmp to compare strings
        printf("Mark Task Completed\n");
        Mark_Completed();
    }
    else if (strcmp(command, "VC") == 0)
    { // Use strcmp to compare strings
        printf("View Completed task so far\n");
        view_completed();
    }
    else if (strcmp(command, "Tod") == 0)
    { // Use strcmp to compare strings
        printf("Task to do be done Today\n");
        view_today();
    }
    else if (strcmp(command, "Tom") == 0)
    { // Use strcmp to compare strings
        printf("Task to be done Tommorow\n");
        view_tommorow();
    }
    else if (strcmp(command, "logout") == 0)
    { // Use strcmp to compare strings
        printf("Logging out\n");
        sleep(1);
        system("cls");
        login();
    }
    else if (strcmp(command, "exit") == 0)
    { // Use strcmp to compare strings
        system("cls");
        printf("exiting from app\n");
        sleep(1);
        system("cls");
        exit(0);
    }
    else
    {
        printf("Unknown command\n");
    }
}

/* Function to add task to the list */
void add_task()
{
    printf("List Number:");
}

/* Function to remove task to the list */
void remove_task()
{
    printf("List Number:");
}
/* Function to Create a new task list */
void new_task_list()
{
    char NewlistName[20];
    char NewFileName[30];        // Adjust size to accommodate ".txt" and potential path
    char dataPath[] = "./Data/"; // Use a separate variable for the path

    printf("Insert name of the new list: ");
    scanf("%19s", NewlistName); // Limit input to 19 characters

    // Concatenate filename using strcpy and strcat
    strcpy(NewFileName, dataPath);
    strcat(NewFileName, NewlistName);
    strcat(NewFileName, ".txt");

    FILE *fplist = fopen(NewFileName, "w");
    if (fplist == NULL)
    {
        printf("Error creating file!\n");
        return;
    }

    fprintf(fplist, "Test text");
    fclose(fplist);
}

void Mark_Completed()
{
    printf("Functon to mark completed task");
}
void view_completed()
{
    printf("Function to View completed task");
}
void view_today()
{
    printf("Function to View task to be done today");
}
void view_tommorow()
{
    printf("Function to View task to be done tommorow");
}
/* Main function Function to Create a new task list */

int main()
{
    login();

    return 0; // Return an integer value
}
