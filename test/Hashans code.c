
#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 100

typedef struct {
    char description[MAX_LENGTH];
} Task;

Task tasks[MAX_TASKS];
int taskCount = 0;

// Function to add a task
void addTask(Task tasks[], int *taskCount) {
    if (*taskCount >= MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }
    printf("Enter the task description: ");
    scanf(" %[^\n]", tasks[*taskCount].description);
    (*taskCount)++;
    printf("Task added successfully.\n");
}

// Function to remove a task
void removeTask(Task tasks[], int *taskCount) {
    int taskNumber;
    printf("Enter the task number to remove: ");
    scanf("%d", &taskNumber);

    if (taskNumber < 1 || taskNumber > *taskCount) {
        printf("Invalid task number!\n");
        return;
    }

    // Shift tasks to remove the specified task
    for (int i = taskNumber - 1; i < *taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    (*taskCount)--;
    printf("Task removed successfully.\n");
}

// Function to display all tasks
void displayTasks(Task tasks[], int taskCount) {
    if (taskCount == 0) {
        printf("No tasks to display.\n");
        return;
    }
    printf("Tasks:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s\n", i + 1, tasks[i].description);
    }
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. View Tasks\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask(tasks, &taskCount);
                break;
            case 2:
                removeTask(tasks, &taskCount);
                break;
            case 3:
                displayTasks(tasks, taskCount);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
