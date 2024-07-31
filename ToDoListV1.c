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
/* Function to handle Login */
void taskList(){
    
}


void main()
{
    login();

}
