#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>

/*User Defined Functions Included in this project*/
void login();

void guide_text01();
void command_identifier01();

void add_task();
void remove_task();

void new_task_list(); // Finished
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
    guide_text01();
    command_identifier01();
}

/* Function to Print guide text */
void guide_text01()
{
    system("cls");
    printf("\033[34m //////////////// Guide ////////////////\n");
    printf(" -------------------------------------- \n");
    printf(" Command \t| Task \n");
    printf(" -------------------------------------- \n");
    printf(" add \t\t- Add task to list \n");
    printf(" remove  \t- Remove task from list \n");
    printf("\n");
    printf(" NewList  \t- Create New task list \n");
    printf("\n");
    printf(" MC \t\t- mark complete task from list \n");
    printf(" VC \t\t- View Completed task\n");
    printf("\n");
    printf(" Tod \t\t- View task to do today \n");
    printf(" Tom \t\t- View task to do Tommorow \n");
    printf("\n");
    printf(" logout \t- Logout from task \n");
    printf(" exit \t\t- Exit from task list \n");
    printf("\n");
    printf(" /////////////////////////////////////// \033[0m\n\n");
    command_identifier01();
}

/* Function to handle command identification */
void command_identifier01()
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
        command_identifier01();
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
/* Function to Create a new task list - Finished */
void new_task_list()
{
    system("cls");
    char ListDetails[100];
    char NewlistName[20];
    char NewFileName[50];
    char NewlistCategory[30];
    char dataPath[] = "./Data/"; // File path to the task lists and their information

    FILE *fpalist = fopen("./Data/TaskLists.txt", "r+");
    if (fpalist == NULL)
    {
        printf("Data file missing!\n");
        printf("New data file is being created...\n");
        fpalist = fopen("./Data/TaskLists.txt", "w+");
        if (fpalist == NULL)
        {
            perror("Failed to create TaskLists.txt");
            return;
        }
        sleep(1); // Use Sleep() on Windows
        system("cls");
    }

    printf("-------------------------------------------------\n");
    printf("File opened successfully.\n\n\033[41m Do not create a new list with the names below \033[0m\n");

    // Print content inside the text file
    fseek(fpalist, 0, SEEK_SET); // Move the file pointer to the beginning of the file
    char ch;
    while ((ch = fgetc(fpalist)) != EOF)
    {
        putchar(ch);
    }

    printf("-------------------------------------------------\n");
    printf("\033[43m\033[30m Do not include spaces bettween words \033[0m\n");
    printf("Insert name of the new list: ");
    scanf("%19s", NewlistName); // Limit input to 19 characters
    printf("Task Category: ");
    scanf("%29s", NewlistCategory);

    // Concatenate filename using strcpy and strcat
    strcpy(NewFileName, dataPath);
    strcat(NewFileName, NewlistName);
    strcat(NewFileName, ".txt");
    FILE *fpnlist = fopen(NewFileName, "w");
    if (fpnlist == NULL)
    {
        perror("Failed to create new list file");
        fclose(fpalist);
        return;
    }

    // Write to the files
    fprintf(fpalist, "%s - %s\n", NewlistName, NewlistCategory);
    fprintf(fpnlist, "///////////////// %s - %s /////////////////\n", NewlistName, NewlistCategory);

    // Close the files
    fclose(fpnlist);
    fclose(fpalist);

    // Call the guide text function
    guide_text01();
}
//--------------------------------------------------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------------------------------------------------

// Main function
void main()
{
    // login();  // uncomment this
    guide_text01();
}
