#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXLISTNAME 20

char flname[] = "list.dat";

struct List
{
    int id;
    char name[MAXLISTNAME];
};

int displayAllList(int x); // to have a return value pass 1 and any other number for print
int newlist();
void delList();

void fetchListNameByID(char *str, int id)
{
    int found;
    struct List l;
    FILE *fp;
    fp = fopen(flname, "rb");
    while (1)
    {
        fread(&l, sizeof(l), 1, fp);

        if (feof(fp))
            break;
        if (l.id == id)
        {
            found = 1;
            strcpy(str, l.name);
            strcat(str, ".dat");
            break;
        }
    }
    fclose(fp);
}
int newlist()
{
    int count = displayAllList(1) + 1;
    FILE *fp;
    char name[MAXLISTNAME];

    struct List l;
    fp = fopen(flname, "ab");
    printf("New List ID = %d\n", count);
    l.id = count;
    printf("\033[33mEnter New List Name: \033[0m");
    scanf("%s", &l.name);
    fwrite(&l, sizeof(l), 1, fp);
    fclose(fp);

    FILE *fpt;               // creating the file to store task
    char namef[MAXLISTNAME]; // temp file name
    strcpy(namef, l.name);
    strcat(namef, ".dat");
    fpt = fopen(namef, "wb");

    fclose(fpt);
    return l.id;
}

void delList()
{
    displayAllList(0);
    FILE *fp, *fpt;
    struct List l;
    int id, found = 0, count = 0;
    char name[MAXLISTNAME];
    char temp[9] = "temp.dat";
    fp = fopen(flname, "rb");
    fpt = fopen(temp, "wb");

    printf("\033[32m Tip - To remove multiple items from the list, input their IDs in descending order, separated by a space, with a \'2\' inserted between each ID.\nexample: \'3 2 2 2 1\'. \033[0m\n");
    printf("\033[33mEnter List ID: \033[0m");
    scanf("%d", &id);

    while (1)
    {
        fread(&l, sizeof(l), 1, fp);

        if (feof(fp))
            break;

        if (l.id == id)
        {
            found = 1;
            strcpy(name, l.name);
            strcat(name, ".dat");
            remove(name);
        }
        else if (found == 1)
        {
            l.id = l.id - 1;
            fwrite(&l, sizeof(l), 1, fpt);
        }
        else
            fwrite(&l, sizeof(l), 1, fpt);
    }

    fclose(fp);
    fclose(fpt);
    if (found == 0)
        printf("list not founded");
    else
    {
        fp = fopen(flname, "wb");
        fpt = fopen(temp, "rb");
        while (1)
        {
            fread(&l, sizeof(l), 1, fpt);
            if (feof(fpt))
                break;

            fwrite(&l, sizeof(l), 1, fp);
        }
    }
    printf("\nCompleted permanantly deleting List\\s\n");
    sleep(1);
    fclose(fp);
    fclose(fpt);
    remove(temp);
}

int displayAllList(int x)
{
    FILE *fp;
    struct List l;
    int count = 0;

    fp = fopen(flname, "rb");
    if (fp == NULL)
    {
        printf("\033[31m No List Found \033[0m\n");
        return count;
    }

    printf("=============All Lists===============\n");
    printf("ID\t|\tName\n");
    printf("-------------------------------------\n");

    while (1)
    {
        fread(&l, sizeof(l), 1, fp);
        if (feof(fp))
            break;
        if (sizeof(fp) == 0)
            break;
        printf("%d \t|\t", l.id);
        printf("%s \n", l.name);
        count++;
    }
    fclose(fp);
    printf("================================================\n");
    switch (x)
    {
    case 1:
        return count;
        break;
    default:
        (count == 0) ? printf("Plese Crearte New List") : printf("List count = %d", count);
        printf("\n================================================\n\n");
        break;
    }
    return count;
}
