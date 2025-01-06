#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void menu(void);
void Admin_Login(void);
void Admin_menu(void);
int i;
char one[1] = {'0'}, two[1] = {'2'};
void main()
{
    menu();
}
void menu(void)
{
    system("cls");
    printf("Welcome to my Library Management Software...");
    printf("\n");
    printf("\n");
    printf("1. Admin Login");
    printf("\n");
    printf("2. Staff Login");
    printf("\n");
    printf("3. Member Login");
    printf("\n");
    printf("4. Exit");
    printf("\n");
    printf("\n");
    printf("Please Enter Your Choice:");
    scanf("%d", &i);
    if(i == 1)
    {
        Admin_Login();
        Admin_menu();
    }
    if(i == 2)
    {

    }
    if(i == 3)
    {

    }
    if(i == 4)
    {
        system("cls");
        exit(0);
    }
}
void Admin_Login(void)
{
    int j = 0;
    system("cls");
    char password[11];
    char defult_password[11] = {'@','A','m','i','r','_','1','3','8','5'};
    printf("Admin                                              1. Back    2.exit");
    printf("\n");
    printf("Password: ");
    while(j != 1)
    {
        scanf("%s", password);
        if(strcmp(password, defult_password) == 0)
        {
            j++;
        }
        else
        {
            if(strcmp(password, one) == 0)
            {
                menu();
            }
            else
            {
                if(strcmp(password, two) == 0)
                {
                    exit(0);
                }
                else
                {
                    printf("Password is false!");
                    printf("\n");
                    printf("Please enter again.");
                }
            }
        }
    }
}
void Admin_menu(void)
{
    system("cls");
    printf("Admin");
    printf("\n");
}
