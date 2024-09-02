# To-do-list
> This project is made for learning purposes

# Contributors
* Vimuth
* Hashan
* Rivindu
* Dulaj
* Nisindu

# Features

1. Create New List
2. Delete List

3. Export Selected List
4. Export All Lists

5. Add Task to a List
6. Delete Task from a List

7. View Tasks in a List
8. View All Tasks Across Lists

9.  Mark Task as Complete
10. View/Delete Completed Tasks

11. View Tasks for Today/Tomorrow/Other

12. Reset View
13. Exit App

# Features to be Finish

- [ ] Mark Task as Complete
- [ ]  View/Delete Completed Tasks
- [ ]  View Tasks for Today/Tomorrow/Other

# User Defined header files Explanation

## vimuth.h
### Functions Included

```c
// Fetch List Name by ID
void fetchListNameByID(char *str, int id); 

// Displays all list the user had created
// returns the value of how many list are created
int displayAllList();  

// create new list
int newlist();
// delete a list permanently
void delList();
```
### Pre-defined global variables
```c
#define MAXLISTNAME 20

char flname[] = "list.dat";

struct List
{
    int id;
    char name[MAXLISTNAME];
};
```

### Example Usage
 - `fetchListNameByID(str)` 
 - `displayAllList()`

```c
#include <stdio.h>
#include <string.h>
#include "vimuth.h"

/* Global variable
#define MAXLISTNAME 20
*/

int main() {
    int id,count;
    char name[MAXLISTNAME];  // Buffer to hold the list name file name in the format of "fileName.dat"

    count = displayAllList();
    printf("# of Lists available : %d\n", count);

    printf("Enter List ID");
    scanf("%d",id);

    fetchListNameByID(name, id);
    printf("The list name is: %s\n", name);
    return 0;
}
```


## dulaj.h
### Functions Included

```c
// Display tasks in a given file name 
// The name of file has be "fileName.dat" 
// if the color integer is a odd number it prints the list in cyan and is it's a round number it prints the list in green
// Use  fetchListNameByID  which is explained under 'vimuth.h' header file
int displayTask(char name[MAXLISTNAME], int color);

// Display all the task 
void displayAllTask();

// Uses the same concept but prints(overwrites) on "./Export/Export.txt"
int exportList(char name[MAXLISTNAME], int x);
void exportAllLists();
```
### Pre-defined global variables
```c
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
```

### Example Usage

-  `displayTask`
-  `displayAllTask`
-  `exportList`
-  `exportAllLists`

```c
#include <stdio.h>
#include <string.h>

#include "vimuth.h"
#include "dulaj.h"

/* Global variable
#define MAXTITLE 40
#define MAXDISCRIPTION 40
*/

int main() {
    int id,count;
    char name[MAXLISTNAME];  // Buffer to hold the list name file name in the format of "fileName.dat"

    count = displayAllList();
    printf("# of Lists available : %d\n", count);

    printf("Enter List ID:");
    scanf("%d",id);

    fetchListNameByID(name, id);
    printf("The list name is: %s\n", name);
    displayTask(name,1); // prints the list in cyan color
    displayTask(name,2); // prints the list in green color
    
    printf("\n printing all task list\n");
    displayAllTask(); // displays all task while switching colors

    exportList(name,1); // prints the list in cyan color
    exportAllLists(name,2); // prints the list in green color
    
    return 0;
}
```

## hashan.h
### Functions Included

```c
// add task to a list 
int addTask();
void delTask();
int deleteTaskByID(char *name, int id);
int calculateDueDate(int x); // returns a integer as a date

```
### Pre-defined global variables
```c
#define MAXLISTNAME 20
```

### Example Usage
- `deleteTaskByID`
- `calculateDueDate`

```c
#include <stdio.h>
#include <string.h>
#include "hashan.h"

int main() {
    
    printf("\033[33mEnter List ID: \033[0m");
    scanf("%d", &idl);
    fetchListNameByID(name, idl); // function defined under vimuth.h
    int id;
    displayTask(name, 1); // function defined under dulaj.h
    printf("Enter Task id:");
    scanf("%d", &id);
    deleteTaskByID(name, id);


    int days,date;
    printf("Due date: ");
    scanf("%d", &days);
    date = calculateDueDate(days);
    printf("The date after %d days from today%d",days,date);
    return 0;
}
```

## nisindu.h
### Functions Included

```c


```
### Pre-defined global variables
```c

```

### Example Usage
- 

```c
#include <stdio.h>
#include <string.h>
#include "hashan.h"

int main() {

    return 0;
}
```

## rivindu.h
### Functions Included

```c


```
### Pre-defined global variables
```c

```

### Example Usage
- 

```c
#include <stdio.h>
#include <string.h>
#include "hashan.h"

int main() {
    
    return 0;
}
```

