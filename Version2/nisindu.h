#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "dulaj.h"

void markCompletedTask()
{
    displayAllTask();
    int idl, idt;
    printf("Enter List ID: ");
    scanf("%d", idl);
    printf("Enter Task ID: ");
    scanf("%d", idt);
    char name[MAXLISTNAME];
    fetchListNameByID(name, idl);
    deleteTaskByID(name, idt);
}