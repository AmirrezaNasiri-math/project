#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
void date(char datestr[11]);
void menu(void);
void Admin_Login(void);
void Admin_menu(void);
void New_employee(void);
void list_employee(void);
void delet_employee(void);
void addatend_employee(void);
int i;
char one[2] = {'1'}, two[2] = {'2'};
// tarif sakhtar baray moshakhsat karmandan.
struct employee{
    char name[20];
    char family[20];
    char date[11];
    char phone[12];
    char code_meli[11];
    char email[40];
    char username[20];
    char password[20];
    struct employee *link;
};
void main()
{
    // karbar vaghti vard barname mishavad ba menu barname robero mishavad.
    menu();
}
// in tabe terikh ra elam mikonad.
void date(char datestr[11])
{
    // baray estafade az tabe localtime bayad az esharegarha estefade kard chon in tabe vorodiash.
    //esharegar ast.
    time_t t;
    t = time(NULL);
    // tm = mohtavay khane t.
    struct tm tm = *localtime(&t);
    sprintf(datestr,"%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1 , tm.tm_mday);
}
void menu(void)
{
    // vaghti in tabe farakhni mishavad har chap shode dar barneme pak mishavd va menu namayesh dade mishavad.
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
    //vaghti karbar adad yek ra vard konad ebteda karbar bayad login anjam dahad bad vard menu admin savad.
    if(i == 1)
    {
        Admin_Login();
        // vaghti ramz dorost bashad vared menu Admin mishavad.
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
// baray login kardan admin yek tabe tarif mikonim.
void Admin_Login(void)
{
    // dar ebteda har chi ke ghablan dar barname nevehte sode pak mishavad va bayad karbar login konad.
    int i = 0;
    system("cls");
    char password[11];
    //enja password admin ro tarif mikonim.
    char defult_password[11] = {'@','A','m','i','r','_','1','3','8','5'};
    printf("Admin                                                         1. Back    2.exit");
    printf("\n");
    printf("Password: ");
    while(i != 1)
    {
        //inaja yek password az karbar gerefte mishavad
        scanf("%s", password);
        // va ba password karbar moghyese mishavad
        if(strcmp(password, defult_password) == 0)
        {
            //agar barabar bod az halghe kharej mishavad.
            i++;
        }
        else
        {
            if(strcmp(password, one ) == 0)
            {
                // zamani ke karbar adad yek ra vared konad vard ghesmat menu mishavad.
                menu();
            }
            else
            {
                if(strcmp(password, two) == 0)
                {
                    // zamani ke sefr vared shavad az barname khrej mishavad.
                    exit(0);
                }
                else
                {
                    // har bar ramz ghalat bashad in chap mishavd.
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
    // inja safe menu karbar namayesh dade mishavad.
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
    if(i == 2)
    {
        list_employee();
    }
    if(i == 3)
    {
        delet_employee();
    }
}
void New_employee(void)
{
    int i;
    struct employee *start, *temp;
    FILE *fp;
    system("cls");
    fp = fopen("Employee Profile.text","a");
    start = malloc(sizeof(struct employee));
    printf("Please enter the name's employee:");
    scanf("%s",start->name);
    printf("\n");
    printf("Please enter the family name's employee:");
    scanf("%s",start->family);
    printf("\n");
    printf("the registration date:");
    date(start->date);
    puts(start->date);
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
    fprintf(fp,"\n");
    fputs(start->name,fp);
    fprintf(fp,"\n");
    fputs(start->family,fp);
    fprintf(fp,"\n");
    fputs(start->date,fp);
    fprintf(fp,"\n");
    fputs(start->phone,fp);
    fprintf(fp,"\n");
    fputs(start->code_meli,fp);
    fprintf(fp,"\n");
    fputs(start->email,fp);
    fprintf(fp,"\n");
    fputs(start->username,fp);
    fprintf(fp,"\n");
    fputs(start->password,fp);
    system("cls");
    printf("The operation was successful.");
    fclose(fp);
    Sleep(2000);
    printf("\n");
    printf("1. New employee registration");
    printf("\n");
    printf("2. Back");
    printf("Please Enter Your Choice:");
    scanf("%d", &i);
    if(i == 1)
    {
        New_employee();
    }
    else
    {
        Admin_menu();
    }
}
void list_employee(void)
{
    int i;
    struct employee *start, *temp;
    FILE *fp;
    char line[100];
    system("cls");
    fp = fopen("Employee Profile.text","r");
    start = malloc(sizeof(struct employee));
    end = malloc(sizeof(struct employee));
    temp = start;
    printf("                                                  1. Back");
    while(feof(fp) == 0)
    {
        //ebteda kol khat dar line ezafe mishavad bad
        printf("FIRST NAME:");
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->name, line);
        }
        puts(temp->name);
        printf("LAST NAME:");
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->family, line);
        }
        puts(temp->family);
        printf("REGISTRATION DATE:");
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        puts(temp->date);
        printf("HER/HIS PHONE NUMBER:");
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->phone, line);
        }
        puts(temp->phone);
        printf("HER/HIS NATIONAL CODE:");
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->code_meli, line);
        }
        puts(temp->code_meli);
        printf("HER/HIS EMAIL:");
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->email, line);
        }
        puts(temp->email);
        printf("USER NAME:");
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        puts(temp->username);
        printf("PASSWORD:");
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->password, line);
        }
        puts(temp->password);
        printf("------------------------------------------\n");
    }
    scanf("%d", &i);
    if(i == 1)
    {
        Admin_menu();
    }
}
void delet_employee(void)
{
    int i;
    struct employee *start, *temp;
    char line, delet;
    system("cls");
    printf("Please enter The name of the employee to be deleted:");
    gets(delet);
    start = malloc(sizeof(struct employee));

}
void addatend_employee()
