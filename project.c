#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void menu(void);
void Admin_Login(void);
void Admin_menu(void);
void New_employee(void);
int i;
char one[2] = {'1'}, two[2] = {'2'};
struct employee{
    char name[20];
    char family[20];
    char date[20];
    char phone[12];
    char code_meli[11];
    char email[20];
    char username[20];
    char password[20];
    struct employee *link;
};
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
    int i = 0;
    system("cls");
    char password[11];
    char defult_password[11] = {'@','A','m','i','r','_','1','3','8','5'};
    printf("Admin                                                         1. Back    2.exit");
    printf("\n");
    printf("Password: ");
    while(i != 1)
    {
        scanf("%s", password);
        if(strcmp(password, defult_password) == 0)
        {
            i++;
        }
        else
        {
            if(strcmp(password, one ) == 0)
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
    int i;
    system("cls");
    printf("Admin");
    printf("\n");
    printf("1. New employee registration");
    printf("\n");
    printf("2. View employee list");
    printf("\n");
    printf("3. Removing an employee from the system");
    printf("\n");
    printf("4. Reports");
    printf("\n");
    printf("5. Log out of account");
    printf("\n");
    printf("\n");
    printf("Please Enter Your Choice:");
    scanf("%d", &i);
    if(i == 1)
    {
        New_employee();
    }
}
void New_employee(void)
{
    struct employee *start, *temp;
    FILE *fp;
    system("cls");
    fp = fopen("Employee Profile.text","w");
    start = malloc(sizeof(struct employee));
    start;
    printf("Please enter the name's employee:");
    scanf("%s",start->name);
    printf("\n");
    printf("Please enter the family name's employee:");
    scanf("%s",start->family);
    printf("\n");
    printf("Please enter the registration date:");
    scanf("%s",start->date);
    printf("\n");
    printf("Please enter the phone number's employee:");
    scanf("%s",start->phone);
    printf("\n");
    printf("Please enter the employee's national code:");
    scanf("%s",start->code_meli);
    printf("\n");
    printf("Please enter the employee's email:");
    scanf("%s",start->email);
    printf("\n");
    printf("Please enter the user name for employee:");
    scanf("%s",start->username);
    printf("\n");
    printf("Please enter the password for employee:");
    scanf("%s",start->password);
    fputs(start->name,fp);
    fputs(start->family,fp);
    fputs(start->date,fp);
    fputs(start->phone,fp);
    fputs(start->code_meli,fp);
    fputs(start->email,fp);
    fputs(start->username,fp);
    fputs(start->password,fp);
    fclose(fp);
}
