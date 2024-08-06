#include <stdio.h>
/* Function to handle Login */
void login()
{
    const int correct_password = 1234;
    int password;
    do
    {
        printf("Enter password: ");
        scanf("%d/n", &password);
    } while (password != correct_password);
    printf("Login Sucsessful\n");
}
/* Function to Print Help text */
void guide_text()
{
    printf("\033[31m //////// Guide TExt  ///////.\033[0m\n");
}

/* Function to handle Login */
void command_identifier()
{
    printf("\033[31m //////// Insert Function  ///////.\033[0m\n");
}

void main()
{
    login();
    guide_text();
}
