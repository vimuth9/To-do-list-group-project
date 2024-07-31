#include <stdio.h>

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

void main()
{
    login();
}
