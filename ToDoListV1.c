#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
/* Functions Include in this project*/

void login();
void guide_text();
void command_identifier();
void add_task();
void remove_task();

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
}

/* Function to Print guide text */
void guide_text()
{
    system("cls");
    printf("\033[31m //////////////// Guide ////////////////\n");
    printf(" -------------------------------------- \n");
    printf(" Command \t| Task \n");
    printf(" -------------------------------------- \n");
    printf(" add \t\t| Add task to list \n");
    printf(" remove  \t| Remove task from list \n");

    printf(" MC \t\t| mark complete task from list \n");
    printf(" VC \t\t| View Completed task\n");

    printf(" Tod \t\t| View task to do today \n");
    printf(" Tom \t\t| View task to do Tommorow \n");

    printf(" logout \t\t| Logout from task \n");
    printf(" exit \t\t| Exit from task list \n");

    printf(" /////////////////////////////////////// \033[0m\n\n");
}

/* Function to handle command identification */
void command_identifier()
{
    char command[20];                          // Changed to an array to store command strings
    printf("\033[33mInsert Command: \033[0m"); // Changed to yellow text
    scanf("%s", command);                      // Changed to %s to read a string

    if (strcmp(command, "add") == 0)
    { // Use strcmp to compare strings
        printf("Add task to list\n");
        add_task();
    }
    else if (strcmp(command, "remove") == 0)
    { // Use strcmp to compare strings
        printf("Remove task from List\n");
        add_task();
    }
    else if (strcmp(command, "MC") == 0)
    { // Use strcmp to compare strings
        printf("Mark Task Completed\n");
        add_task();
    }
    else if (strcmp(command, "VC") == 0)
    { // Use strcmp to compare strings
        printf("View Completed task so far\n");
        add_task();
    }
    else if (strcmp(command, "Tod") == 0)
    { // Use strcmp to compare strings
        printf("Task to do be done Today\n");
        add_task();
    }
    else if (strcmp(command, "Tom") == 0)
    { // Use strcmp to compare strings
        printf("Task to be done Tommorow\n");
        add_task();
    }
    else if (strcmp(command, "logout") == 0)
    { // Use strcmp to compare strings
        printf("exit function initiated\n");
        add_task();
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
/* Main Function */

int main()
{ // Changed void to int
    login();
    system("cls");
    guide_text();
    command_identifier(); // Call the command_identifier function

    return 0; // Return an integer value
}
