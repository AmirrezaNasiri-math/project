#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
void date(char datestr[11]);
void validity(char val_date[11]);
void validity_book(char val_date[11]);
void remainder(void);
void menu(void);
void Admin_Login(void);
void Admin_menu(void);
void New_employee(void);
void list_employee(void);
void delet_employee(void);
void Staff_login(void);
void Staff_menu(void);
void New_member(void);
void New_book(void);
void ID_book(char ID[10]);
void list_member(void);
void list_active(void);
void list_inactive(void);
void list_farmer(void);
void delet_member(void);
void setting_employee(void);
void Change_Password(void);
void Change_Email(void);
void Change_Phone(void);
void renewal(void);
void Member_login(void);
void Member_menu(void);
void register_trust(void);
void register_return(void);
void my_book_list(void);
void my_unreturn_book(void);
void my_return_book(void);
void books(void);
void book_list_borrowing(void);
void book_list(void);
void setting_member(void);
void Change_Password_Member(void);
void Change_Email_Member(void);
void Change_Phone_Member(void);
void report_Admin(void);
void report_Admin_list_member(void);
void report_Admin_list_employee(void);
void report_Admin_list_book(void);
void report_Admin_list_book_2(void);
void report_Admin_list_book_3(void);
void report_Admin_history_book(void);
void report_Admin_search(void);
char one[2] = {'1', '\0'}, two[2] = {'2', '\0'}, three[2] = {'3', '\0'}, four[2] = {'4', '\0'}, five[2] = {'5', '\0'}, six[2] = {'6', '\0'}, seven[2] = {'7', '\0'}, eight[2] = {'8', '\0'}, nine[2] = {'9', '\0'}, ten[2] = {'10', '\0'}, eleven[2] = {'11', '\0'};
char karmand[20], ozve[20];
// ID_book baray shenase ketab ke har bar ketab jadid sabt mishe yeki behesh ezafe mishe.
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
struct member{
    char name[20];
    char family[20];
    char date[11];
    char end_date[11];
    char phone[12];
    char code_meli[11];
    char email[40];
    char active[20];
    char username[20];
    char password[20];
    struct member *link;
};
struct book{
    char name[100];
    char publication[20];
    char author[100];
    char year[10];
    char date[11];
    char id[10];
    char username[20];
    char genre[20];
    char username_member[20];
    char date_trust[11];
    char date_take[11];
    struct book *link;
};
struct my_book{
    char user_name[20];
    char name[100];
    char date_trust[11];
    char date_take[11];
    char id[10];
    struct my_book *link;
};
struct return_book{
    char user_name[20];
    char name[100];
    char date_trust[11];
    char date_take[11];
    char date_return[11];
    char id[10];
    struct return_book *link;
};
void main()
{
    // in tabe vazife beroz resani tarikh ozviat ra darad.
    remainder();
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
void validity(char val_date[11])
{
    time_t t;
    t = time(NULL);
    // tm = mohtavay khane t.
    struct tm tm = *localtime(&t);
    sprintf(val_date,"%04d-%02d-%02d", tm.tm_year + 1901, tm.tm_mon + 1 , tm.tm_mday);
}
void validity_book(char val_date[11])
{
    time_t t;
    t = time(NULL);
    // tm = mohtavay khane t.
    struct tm tm = *localtime(&t);
    if(tm.tm_mon != 11)
    {
        sprintf(val_date,"%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 2 , tm.tm_mday);
    }
    else
    {
        sprintf(val_date,"%04d-%02d-%02d", tm.tm_year + 1901, tm.tm_mon + 1 , tm.tm_mday);
    }
}
void remainder(void)
{
    struct member *start = NULL, *end = NULL, *temp = NULL;
    char line[100], date_today[11];
    FILE *fp;
    fp = fopen("Member Profile.txt", "r");
    date(date_today);
    puts(date_today);
    while(1)
    {
        temp = malloc(sizeof(struct member));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->family, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->end_date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->phone, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->code_meli, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->email, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->active, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->password, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    temp = start;
    while(temp != NULL)
    {
        if(strcmp(temp->active, "Active") == 0)
        {
            if(strcmp(date_today, temp->end_date) >= 0)
            {
                strcpy(temp->active, "Inactive");
            }
        }
        if(strcmp(temp->active, "Inactive") == 0)
        {
            if(strcmp(date_today, temp->end_date) < 0)
            {
                strcpy(temp->active, "Active");
            }
        }
        temp = temp->link;
    }
    fp = fopen("Member Profile.txt", "w");
    temp = start;
    while(temp != NULL)
    {
        fputs(temp->name,fp);
        fprintf(fp,"\n");
        fputs(temp->family,fp);
        fprintf(fp,"\n");
        fputs(temp->date,fp);
        fprintf(fp,"\n");
        fputs(temp->end_date, fp);
        fprintf(fp, "\n");
        fputs(temp->phone,fp);
        fprintf(fp,"\n");
        fputs(temp->code_meli,fp);
        fprintf(fp,"\n");
        fputs(temp->email,fp);
        fprintf(fp,"\n");
        fputs(temp->active, fp);
        fprintf(fp, "\n");
        fputs(temp->username,fp);
        fprintf(fp,"\n");
        fputs(temp->password,fp);
        fprintf(fp,"\n");
        temp = temp->link;
    }
    fclose(fp);
    temp = start;
    while(temp != NULL)
    {
        struct member *next;
        next = temp ->link;
        free(temp);
        temp = next;
    }
}
void menu(void)
{
    char i[100];
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
    while(1)
    {
        scanf("%s", i);
        //vaghti karbar adad yek ra vard konad ebteda karbar bayad login anjam dahad bad vard menu admin savad.
        if(strcmp(i , one) == 0)
        {
            Admin_Login();
        }
        if(strcmp(i, two) == 0)
        {
            Staff_login();
        }
        if(strcmp(i, three) == 0)
        {
            Member_login();
        }
        if(strcmp(i, four) == 0)
        {
            system("cls");
            exit(0);
        }
        else
        {
            printf("Please enter a number of above: ");
        }
    }
}
// baray login kardan admin yek tabe tarif mikonim.
void Admin_Login(void)
{
    // dar ebteda har chi ke ghablan dar barname nevehte sode pak mishavad va bayad karbar login konad.
    char i[100];
    system("cls");
    char username[6];
    char defult_username[6]={'A','d','m','i','n'};
    char password[11];
    //enja password admin ro tarif mikonim.
    char defult_password[11] = {'@','A','m','i','r','_','1','3','8','5'};
    printf("Please enter the your username: ");
    fflush(stdin);
    scanf("%s", username);
    if(strcmp(username, defult_username) == 0)
    {
        system("cls");
        printf("Admin                                                         1. Back    2.exit");
        printf("\n");
        printf("Password: ");
        while(1)
        {
            //inaja yek password az karbar gerefte mishavad
            fflush(stdin);
            scanf("%s", password);
            // va ba password karbar moghyese mishavad
            if(strcmp(password, defult_password) == 0)
            {
                //agar barabar bod az halghe kharej mishavad.
                break;
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
    else
    {
        printf("Username is False.\n");
        printf("1. Try again.");
        printf("2. back");
        while(1)
        {
            scanf("%s", i);
            if(strcmp(i,one) == 0)
            {
                Admin_Login();
            }
            if(strcmp(i, two) == 0)
            {
                menu();
            }
            else
            {
                printf("\nPlease enter the one or two: ");
            }
        }
    }
    // vaghti ramz dorost bashad vared menu Admin mishavad.
    Admin_menu();
}
void Admin_menu(void)
{
    char i[100];
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
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            New_employee();
        }
        if(strcmp(i, two) == 0)
        {
            list_employee();
        }
        if(strcmp(i, three) == 0)
        {
            delet_employee();
        }
        if(strcmp(i, four) == 0)
        {
            report_Admin();
        }
        if(strcmp(i, five) == 0)
        {
            menu();
        }
        else
        {
            printf("\nPlease enter a number of above: ");
        }
    }
}
void New_employee(void)
{
    int i;
    struct employee *start;
    FILE *fp;
    system("cls");
    fp = fopen("Employee Profile.txt","a");
    start = malloc(sizeof(struct employee));
    printf("Please enter the name's employee:");
    scanf("%s",start->name);
    printf("\n");
    printf("Please enter the family name's employee:");
    scanf("%s",start->family);
    printf("\n");
    printf("The registration date:");
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
    fprintf(fp, "\n");
    system("cls");
    printf("The operation was successful.");
    fclose(fp);
    Sleep(2000);
    printf("\n");
    printf("1. New employee registration");
    printf("\n");
    printf("2. Back\n");
    printf("Please Enter Your Choice:");
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            New_employee();
        }
        if(strcmp(i, two) == 0)
        {
            Admin_menu();
        }
        else
        {
            printf("\nPlease enter a number of above:");
        }
    }
}
void list_employee(void)
{
    struct employee *start = NULL, *end = NULL, *temp = NULL;
    system("cls");
    char line[100], i[100];
    FILE *fp;
    fp = fopen("Employee Profile.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct employee));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->family, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->phone, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->code_meli, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->email, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->password, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    printf("                                                  1. Back\n");
    temp = start;
    while(temp != NULL)
    {
        printf("FIRST NAME:                         ");
        puts(temp->name);
        printf("LAST NAME:                          ");
        puts(temp->family);
        printf("REGISTRATION DATE:                  ");
        puts(temp->date);
        printf("PHONE:                              ");
        puts(temp->phone);
        printf("NATIONAL CODE:                      ");
        puts(temp->code_meli);
        printf("EMAIL:                              ");
        puts(temp->email);
        printf("USERNAME:                           ");
        puts(temp->username);
        printf("PASSWORD:                           ");
        puts(temp->password);
        printf("--------------------------------------------------------------------\n");
        temp = temp->link;
    }
    while(temp != NULL)
    {
        struct employee *next;
        next = temp ->link;
        free(temp);
        temp = next;
    }
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            Admin_menu();
        }
        else
        {
            printf("\nPlease enter 1.");
        }
    }
}
void delet_employee(void)
{
    struct employee *start = NULL, *end = NULL, *temp = NULL;
    int j = 0;
    char delet[20], i[100];
    FILE *fp1, *fp2;
    system("cls");
    char line[100];
    FILE *fp;
    fp = fopen("Employee Profile.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct employee));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->family, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->phone, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->code_meli, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->email, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->password, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    printf("Please enter The username of the employee to be deleted:");
    scanf("%s", delet);
    temp = start;
    fp1 = fopen("Employee Profile.txt","w");
    fp2 = fopen("Deleted Employee Profile.txt", "a");
    while(temp != NULL)
    {
        if(strcmp(delet, temp->username) == 0)
        {
            fputs(temp->name,fp2);
            fprintf(fp2, "\n");
            fputs(temp->family,fp2);
            fprintf(fp2, "\n");
            fputs(temp->date,fp2);
            fprintf(fp2, "\n");
            fputs(temp->phone,fp2);
            fprintf(fp2, "\n");
            fputs(temp->code_meli,fp2);
            fprintf(fp2, "\n");
            fputs(temp->email,fp2);
            fprintf(fp2, "\n");
            fputs(temp->username,fp2);
            fprintf(fp2, "\n");
            fputs(temp->password,fp2);
            fprintf(fp2, "\n");
            temp = temp->link;
            j++;
        }
        else
        {
            fputs(temp->name,fp1);
            fprintf(fp1, "\n");
            fputs(temp->family,fp1);
            fprintf(fp1, "\n");
            fputs(temp->date,fp1);
            fprintf(fp1, "\n");
            fputs(temp->phone,fp1);
            fprintf(fp1, "\n");
            fputs(temp->code_meli,fp1);
            fprintf(fp1, "\n");
            fputs(temp->email,fp1);
            fprintf(fp1, "\n");
            fputs(temp->username,fp1);
            fprintf(fp1, "\n");
            fputs(temp->password,fp1);
            fprintf(fp1, "\n");
            temp = temp->link;
        }
    }
    fclose(fp1);
    fclose(fp2);
    temp = start;
    while(temp != NULL)
    {
        struct employee *next;
        next = temp->link;
        free(temp);
        temp = next;
    }
    // momken kasi baray hazf kardan nabashe.
    if(j == 1)
    {
        printf("%s's removal was successful.                          1.back", delet);
    }
    else
    {
        printf("No one named %s was found.                            1.back", delet);
    }
    // ke karbar age chert o pert vared kard hamechi ok bashe.
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            Admin_menu();
        }
        else
        {
            printf("\nPlease enter 1.\n");
        }
    }
}
void report_Admin(void)
{
    system("cls");
    char i[100];
    printf("1. List of member profiles");
    printf("\n");
    printf("2. List of employee profiles");
    printf("\n");
    printf("3. List of all books");
    printf("\n");
    printf("4. List of all books available for borrowing,all books currently on loan");
    printf("\n");
    printf("5. List of books that are overdue for return");
    printf("\n");
    printf("6. History of borrowing books");
    printf("\n");
    printf("7. List of books registered in the library by a specific employee");
    printf("\n");
    printf("8. Back");
    printf("\n");
    printf("\n");
    printf("Please Enter Your Choice:");
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            report_Admin_list_member();
        }
        else
        {
            if(strcmp(i, two) == 0)
            {
                report_Admin_list_employee();
            }
            else
            {
                if(strcmp(i, three) == 0)
                {
                    // dar in ghesmat tarikhche sabt har ketab mojod ast.
                    report_Admin_list_book();
                }
                else
                {
                    if(strcmp(i, four) == 0)
                    {
                        report_Admin_list_book_2();
                    }
                    else
                    {
                        if(strcmp(i, five) == 0)
                        {
                            report_Admin_list_book_3();
                        }
                        else
                        {
                            if(strcmp(i, six) == 0)
                            {
                                report_Admin_history_book();
                            }
                            else
                            {
                               if(strcmp(i, seven) == 0)
                               {
                                   report_Admin_search();
                               }
                               else
                               {
                                   if(strcmp(i , eight) == 0)
                                   {
                                       Admin_menu();
                                   }
                                   else
                                   {
                                       printf("Please enter a number of above: ");
                                   }
                               }
                            }
                        }
                    }
                }
            }
        }

    }
}
void report_Admin_list_member(void)
{
    struct member *start = NULL, *end = NULL, *temp = NULL;
    int j = 0;
    system("cls");
    char line[100], i[100];
    FILE *fp;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    fp = fopen("Member Profile.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct member));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->family, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->end_date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->phone, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->code_meli, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->email, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->active, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->password, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    temp = start;
    printf("                                                  1. Back\n");
    while(temp != NULL)
    {
        if(strcmp(temp->active, "Active") == 0)
        {
            printf("FIRST NAME:                         ");
            SetConsoleTextAttribute(hConsole, 10);
            puts(temp->name);
            SetConsoleTextAttribute(hConsole, 7);
            printf("LAST NAME:                          ");
            SetConsoleTextAttribute(hConsole, 10);
            puts(temp->family);
            SetConsoleTextAttribute(hConsole, 7);
            printf("REGISTRATION DATE:                  ");
            SetConsoleTextAttribute(hConsole, 10);
            puts(temp->date);
            SetConsoleTextAttribute(hConsole, 7);
            printf("MEMBERSHIP EXPIRATION DATE:         ");
            SetConsoleTextAttribute(hConsole, 10);
            puts(temp->end_date);
            SetConsoleTextAttribute(hConsole, 7);
            printf("PHONE NUMBER:                       ");
            SetConsoleTextAttribute(hConsole, 10);
            puts(temp->phone);
            SetConsoleTextAttribute(hConsole, 7);
            printf("NATIONAL CODE:                      ");
            SetConsoleTextAttribute(hConsole, 10);
            puts(temp->code_meli);
            SetConsoleTextAttribute(hConsole, 7);
            printf("EMAIL:                              ");
            SetConsoleTextAttribute(hConsole, 10);
            puts(temp->email);
            SetConsoleTextAttribute(hConsole, 7);
            printf("STATUS:                             ");
            SetConsoleTextAttribute(hConsole, 10);
            puts(temp->active);
            SetConsoleTextAttribute(hConsole, 7);
            printf("USERNAME:                           ");
            SetConsoleTextAttribute(hConsole, 10);
            puts(temp->username);
            SetConsoleTextAttribute(hConsole, 7);
            printf("PASSWORD:                           ");
            SetConsoleTextAttribute(hConsole, 10);
            puts(temp->password);
            SetConsoleTextAttribute(hConsole, 7);
        }
        if(strcmp(temp->active, "Inactive") == 0)
        {
            printf("FIRST NAME:                         ");
            SetConsoleTextAttribute(hConsole, 12);
            puts(temp->name);
            SetConsoleTextAttribute(hConsole, 7);
            printf("LAST NAME:                          ");
            SetConsoleTextAttribute(hConsole, 12);
            puts(temp->family);
            SetConsoleTextAttribute(hConsole, 7);
            printf("REGISTRATION DATE:                  ");
            SetConsoleTextAttribute(hConsole, 12);
            puts(temp->date);
            SetConsoleTextAttribute(hConsole, 7);
            printf("MEMBERSHIP EXPIRATION DATE:         ");
            SetConsoleTextAttribute(hConsole, 12);
            puts(temp->end_date);
            SetConsoleTextAttribute(hConsole, 7);
            printf("PHONE NUMBER:                       ");
            SetConsoleTextAttribute(hConsole, 12);
            puts(temp->phone);
            SetConsoleTextAttribute(hConsole, 7);
            printf("NATIONAL CODE:                      ");
            SetConsoleTextAttribute(hConsole, 12);
            puts(temp->code_meli);
            SetConsoleTextAttribute(hConsole, 7);
            printf("EMAIL:                              ");
            SetConsoleTextAttribute(hConsole, 12);
            puts(temp->email);
            SetConsoleTextAttribute(hConsole, 7);
            printf("STATUS:                             ");
            SetConsoleTextAttribute(hConsole, 12);
            puts(temp->active);
            SetConsoleTextAttribute(hConsole, 7);
            printf("USERNAME:                           ");
            SetConsoleTextAttribute(hConsole, 12);
            puts(temp->username);
            SetConsoleTextAttribute(hConsole, 7);
            printf("PASSWORD:                           ");
            SetConsoleTextAttribute(hConsole, 12);
            puts(temp->password);
            SetConsoleTextAttribute(hConsole, 7);
        }
        if(strcmp(temp->active, "Farmer") == 0)
        {
            printf("FIRST NAME:                         ");
            puts(temp->name);
            printf("LAST NAME:                          ");
            puts(temp->family);
            printf("REGISTRATION DATE:                  ");
            puts(temp->date);
            printf("MEMBERSHIP EXPIRATION DATE:         ");
            puts(temp->end_date);
            printf("PHONE NUMBER:                       ");
            puts(temp->phone);
            printf("NATIONAL CODE:                      ");
            puts(temp->code_meli);
            printf("EMAIL:                              ");
            puts(temp->email);
            printf("STATUS:                             ");
            puts(temp->active);
            printf("USERNAME:                           ");
            puts(temp->username);
            printf("PASSWORD:                           ");
            puts(temp->password);
        }
        printf("--------------------------------------------------------------------\n");
        temp = temp->link;
    }
    temp = start;
    while(temp != NULL)
    {
        struct member *next;
        next = temp->link;
        free(temp);
        temp = next;
    }
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            report_Admin();
        }
        else
        {
            printf("Please enter one.\n");
        }
    }
}
void report_Admin_list_employee(void)
{
    system("cls");
    struct employee *start = NULL, *end = NULL, *temp = NULL;
    char line[100], i[100];
    FILE *fp;
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    fp = fopen("Employee Profile.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct employee));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->family, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->phone, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->code_meli, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->email, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->password, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    printf("                                                  1. Back\n");
    printf("List of active employees\n");
    temp = start;
    while(temp != NULL)
    {
        printf("FIRST NAME:                         ");
        puts(temp->name);
        printf("LAST NAME:                          ");
        puts(temp->family);
        printf("REGISTRATION DATE:                  ");
        puts(temp->date);
        printf("PHONE NUMBER:                       ");
        puts(temp->phone);
        printf("NATIONAL CODE:                      ");
        puts(temp->code_meli);
        printf("EMAIL:                              ");
        puts(temp->email);
        printf("USERNAME:                           ");
        puts(temp->username);
        printf("PASSWORD:                           ");
        puts(temp->password);
        temp = temp->link;
        printf("--------------------------------------------------------------------\n");
    }
    temp = start;
    while(temp != NULL)
    {
        struct employee *next;
        next = temp->link;
        free(temp);
        temp = next;
    }
    fp = fopen("Deleted Employee Profile.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct employee));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->family, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->phone, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->code_meli, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->email, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->password, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    printf("List of");
    SetConsoleTextAttribute(color, 12);
    printf(" inactive ");
    SetConsoleTextAttribute(color, 7);
    printf("employees\n");
    temp = start;
    while(temp != NULL)
    {
        printf("FIRST NAME:                         ");
        SetConsoleTextAttribute(color, 12);
        puts(temp->name);
        SetConsoleTextAttribute(color, 7);
        printf("LAST NAME:                          ");
        SetConsoleTextAttribute(color, 12);
        puts(temp->family);
        SetConsoleTextAttribute(color, 7);
        printf("REGISTRATION DATE:                  ");
        SetConsoleTextAttribute(color, 12);
        puts(temp->date);
        SetConsoleTextAttribute(color, 7);
        printf("PHONE NUMBER:                       ");
        SetConsoleTextAttribute(color, 12);
        puts(temp->phone);
        SetConsoleTextAttribute(color, 7);
        printf("NATIONAL CODE:                      ");
        SetConsoleTextAttribute(color, 12);
        puts(temp->code_meli);
        SetConsoleTextAttribute(color, 7);
        printf("EMAIL:                              ");
        SetConsoleTextAttribute(color, 12);
        puts(temp->email);
        SetConsoleTextAttribute(color, 7);
        printf("USERNAME:                           ");
        SetConsoleTextAttribute(color, 12);
        puts(temp->username);
        SetConsoleTextAttribute(color, 7);
        printf("PASSWORD:                           ");
        SetConsoleTextAttribute(color, 12);
        puts(temp->password);
        SetConsoleTextAttribute(color, 7);
        temp = temp->link;
        printf("--------------------------------------------------------------------\n");
    }
    temp = start;
    while(temp != NULL)
    {
        struct employee *next;
        next = temp->link;
        free(temp);
        temp = next;
    }
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            report_Admin();
        }
        else
        {
            printf("Please enter one.\n");
        }
    }
}
void report_Admin_list_book(void)
{
    system("cls");
    char i[100];
    FILE *fp;
    char line[100];
    struct book *start = NULL, *temp = NULL, *end = NULL;
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    fp = fopen("Book Profile.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct book));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->publication, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->author, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->year, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->id, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->genre, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username_member, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date_trust, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date_take, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    temp = start;
    printf("                                                                    1.Back\n");
    printf("\n");
    while(temp != NULL)
    {
        printf("NAME BOOK:                          ");
        puts(temp->name);
        printf("NAME PUBLICATION:                   ");
        puts(temp->publication);
        printf("NAME AUTHOR:                        ");
        puts(temp->author);
        printf("YEAR OF PUBLICATION:                ");
        puts(temp->year);
        printf("BOOK REGISTERATION DATE:            ");
        puts(temp->date);
        printf("BOOK ID:                            ");
        puts(temp->id);
        printf("BOOK GENRE:                         ");
        puts(temp->genre);
        temp = temp->link;
        printf("--------------------------------------------------------------------\n");
    }
    temp = start;
    while(temp != NULL)
    {
        struct book *next;
        next = temp->link;
        free(temp);
        temp = next;
    }
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            report_Admin();
        }
        else
        {
            printf("Please enter one.\n");
        }
    }
}
void report_Admin_list_book_2(void)
{
    system("cls");
    char i[100];
    FILE *fp;
    char line[100];
    int j = 0, k = 0;
    struct book *start = NULL, *temp = NULL, *end = NULL;
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    fp = fopen("Book Profile.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct book));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->publication, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->author, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->year, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->id, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->genre, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username_member, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date_trust, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date_take, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    temp = start;
    printf("                                                                    1.Back\n");
    printf("List of unborrowed books\n");
    printf("\n");
    while(temp != NULL)
    {
        if(strcmp(temp->username_member, "NULL") == 0)
        {
            printf("NAME BOOK:                          ");
            puts(temp->name);
            printf("NAME PUBLICATION:                   ");
            puts(temp->publication);
            printf("NAME AUTHOR:                        ");
            puts(temp->author);
            printf("YEAR OF PUBLICATION:                ");
            puts(temp->year);
            printf("BOOK REGISTERATION DATE:            ");
            puts(temp->date);
            printf("BOOK ID:                            ");
            puts(temp->id);
            printf("BOOK GENRE:                         ");
            puts(temp->genre);
            printf("A PERSON WHO HAS BORROWED MONEY:    ");
            puts(temp->username_member);
            printf("TRUST REGISTRATION DATE:            ");
            puts(temp->date_trust);
            printf("BOOK RATURN DATE:                   ");
            puts(temp->date_take);
            temp = temp->link;
            printf("--------------------------------------------------------------------\n");
            j++;
        }
        else
        {
            temp = temp->link;
        }
    }
    if(j == 0)
    {
        printf("NULL\n");
    }
    printf("List of borrowed books\n");
    printf("\n");
    temp = start;
    while(temp != NULL)
    {
        if(strcmp(temp->username_member, "NULL") != 0)
        {
            printf("NAME BOOK:                          ");
            SetConsoleTextAttribute(color, 12);
            puts(temp->name);
            SetConsoleTextAttribute(color, 7);
            printf("NAME PUBLICATION:                   ");
            SetConsoleTextAttribute(color, 12);
            puts(temp->publication);
            SetConsoleTextAttribute(color, 7);
            printf("NAME AUTHOR:                        ");
            SetConsoleTextAttribute(color, 12);
            puts(temp->author);
            SetConsoleTextAttribute(color, 7);
            printf("YEAR OF PUBLICATION:                ");
            SetConsoleTextAttribute(color, 12);
            puts(temp->year);
            SetConsoleTextAttribute(color, 7);
            printf("BOOK REGISTERATION DATE:            ");
            SetConsoleTextAttribute(color, 12);
            puts(temp->date);
            SetConsoleTextAttribute(color, 7);
            printf("BOOK ID:                            ");
            SetConsoleTextAttribute(color, 12);
            puts(temp->id);
            SetConsoleTextAttribute(color, 7);
            printf("USER NAME OF THE EMPLOYEE:          ");
            SetConsoleTextAttribute(color, 12);
            puts(temp->username);
            SetConsoleTextAttribute(color, 7);
            printf("BOOK GENRE:                         ");
            SetConsoleTextAttribute(color, 12);
            puts(temp->genre);
            SetConsoleTextAttribute(color, 7);
            printf("USERNAME:                           ");
            SetConsoleTextAttribute(color, 12);
            puts(temp->username_member);
            SetConsoleTextAttribute(color, 7);
            printf("TRUST REGISTRATION DATE:            ");
            SetConsoleTextAttribute(color, 12);
            puts(temp->date_trust);
            SetConsoleTextAttribute(color, 7);
            printf("BOOK RATURN DATE:                   ");
            SetConsoleTextAttribute(color, 12);
            puts(temp->date_take);
            SetConsoleTextAttribute(color, 7);
            temp = temp->link;
            printf("--------------------------------------------------------------------\n");
            k++;
        }
        else
        {
            temp = temp->link;
        }
    }
    if(k == 0)
    {
        printf("NULL\n");
    }
    temp = start;
    while(temp != NULL)
    {
        struct book *next;
        next = temp->link;
        free(temp);
        temp = next;
    }
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            report_Admin();
        }
        else
        {
            printf("Please enter one.\n");
        }
    }
}
report_Admin_list_book_3()
{
    system("cls");
    char i[100];
    FILE *fp;
    char line[100], today[100];
    int j = 0, k = 0;
    struct book *start = NULL, *temp = NULL, *end = NULL;
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    fp = fopen("Book Profile.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct book));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->publication, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->author, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->year, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->id, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->genre, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username_member, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date_trust, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date_take, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    date(today);
    printf("                                                                    1.Back\n");
    temp = start;
    while(temp != NULL)
    {
        if(strcmp(today, temp->date_take) >= 0)
        {
            printf("NAME BOOK:                          ");
            SetConsoleTextAttribute(color, 12);
            puts(temp->name);
            SetConsoleTextAttribute(color, 7);
            printf("NAME PUBLICATION:                   ");
            SetConsoleTextAttribute(color, 12);
            puts(temp->publication);
            SetConsoleTextAttribute(color, 7);
            printf("NAME AUTHOR:                        ");
            SetConsoleTextAttribute(color, 12);
            puts(temp->author);
            SetConsoleTextAttribute(color, 7);
            printf("YEAR OF PUBLICATION:                ");
            SetConsoleTextAttribute(color, 12);
            puts(temp->year);
            SetConsoleTextAttribute(color, 7);
            printf("BOOK REGISTERATION DATE:            ");
            SetConsoleTextAttribute(color, 12);
            puts(temp->date);
            SetConsoleTextAttribute(color, 7);
            printf("BOOK ID:                            ");
            SetConsoleTextAttribute(color, 12);
            puts(temp->id);
            SetConsoleTextAttribute(color, 7);
            printf("USERNAME OF THE EMPLOYEE:           ");
            SetConsoleTextAttribute(color, 12);
            puts(temp->username);
            SetConsoleTextAttribute(color, 7);
            printf("BOOK GENRE:                         ");
            SetConsoleTextAttribute(color, 12);
            puts(temp->genre);
            SetConsoleTextAttribute(color, 7);
            printf("USERNAME:                           ");
            SetConsoleTextAttribute(color, 12);
            puts(temp->username_member);
            SetConsoleTextAttribute(color, 7);
            printf("TRUST REGISTRATION DATE:            ");
            SetConsoleTextAttribute(color, 12);
            puts(temp->date_trust);
            SetConsoleTextAttribute(color, 7);
            printf("BOOK RATURN DATE:                   ");
            SetConsoleTextAttribute(color, 12);
            puts(temp->date_take);
            SetConsoleTextAttribute(color, 7);
            temp = temp->link;
            printf("--------------------------------------------------------------------\n");
            k++;
        }
        else
        {
            temp = temp->link;
        }
    }
    if(k == 0)
    {
        printf("NULL.\n");
    }
    temp = start;
    while(temp != NULL)
    {
        struct book *next;
        next = temp->link;
        free(temp);
        temp = next;
    }
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            report_Admin();
        }
        else
        {
            printf("Please enter one.\n");
        }
    }
}
void report_Admin_history_book(void)
{
    system("cls");
    char i[100], k[100];
    FILE *fp;
    char line[100];
    int j = 0;
    struct return_book *start = NULL, *temp = NULL, *end = NULL;
    fp = fopen("Return Book.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct return_book));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->user_name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->name, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date_trust, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date_take, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date_return, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->id, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    printf("                                                                    1.Back\n");
    printf("Please enter the Date:(For example 2025-01-02)\n");
    while(1)
    {
        fflush(stdin);
        scanf("%s", i);
        fflush(stdin);
        scanf("%s", k);
        if(strlen(i) == 10 && strlen(k) == 10 && i[4] == '-' && k[4] == '-' && i[7] == '-' && k[7] == '-')
        {
            break;
        }
        else
        {
            printf("Please enter the dates as in the example.\n");
        }
    }
    temp = start;
    while(temp != NULL)
    {
        if(strcmp(i, temp->date_trust) >= 0 && strcmp(k, temp->date_trust) <= 0)
        {
            printf("NAME BOOK:                          ");
            puts(temp->name);
            printf("TRUST REGISTRATION DATE:            ");
            puts(temp->date_trust);
            printf("BOOK RATURN DATE:                   ");
            puts(temp->date_return);
            printf("BOOK ID:                            ");
            puts(temp->id);
            temp = temp->link;
            printf("--------------------------------------------------------------------\n");
            j++;
        }
        else
        {
            temp = temp->link;
        }
    }
    if(j == 0)
    {
        printf("NULL\n");
    }
    temp = start;
    while(temp != NULL)
    {
        struct my_book *next;
        next = temp->link;
        free(temp);
        temp = next;
    }
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            report_Admin();
        }
        else
        {
            printf("Please enter one.\n");
        }
    }
}
void report_Admin_search(void)
{
    system("cls");
    char i[100];
    FILE *fp;
    char line[100], emp[100];//employee = emp;
    int j = 0, k = 0;
    struct book *start = NULL, *temp = NULL, *end = NULL;
    struct employee *start1 = NULL, *temp1 = NULL, *end1 = NULL;
    fp = fopen("Book Profile.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct book));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->publication, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->author, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->year, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->id, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->genre, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username_member, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date_trust, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date_take, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    fp = fopen("Employee Profile.txt", "r");
    while(1)
    {
        temp1 = malloc(sizeof(struct employee));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp1->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp1->family, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp1->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp1->phone, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp1->code_meli, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp1->email, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp1->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp1->password, line);
        }
        temp1->link = NULL;
        if(start1 == NULL)
        {
            start1 = temp1;
            end1 = temp1;
        }
        else
        {
            end1->link = temp1;
            end1 = temp1;
        }
    }
    fclose(fp);
    printf("                                                                    1.Back\n");
    printf("Please enter the employee's username:\n");
    scanf("%s", emp);
    if(strcmp(emp, one) == 0)
    {
        report_Admin();
    }
    temp1 = start1;
    while(temp1 != NULL)
    {
        if(strcmp(temp1->username, emp) == 0)
        {
            break;
        }
        else
        {
            temp1 = temp1->link;
        }
    }
    if(temp1 == NULL)
    {
        printf("There is no such employee.\n");
        printf("1.Try again\n");
        printf("2.Back\n");
        while(1)
        {
            scanf("%s", i);
            if(strcmp(i, one) == 0)
            {
                temp = start;
                while(temp != NULL)
                {
                    struct book *next;
                    next = temp->link;
                    free(temp);
                    temp = next;
                }
                temp1 = start1;
                while(temp1 != NULL)
                {
                    struct employee *next1;
                    next1 = temp1->link;
                    free(temp1);
                    temp1 = next1;
                }
                report_Admin_search();
            }
            else
            {
                if(strcmp(i, two) == 0)
                {
                    temp = start;
                    while(temp != NULL)
                    {
                        struct book *next;
                        next = temp->link;
                        free(temp);
                        temp = next;
                    }
                    temp1 = start1;
                    while(temp1 != NULL)
                    {
                        struct employee *next1;
                        next1 = temp1->link;
                        free(temp1);
                        temp1 = next1;
                    }
                    report_Admin();
                }
                else
                {
                    printf("Please enter 1 or 2.\n");
                }
            }
        }
    }
    temp1 = start1;
    while(temp1 != NULL)
    {
        struct employee *next1;
        next1 = temp1->link;
        free(temp1);
        temp1 = next1;
    }
    temp = start;
    while(temp != NULL)
    {
        if(strcmp(temp->username, emp) == 0)
        {
            printf("NAME BOOK:                          ");
            puts(temp->name);
            printf("NAME PUBLICATION:                   ");
            puts(temp->publication);
            printf("NAME AUTHOR:                        ");
            puts(temp->author);
            printf("YEAR OF PUBLICATION:                ");
            puts(temp->year);
            printf("BOOK ID:                            ");
            puts(temp->id);
            printf("BOOK GENRE:                         ");
            puts(temp->genre);
            temp = temp->link;
            printf("--------------------------------------------------------------------\n");
            j++;
        }
        else
        {
            temp = temp->link;
        }
    }
    if(j == 0)
    {
        printf("NULL\n");
    }
    temp = start;
    while(temp != NULL)
    {
        struct book *next;
        next = temp->link;
        free(temp);
        temp = next;
    }
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            report_Admin();
        }
        else
        {
            printf("Please enter one.\n");
        }
    }
}
void Staff_login(void)
{
    system("cls");
    int j = 0;
    char user_name[20], user_password[20], i[100];
    struct employee *start = NULL, *end = NULL, *temp = NULL;
    char line[100];
    FILE *fp;
    fp = fopen("Employee Profile.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct employee));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->family, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->phone, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->code_meli, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->email, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->password, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    printf("Please enter your username: ");
    fflush(stdin);
    scanf("%s", user_name);
    temp = start;
    while(temp != NULL)
    {
        if(strcmp(temp->username, user_name) == 0)
        {
            break;
        }
        temp = temp->link;
    }
    //agar ta akhar check anjam shavad va user name paida nashavad vared in shart mishavad
    if(temp == NULL)
    {
        // print mishe ke user name vojod nadarad.
        printf("This username doesn't exist.\n");
        Sleep(1000);
        printf("1. to try again.\n");
        printf("2. back.\n");
        while(1)
        {
            scanf("%s", i);
            if(strcmp(i, one) == 0)
            {
                Staff_login();
            }
            else
            {
                if(strcmp(i, two) == 0)
                {
                    menu();
                }
                else
                {
                    printf("\nPlease enter a number of above: ");
                }
            }
         }
    }
    else
    {
        //baray inke dar tol ejra barname username karmand ro dashtebashim.
        strcpy(karmand,temp->username);
        system("cls");
        printf("%s %s                                          1.back   2.exit\n", temp->name, temp->family);
        printf("\nPlease enter the your password:");
        while(1)
        {
            //inaja yek password az karbar gerefte mishavad
            fflush(stdin);
            scanf("%s", user_password);
            // va ba password karbar moghyese mishavad
            if(strcmp(user_password, temp->password) == 0)
            {
                //agar barabar bod az halghe kharej mishavad.
                break;
            }
            else
            {
                if(strcmp(user_password, one ) == 0)
                {
                    // zamani ke karbar adad yek ra vared konad vard ghesmat menu mishavad.
                    menu();
                }
                else
                {
                    if(strcmp(user_password, two) == 0)
                    {
                        // zamani ke sefr vared shavad az barname khrej mishavad.
                        exit(0);
                    }
                    else
                    {
                        // har bar ramz ghalat bashad in chap mishavd.
                        printf("Password is false!");
                        printf("\n");
                        printf("Please enter again.\n");
                    }
                }
            }
        }
    }
    // vaghti karmand login kone vared menu karmand mishim.
    Staff_menu();
}
void Staff_menu(void)
{
    char i[100];
    // inja safe menu karmand namayesh dade mishavad.
    system("cls");
    puts(karmand);
    printf("\n");
    printf("1. New Member registration");
    printf("\n");
    printf("2. Membership renewal");
    printf("\n");
    printf("3. View member list");
    printf("\n");
    printf("4. Delete member");
    printf("\n");
    printf("5. New book registration");
    printf("\n");
    printf("6. Reports");
    printf("\n");
    printf("7. Account settings");
    printf("\n");
    printf("8. log out of account");
    printf("\n");
    printf("\n");
    printf("Please Enter Your Choice:");
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            New_member();
        }
        else
        {
            if(strcmp(i, two) == 0)
            {
                renewal();
            }
            else
            {
                if(strcmp(i, three) == 0)
                {
                    list_member();
                }
                else
                {
                    if(strcmp(i, four) == 0)
                    {
                        delet_member();
                    }
                    else
                    {
                        if(strcmp(i, five) == 0)
                        {
                            New_book();
                        }
                        else
                        {
                            if(strcmp(i, six) == 0)
                            {

                            }
                            else
                            {
                               if(strcmp(i, seven) == 0)
                               {
                                   setting_employee();
                               }
                               else
                               {
                                   if(strcmp(i , eight) == 0)
                                   {
                                       menu();
                                   }
                                   else
                                   {
                                       printf("Please enter a number of above: ");
                                   }
                               }
                            }
                        }
                    }
                }
            }
        }

    }
}
void New_member(void)
{
    char i[100];
    struct member *start, *temp;
    FILE *fp;
    system("cls");
    fp = fopen("Member Profile.txt","a");
    start = malloc(sizeof(struct member));
    printf("Please enter the name's member:");
    scanf("%s",start->name);
    printf("\n");
    printf("Please enter the family name's member:");
    scanf("%s",start->family);
    printf("\n");
    printf("The registration date:");
    date(start->date);
    puts(start->date);
    printf("\n");
    printf("Membership expiration date:");
    validity(start->end_date);
    puts(start->end_date);
    printf("\n");
    printf("Please enter the phone number's member:");
    scanf("%s",start->phone);
    printf("\n");
    printf("Please enter the member's national code:");
    scanf("%s",start->code_meli);
    printf("\n");
    printf("Please enter the member's email:");
    scanf("%s",start->email);
    printf("\n");
    strcpy(start->active, "Active");
    printf("Please enter the user name for member:");
    scanf("%s",start->username);
    printf("\n");
    printf("Please enter the password for member:");
    scanf("%s",start->password);
    fputs(start->name,fp);
    fprintf(fp,"\n");
    fputs(start->family,fp);
    fprintf(fp,"\n");
    fputs(start->date,fp);
    fprintf(fp,"\n");
    fputs(start->end_date, fp);
    fprintf(fp, "\n");
    fputs(start->phone,fp);
    fprintf(fp,"\n");
    fputs(start->code_meli,fp);
    fprintf(fp,"\n");
    fputs(start->email,fp);
    fprintf(fp,"\n");
    fputs(start->active, fp);
    fprintf(fp, "\n");
    fputs(start->username,fp);
    fprintf(fp,"\n");
    fputs(start->password,fp);
    fprintf(fp,"\n");
    system("cls");
    printf("The operation was successful.");
    fclose(fp);
    Sleep(2000);
    printf("\n");
    printf("1. New member registration");
    printf("\n");
    printf("2. Back\n");
    printf("Please Enter Your Choice:");
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            New_member();
        }
        if(strcmp(i, two) == 0)
        {
            Staff_menu();
        }
        else
        {
            printf("\nPlease enter a number of above:");
        }
    }
}
void New_book(void)
{
    char i[100];
    struct book *start;
    FILE *fp;
    system("cls");
    fp = fopen("Book Profile.txt","a");
    start = malloc(sizeof(struct book));
    printf("Please enter the name's book:");
    fflush(stdin);
    gets(start->name);
    printf("\n");
    printf("Please enter the name's publication:");
    // baray khali kardan bafer az in tabe estefade kardam.
    fflush(stdin);
    gets(start->publication);
    printf("\n");
    printf("Please enter the name's author:");
    // baray khali kardan bafer az in tabe estefade kardam.
    fflush(stdin);
    gets(start->author);
    printf("\n");
    printf("Please enter the year of publication:");
    // baray khali kardan bafer az in tabe estefade kardam.
    fflush(stdin);
    gets(start->year);
    printf("\n");
    printf("the registration date:");
    date(start->date);
    puts(start->date);
    printf("\n");
    printf("the ID book: ");
    ID_book(start->id);
    puts(start->id);
    printf("\n");
    printf("Please enter the user name for employee:");
    puts(karmand);
    strcpy(start->username,karmand);
    printf("\n");
    printf("Please enter the genre's book:");
    fflush(stdin);
    gets(start->genre);
    printf("\n");
    printf("Someone who borrowed:");
    strcpy(start->username_member, "NULL");
    puts(start->username_member);
    printf("\n");
    printf("Loan date:");
    strcpy(start->date_trust, "NULL");
    puts(start->date_trust);
    puts("\n");
    printf("Return date:");
    strcpy(start->date_take, "NULL");
    puts(start->date_take);
    puts("\n");
    Sleep(2000);
    fputs(start->name,fp);
    fprintf(fp,"\n");
    fputs(start->publication,fp);
    fprintf(fp,"\n");
    fputs(start->author,fp);
    fprintf(fp,"\n");
    fputs(start->year,fp);
    fprintf(fp,"\n");
    fputs(start->date,fp);
    fprintf(fp,"\n");
    fputs(start->id,fp);
    fprintf(fp,"\n");
    fputs(start->username,fp);
    fprintf(fp,"\n");
    fputs(start->genre,fp);
    fprintf(fp, "\n");
    fputs(start->username_member, fp);
    fprintf(fp, "\n");
    fputs(start->date_trust, fp);
    fprintf(fp,"\n");
    system("cls");
    printf("The operation was successful.");
    fclose(fp);
    Sleep(2000);
    printf("\n");
    printf("1. New book registration");
    printf("\n");
    printf("2. Back\n");
    printf("Please Enter Your Choice:");
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            New_book();
        }
        if(strcmp(i , two) == 0)
        {
            Staff_menu();
        }
        else("\nPlease enter one or two");
    }
}
void ID_book(char ID[10])
{
    int i, j;
    struct book *start = NULL, *end = NULL, *temp = NULL;
    char line[100];
    FILE *fp;
    fp = fopen("Book Profile.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct book));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->publication, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->author, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->year, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->id, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->genre, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username_member, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date_trust, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    temp = start;
    j = 1;
    while(temp != NULL)
    {
        i = atoi(temp->id);
        if(j == i)
        {
            temp = temp->link;
        }
        j++;
    }
    sprintf(ID, "%d", j);
    temp = start;
    while(temp != NULL)
    {
        struct book *next;
        next = temp ->link;
        free(temp);
        temp = next;
    }
}
void list_member(void)
{
    char i[100];
    system("cls");
    printf("1. List of active people\n");
    printf("2. List of inactive people\n");
    printf("3. List of Former people\n");
    printf("4. Back\n");
    printf("\n");
    printf("Plese Enter Your Choice:");
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i , one) == 0)
        {
            list_active();
        }
        if(strcmp(i , two) == 0)
        {
            list_inactive();
        }
        if(strcmp(i, three) == 0)
        {
            list_farmer();
        }
        if(strcmp(i, four) == 0)
        {
            Staff_menu();
        }
        else
        {
            printf("\nPlease enter one of the numbers above:\n");
        }
    }
}
void list_active(void)
{
    struct member *start = NULL, *end = NULL, *temp = NULL;
    int j = 0;
    system("cls");
    char line[100], i[100];
    FILE *fp;
    fp = fopen("Member Profile.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct member));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->family, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->end_date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->phone, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->code_meli, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->email, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->active, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->password, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    printf("                                                  1. Back\n");
    temp = start;
    while(temp != NULL)
    {
        if(strcmp(temp->active,"Active") == 0)
        {
            printf("FIRST NAME:                         ");
            puts(temp->name);
            printf("LAST NAME:                          ");
            puts(temp->family);
            printf("REGISTRATION DATE:                  ");
            puts(temp->date);
            printf("MEMBERSHIP EXPIRATION DATE:         ");
            puts(temp->end_date);
            printf("PHONE NUMBER:                       ");
            puts(temp->phone);
            printf("NATIONAL CODE:                      ");
            puts(temp->code_meli);
            printf("EMAIL:                              ");
            puts(temp->email);
            printf("STATUS:                             ");
            puts(temp->active);
            printf("USERNAME:                           ");
            puts(temp->username);
            printf("PASSWORD:                           ");
            puts(temp->password);
            printf("--------------------------------------------------------------------\n");
            temp = temp->link;
            j++;
        }
        else
        {
            temp = temp->link;
        }
    }
    if(j == 0)
    {
        printf("There is no one.");
    }
    temp = start;
    while(temp != NULL)
    {
        struct member *next;
        next = temp ->link;
        free(temp);
        temp = next;
    }
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i , one) == 0)
        {
            list_member();
        }
        else
        {
            printf("Please enter 1.\n");
        }
    }
}
void list_inactive(void)
{
    struct member *start = NULL, *end = NULL, *temp = NULL;
    int j = 0;
    system("cls");
    char line[100], i[100];
    FILE *fp;
    fp = fopen("Member Profile.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct member));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->family, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->end_date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->phone, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->code_meli, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->email, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->active, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->password, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    printf("                                                  1. Back\n");
    temp = start;
    while(temp != NULL)
    {
        if(strcmp(temp->active,"Inactive") == 0)
        {
            printf("FIRST NAME:                         ");
            puts(temp->name);
            printf("LAST NAME:                          ");
            puts(temp->family);
            printf("REGISTRATION DATE:                  ");
            puts(temp->date);
            printf("MEMBERSHIP EXPIRATION DATE:         ");
            puts(temp->end_date);
            printf("PHONE NUMBER:                       ");
            puts(temp->phone);
            printf("NATIONAL CODE:                      ");
            puts(temp->code_meli);
            printf("EMAIL:                              ");
            puts(temp->email);
            printf("STATUS:                             ");
            puts(temp->active);
            printf("USERNAME:                           ");
            puts(temp->username);
            printf("PASSWORD:                           ");
            puts(temp->password);
            printf("--------------------------------------------------------------------\n");
            temp = temp->link;
            j++;
        }
        else
        {
            temp = temp->link;
        }
    }
    if(j == 0)
    {
        printf("There is no one.");
    }
    temp = start;
    while(temp != NULL)
    {
        struct member *next;
        next = temp ->link;
        free(temp);
        temp = next;
    }
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            list_member();
        }
        else
        {
            printf("Please enter 1.\n");
        }
    }
}
void list_farmer(void)
{
    struct member *start = NULL, *end = NULL, *temp = NULL;
    int j = 0;
    system("cls");
    char line[100], i[100];
    FILE *fp;
    fp = fopen("Member Profile.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct member));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->family, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->end_date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->phone, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->code_meli, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->email, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->active, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->password, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    printf("                                                  1. Back\n");
    temp = start;
    while(temp != NULL)
    {
        if(strcmp(temp->active,"Farmer") == 0)
        {
            printf("FIRST NAME:                         ");
            puts(temp->name);
            printf("LAST NAME:                          ");
            puts(temp->family);
            printf("REGISTRATION DATE:                  ");
            puts(temp->date);
            printf("MEMBERSHIP EXPIRATION DATE:         ");
            puts(temp->end_date);
            printf("PHONE NUMBER:                       ");
            puts(temp->phone);
            printf("NATIONAL CODE:                      ");
            puts(temp->code_meli);
            printf("EMAIL:                              ");
            puts(temp->email);
            printf("STATUS:                             ");
            puts(temp->active);
            printf("USERNAME:                           ");
            puts(temp->username);
            printf("PASSWORD:                           ");
            puts(temp->password);
            printf("--------------------------------------------------------------------\n");
            temp = temp->link;
            j++;
        }
        else
        {
            temp = temp->link;
        }
    }
    if(j == 0)
    {
        printf("There is no one.");
    }
    temp = start;
    while(temp != NULL)
    {
        struct member *next;
        next = temp ->link;
        free(temp);
        temp = next;
    }
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            list_member();
        }
        else
        {
            printf("Please enter 1.\n");
        }
    }
}
void delet_member(void)
{
    struct member *start = NULL, *end = NULL, *temp = NULL;
    int j = 0;
    char delet[20], i[100];
    system("cls");
    char line[100];
    FILE *fp;
    fp = fopen("Member Profile.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct member));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->family, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->end_date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->phone, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->code_meli, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->email, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->active, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->password, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    printf("Please enter The username of the member to be deleted:");
    scanf("%s", delet);
    temp = start;
    while(temp != NULL)
    {
        if(strcmp(delet, temp->username) == 0)
        {
            strcpy(temp ->active, "Farmer");
            j++;
        }
        temp = temp->link;
    }
    fp = fopen("Member Profile.txt", "w");
    temp = start;
    while(temp != NULL)
    {
        fputs(temp->name,fp);
        fprintf(fp,"\n");
        fputs(temp->family,fp);
        fprintf(fp,"\n");
        fputs(temp->date,fp);
        fprintf(fp,"\n");
        fputs(temp->end_date, fp);
        fprintf(fp, "\n");
        fputs(temp->phone,fp);
        fprintf(fp,"\n");
        fputs(temp->code_meli,fp);
        fprintf(fp,"\n");
        fputs(temp->email,fp);
        fprintf(fp,"\n");
        fputs(temp->active, fp);
        fprintf(fp, "\n");
        fputs(temp->username,fp);
        fprintf(fp,"\n");
        fputs(temp->password,fp);
        fprintf(fp,"\n");
        temp = temp->link;
    }
    fclose(fp);
    temp = start;
    while(temp != NULL)
    {
        struct member *next;
        next = temp ->link;
        free(temp);
        temp = next;
    }
    if(j == 1)
    {
        printf("%s's removal was successful.                          1.back\n", delet);
    }
    else
    {
        printf("No one named %s was found.                            1.back\n", delet);
    }
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            Staff_menu();
        }
        else
        {
            printf("Please enter 1.\n");
        }
    }
}
void setting_employee(void)
{
    system("cls");
    char i[100];
    printf("%s\n", karmand);
    printf("\n1. Change Password\n");
    printf("2. Change Email\n");
    printf("3. Change Phone Number\n");
    printf("4. Back\n");
    printf("\n");
    printf("Please Enter Your Choice:");
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            Change_Password();
        }
        if(strcmp(i, two) == 0)
        {
            Change_Email();
        }
        if(strcmp(i , three) == 0)
        {
            Change_Phone();
        }
        if(strcmp(i, four) == 0)
        {
            Staff_menu();
        }
        else
        {
            printf("Please enter number of above:\n");
        }
    }
}
void Change_Password(void)
{
    system("cls");
    struct employee *start = NULL, *end = NULL, *temp = NULL;
    system("cls");
    char line[100], i[100];
    FILE *fp;
    fp = fopen("Employee Profile.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct employee));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->family, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->phone, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->code_meli, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->email, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->password, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    temp = start;
    while(temp != NULL)
    {
        if(strcmp(temp->username, karmand) == 0)
        {
            printf("Please enter the New password:                              1.Back\n");
            scanf("%s", temp->password);
            if(strcmp(temp->password, one) == 0)
            {
                setting_employee();
            }
        }
        temp = temp->link;
    }
    temp = start;
    fp = fopen("Employee Profile.txt", "w");
    while(temp != NULL)
    {
        fputs(temp->name,fp);
        fprintf(fp, "\n");
        fputs(temp->family,fp);
        fprintf(fp, "\n");
        fputs(temp->date,fp);
        fprintf(fp, "\n");
        fputs(temp->phone,fp);
        fprintf(fp, "\n");
        fputs(temp->code_meli,fp);
        fprintf(fp, "\n");
        fputs(temp->email,fp);
        fprintf(fp, "\n");
        fputs(temp->username,fp);
        fprintf(fp, "\n");
        fputs(temp->password,fp);
        fprintf(fp, "\n");
        temp = temp->link;
    }
    fclose(fp);
    temp = start;
    while(temp != NULL)
    {
        struct employee *next;
        next = temp ->link;
        free(temp);
        temp = next;
    }
    system("cls");
    printf("The operation was successful.\n");
    Sleep(1000);
    printf("1. Back\n");
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            setting_employee();
        }
        else
        {
            printf("Please enter 1.\n");
        }
    }
}
void Change_Email(void)
{
    system("cls");
    struct employee *start = NULL, *end = NULL, *temp = NULL;
    char line[100], i[100];
    FILE *fp;
    fp = fopen("Employee Profile.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct employee));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->family, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->phone, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->code_meli, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->email, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->password, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    temp = start;
    while(temp != NULL)
    {
        if(strcmp(temp->username, karmand) == 0)
        {
            printf("Please enter the New email:                              1.Back\n");
            scanf("%s", temp->email);
            if(strcmp(temp->email, one) == 0)
            {
                setting_employee();
            }
        }
        temp = temp->link;
    }
    temp = start;
    fp = fopen("Employee Profile.txt", "w");
    while(temp != NULL)
    {
        fputs(temp->name,fp);
        fprintf(fp, "\n");
        fputs(temp->family,fp);
        fprintf(fp, "\n");
        fputs(temp->date,fp);
        fprintf(fp, "\n");
        fputs(temp->phone,fp);
        fprintf(fp, "\n");
        fputs(temp->code_meli,fp);
        fprintf(fp, "\n");
        fputs(temp->email,fp);
        fprintf(fp, "\n");
        fputs(temp->username,fp);
        fprintf(fp, "\n");
        fputs(temp->password,fp);
        fprintf(fp, "\n");
        temp = temp->link;
    }
    fclose(fp);
    temp = start;
    while(temp != NULL)
    {
        struct employee *next;
        next = temp ->link;
        free(temp);
        temp = next;
    }
    system("cls");
    printf("The operation was successful.\n");
    Sleep(1000);
    printf("1. Back\n");
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            setting_employee();
        }
        else
        {
            printf("Please enter 1.\n");
        }
    }
}
void Change_Phone(void)
{
    system("cls");
    struct employee *start = NULL, *end = NULL, *temp = NULL;
    char line[100], i[100];
    FILE *fp;
    fp = fopen("Employee Profile.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct employee));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->family, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->phone, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->code_meli, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->email, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->password, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    temp = start;
    while(temp != NULL)
    {
        if(strcmp(temp->username, karmand) == 0)
        {
            printf("Please enter the New number phone:                              1.Back\n");
            scanf("%s", temp->phone);
            if(strcmp(temp->phone, one) == 0)
            {
                setting_employee();
            }
        }
        temp = temp->link;
    }
    temp = start;
    fp = fopen("Employee Profile.txt", "w");
    while(temp != NULL)
    {
        fputs(temp->name,fp);
        fprintf(fp, "\n");
        fputs(temp->family,fp);
        fprintf(fp, "\n");
        fputs(temp->date,fp);
        fprintf(fp, "\n");
        fputs(temp->phone,fp);
        fprintf(fp, "\n");
        fputs(temp->code_meli,fp);
        fprintf(fp, "\n");
        fputs(temp->email,fp);
        fprintf(fp, "\n");
        fputs(temp->username,fp);
        fprintf(fp, "\n");
        fputs(temp->password,fp);
        fprintf(fp, "\n");
        temp = temp->link;
    }
    fclose(fp);
    temp = start;
    while(temp != NULL)
    {
        struct employee *next;
        next = temp ->link;
        free(temp);
        temp = next;
    }
    system("cls");
    printf("The operation was successful.\n");
    Sleep(1000);
    printf("1. Back\n");
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            setting_employee();
        }
        else
        {
            printf("Please enter 1.\n");
        }
    }
}
void renewal(void)
{
    system("cls");
    struct member *start = NULL, *end = NULL, *temp = NULL;
    char line[100], user[20], j[100];
    int i = 0;
    FILE *fp;
    fp = fopen("Member Profile.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct member));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->family, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->end_date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->phone, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->code_meli, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->email, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->active, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->password, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    printf("Please enter the username of the person whose validity is to be extended: ");
    scanf("%s", user);
    temp = start;
    while(temp != NULL)
    {
        if(strcmp(temp->username, user) == 0)
        {
            validity(temp->end_date);
            printf("Membership expiration date: ");
            puts(temp->end_date);
            i++;
        }
        temp = temp -> link;
    }
    if( i == 0 )
    {
        printf("No one was found.\n");
        printf("1. Try again\n");
        printf("2. Back\n");
        while(1)
        {
            scanf("%s", j);
            if(strcmp(j , one) == 0)
            {
                renewal();
            }
            else
            {
                if(strcmp(j , two) == 0)
                {
                    Staff_menu();
                }
                else
                {
                    printf("Please enter one or two.\n");
                }
            }
        }
    }
    else
    {
        temp = start;
        fp = fopen("Member Profile.txt", "w");
        while(temp != NULL)
        {
            fputs(temp->name,fp);
            fprintf(fp,"\n");
            fputs(temp->family,fp);
            fprintf(fp,"\n");
            fputs(temp->date,fp);
            fprintf(fp,"\n");
            fputs(temp->end_date, fp);
            fprintf(fp, "\n");
            fputs(temp->phone,fp);
            fprintf(fp,"\n");
            fputs(temp->code_meli,fp);
            fprintf(fp,"\n");
            fputs(temp->email,fp);
            fprintf(fp,"\n");
            fputs(temp->active, fp);
            fprintf(fp, "\n");
            fputs(temp->username,fp);
            fprintf(fp,"\n");
            fputs(temp->password,fp);
            fprintf(fp,"\n");
            temp = temp->link;
        }
        fclose(fp);
        temp = start;
        while(temp != NULL)
        {
            struct member *next;
            next = temp ->link;
            free(temp);
            temp = next;
        }
        remainder();
        printf("The operation was successful.\n");
        Sleep(1000);
        printf("1. Renewal of another member.\n");
        printf("2. Back\n");
        while(1)
        {
            scanf("%s", j);
            if(strcmp(j , one) == 0)
            {
                renewal();
            }
            else
            {
                if(strcmp(j , two) == 0)
                {
                    Staff_menu();
                }
                else
                {
                    printf("Please enter one or two.\n");
                }
            }
        }
    }
}
void Member_login(void)
{
    system("cls");
    int j = 0;
    char user_name[20], user_password[20], i[100], save[20];
    struct member *start = NULL, *end = NULL, *temp = NULL;
    char line[100];
    FILE *fp;
    fp = fopen("Member Profile.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct member));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->family, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->end_date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->phone, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->code_meli, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->email, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->active, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->password, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    printf("Please enter your username: ");
    fflush(stdin);
    scanf("%s", user_name);
    temp = start;
    while(temp != NULL)
    {
        if(strcmp(temp->username, user_name) == 0)
        {
            strcpy(save, temp->active);
            break;
        }
        temp = temp->link;
    }
    //agar ta akhar check anjam shavad va user name paida nashavad vared in shart mishavad
    if((temp == NULL) || (strcmp(save, "Farmer") == 0))
    {
        // print mishe ke user name vojod nadarad.
        if(temp == NULL)
        {
            printf("This username doesn't exist.\n");
        }
        if(strcmp(save, "Farmer") == 0)
        {
            printf("You have been removed.\n");
        }
        Sleep(1000);
        printf("1. to try again.\n");
        printf("2. back.\n");
        while(1)
        {
            scanf("%s", i);
            if(strcmp(i, one) == 0)
            {
                Member_login();
            }
            else
            {
                if(strcmp(i, two) == 0)
                {
                    menu();
                }
                else
                {
                    printf("\nPlease enter a number of above: ");
                }
            }
         }
    }
    else
    {
        //baray inke dar tol ejra barname username karmand ro dashtebashim.
        strcpy(ozve,temp->username);
        system("cls");
        printf("%s %s                                          1.back   2.exit\n", temp->name, temp->family);
        printf("\nPlease enter the your password:");
        while(j != 1)
        {
            fflush(stdin);
            //inaja yek password az karbar gerefte mishavad
            scanf("%s", user_password);
            // va ba password karbar moghyese mishavad
            if(strcmp(user_password, temp->password) == 0)
            {
                //agar barabar bod az halghe kharej mishavad.
                j++;
            }
            else
            {
                if(strcmp(user_password, one ) == 0)
                {
                    // zamani ke karbar adad yek ra vared konad vard ghesmat menu mishavad.
                    menu();
                }
                else
                {
                    if(strcmp(user_password, two) == 0)
                    {
                        // zamani ke sefr vared shavad az barname khrej mishavad.
                        exit(0);
                    }
                    else
                    {
                        // har bar ramz ghalat bashad in chap mishavd.
                        printf("Password is false!");
                        printf("\n");
                        printf("Please enter again.\n");
                    }
                }
            }
        }
    }
    // vaghti ozve login kone vared menu ozve mishim.
    Member_menu();
}
void Member_menu(void)
{
    char i[100];
    // inja safe menu karmand namayesh dade mishavad.
    system("cls");
    puts(ozve);
    printf("\n");
    printf("1. Register a new trust");
    printf("\n");
    printf("2. Book return registration");
    printf("\n");
    printf("3. List of books I borrowed");
    printf("\n");
    printf("4. View the list of books available for loan");
    printf("\n");
    printf("5. Account settings");
    printf("\n");
    printf("6. log out of account");
    printf("\n");
    printf("\n");
    printf("Please Enter Your Choice:");
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            register_trust();
        }
        else
        {
            if(strcmp(i, two) == 0)
            {
                register_return();
            }
            else
            {
                if(strcmp(i, three) == 0)
                {
                    my_book_list();
                }
                else
                {
                    if(strcmp(i, four) == 0)
                    {
                        books();
                    }
                    else
                    {
                        if(strcmp(i, five) == 0)
                        {
                            setting_member();
                        }
                        else
                        {
                            if(strcmp(i, six) == 0)
                            {
                                menu();
                            }
                        }
                    }
                }
            }
        }

    }
}
void register_trust(void)
{
    system("cls");
    char id[100], i[100];
    int j = 0;
    FILE *fp, *fp1;
    char line[100];
    struct book *start = NULL, *temp = NULL, *end = NULL;
    fp = fopen("Book Profile.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct book));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->publication, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->author, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->year, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->id, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->genre, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username_member, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date_trust, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date_take, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    printf("Please enter the book id: ");
    scanf("%s", id);
    temp  = start;
    while(temp != NULL)
    {
        if(strcmp(id, temp->id) == 0)
        {
            if(strcmp(temp->username_member, "NULL") == 0)
            {
                strcpy(temp->username_member, ozve);
                date(temp->date_trust);
                validity_book(temp->date_take);
                j++;
                break;
            }
            else
            {
                printf("This Book is in someone else's hands.\n");
                printf("1. You want another book.\n");
                printf("2. Back");
                while(1)
                {
                    scanf("%s", i);
                    if(strcmp(i, one) == 0)
                    {
                        temp = start;
                        while(temp != NULL)
                        {
                            struct book *next;
                            next = temp ->link;
                            free(temp);
                            temp = next;
                        }
                        register_trust();
                    }
                    else
                    {
                        temp = start;
                        if(strcmp(i, two) == 0)
                        {
                            while(temp != NULL)
                            {
                                struct book *next;
                                next = temp ->link;
                                free(temp);
                                temp = next;
                            }
                            Member_menu();
                        }
                        else
                        {
                            printf("Please enter the number of above: ");
                        }
                    }
                }
            }
        }
        temp = temp->link;
    }
    if(j != 0)
    {
        printf("The operation was successful.\n");
    }
    else
    {
        printf("There is no book with this ID.\n");
    }
    fp = fopen("Book Profile.txt", "w");
    fp1 = fopen("My Book.txt", "a");
    temp = start;
    while(temp != NULL)
    {
        if(strcmp(temp->username_member, ozve) == 0)
        {
            fputs(temp->username_member, fp1);
            fprintf(fp1, "\n");
            fputs(temp->name,fp1);
            fprintf(fp1,"\n");
            fputs(temp->date_trust, fp1);
            fprintf(fp1, "\n");
            fputs(temp->date_take, fp1);
            fprintf(fp1, "\n");
            fputs(temp->id, fp1);
            fprintf(fp1,"\n");
        }
        fputs(temp->name,fp);
        fprintf(fp,"\n");
        fputs(temp->publication,fp);
        fprintf(fp,"\n");
        fputs(temp->author,fp);
        fprintf(fp,"\n");
        fputs(temp->year,fp);
        fprintf(fp,"\n");
        fputs(temp->date,fp);
        fprintf(fp,"\n");
        fputs(temp->id,fp);
        fprintf(fp,"\n");
        fputs(temp->username,fp);
        fprintf(fp,"\n");
        fputs(temp->genre,fp);
        fprintf(fp, "\n");
        fputs(temp->username_member, fp);
        fprintf(fp, "\n");
        fputs(temp->date_trust, fp);
        fprintf(fp,"\n");
        fputs(temp->date_take, fp);
        fprintf(fp, "\n");
        temp = temp->link;
    }
    fclose(fp);
    fclose(fp1);
    temp = start;
    while(temp != NULL)
    {
        struct book *next;
        next = temp ->link;
        free(temp);
        temp = next;
    }
    Sleep(1000);
    printf("1. Borrowing another book\n");
    printf("2. Back\n");
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            register_trust();
        }
        else
        {
            if(strcmp(i,two) == 0)
            {
                Member_menu();
            }
            else
            {
                printf("Please enter the number of above: \n");
            }
        }
    }
}
void register_return(void)
{
    system("cls");
    FILE *fp;
    char line[100], ID[100], i[100], date_return[11];
    struct book *start = NULL, *temp = NULL, *end = NULL;
    fp = fopen("Book Profile.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct book));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->publication, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->author, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->year, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->id, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->genre, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username_member, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date_trust, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date_take, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    printf("Please enter the id's book: ");
    fflush(stdin);
    scanf("%s", ID);
    temp = start;
    while(temp != NULL)
    {
        if(strcmp(temp->id, ID) == 0)
        {
            if(strcmp(temp->username_member, ozve) == 0)
            {
                fp = fopen("Return Book.txt", "a");
                fputs(temp->username_member, fp);
                fprintf(fp, "\n");
                fputs(temp->name,fp);
                fprintf(fp,"\n");
                fputs(temp->date_trust, fp);
                fprintf(fp, "\n");
                fputs(temp->date_take, fp);
                fprintf(fp, "\n");
                date(date_return);
                fputs(date_return, fp);
                fprintf(fp, "\n");
                fputs(temp->id, fp);
                fprintf(fp,"\n");
                fclose(fp);
                strcpy(temp->username_member,"NULL");
                strcpy(temp->date_take, "NULL");
                strcpy(temp->date_trust, "NULL");
                printf("The operation was successful.\n");
                fp = fopen("Book Profile.txt", "w");
                temp = start;
                while(temp != NULL)
                {
                    fputs(temp->name,fp);
                    fprintf(fp,"\n");
                    fputs(temp->publication,fp);
                    fprintf(fp,"\n");
                    fputs(temp->author,fp);
                    fprintf(fp,"\n");
                    fputs(temp->year,fp);
                    fprintf(fp,"\n");
                    fputs(temp->date,fp);
                    fprintf(fp,"\n");
                    fputs(temp->id,fp);
                    fprintf(fp,"\n");
                    fputs(temp->username,fp);
                    fprintf(fp,"\n");
                    fputs(temp->genre,fp);
                    fprintf(fp, "\n");
                    fputs(temp->username_member, fp);
                    fprintf(fp, "\n");
                    fputs(temp->date_trust, fp);
                    fprintf(fp,"\n");
                    fputs(temp->date_take, fp);
                    fprintf(fp, "\n");
                    temp = temp->link;
                }
                fclose(fp);
                temp = start;
                while(temp != NULL)
                {
                    struct book *next;
                    next = temp ->link;
                    free(temp);
                    temp = next;
                }
                printf("1. Back\n");
                while(1)
                {
                    scanf("%s", i);
                    if(strcmp(i, one) == 0)
                    {
                        Member_menu();
                    }
                    else
                    {
                        printf("Please enter one.\n");
                    }
                }
            }
            else
            {
                printf("This book is not available in this library or you have already returned this book.\n");
                printf("1. Try again\n");
                printf("2. Back\n");
                temp = start;
                while(temp != NULL)
                {
                    struct book *next;
                    next = temp ->link;
                    free(temp);
                    temp = next;
                }
                fflush(stdin);
                while(1)
                {
                    scanf("%s", i);
                    if(strcmp(i, one) == 0)
                    {
                        register_return();
                    }
                    else
                    {
                        if(strcmp(i, two) == 0)
                        {
                            Member_menu();
                        }
                        else
                        {
                            printf("Please enter the number of above: \n");
                        }
                    }
                }
            }
        }
        else
        {
            temp = temp -> link;
        }
    }
    temp = start;
    while(temp != NULL)
    {
        struct book *next;
        next = temp ->link;
        free(temp);
        temp = next;
    }
    printf("This book is not available in this library.\n");
    printf("1. Try again\n");
    printf("2. Back\n");
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            register_return();
        }
        else
        {
            if(strcmp(i, two) == 0)
            {
                Member_menu();
            }
            else
            {
                printf("Please enter the number of above: \n");
            }
        }
    }
}
void my_book_list(void)
{
    system("cls");
    char i[100];
    printf("1. List of returned books.\n");
    printf("2. List of unreturned books.\n");
    printf("3. Back");
    printf("\n");
    printf("Please Enter Your Choice:");
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            my_return_book();
        }
        else
        {
            if(strcmp(i, two) == 0)
            {
                my_unreturn_book();
            }
            else
            {
                if(strcmp(i, three) == 0)
                {
                    Member_menu();
                }
                else
                {
                    printf("Please enter the number of above :\n");
                }
            }
        }
    }
}
void my_unreturn_book(void)
{
    system("cls");
    FILE *fp;
    char line[100], i[100], today[11];
    int j = 0;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    struct book *start = NULL, *temp = NULL, *end = NULL;
    date(today);
    fp = fopen("Book Profile.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct book));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->publication, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->author, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->year, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->id, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->genre, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username_member, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date_trust, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date_take, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    temp = start;
    printf("                                                  1. Back\n");
    while(temp != NULL)
    {
        if(strcmp(temp->username_member, ozve) == 0)
        {
            if(strcmp(today, temp->date_take) > 0)
            {
                printf("NAME'S BOOK:                        ");
                SetConsoleTextAttribute(hConsole, 12);
                puts(temp->name);
                SetConsoleTextAttribute(hConsole, 7);
                printf("ID:                                 ");
                SetConsoleTextAttribute(hConsole, 12);
                puts(temp->id);
                SetConsoleTextAttribute(hConsole, 7);
                printf("TRUST REGISTRATION DATE:            ");
                SetConsoleTextAttribute(hConsole, 12);
                puts(temp->date_trust);
                SetConsoleTextAttribute(hConsole, 7);
                printf("BOOK RETURN DATE:                   ");
                SetConsoleTextAttribute(hConsole, 12);
                puts(temp->date_take);
                SetConsoleTextAttribute(hConsole, 7);
                printf("--------------------------------------------------------------------\n");
                j++;
            }
            else
            {
                printf("NAME'S BOOK:                        ");
                puts(temp->name);
                printf("ID:                                 ");
                puts(temp->id);
                printf("TRUST REGISTRATION DATE:            ");
                puts(temp->date_trust);
                printf("BOOK RETURN DATE:                   ");
                puts(temp->date_take);
                printf("--------------------------------------------------------------------\n");
                j++;
            }
        }
        temp = temp->link;
    }
    if( j == 0)
    {
        printf("No book are registered in your name.");
    }
    temp = start;
    while(temp != NULL)
    {
        struct book *next;
        next = temp ->link;
        free(temp);
        temp = next;
    }
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            my_book_list();
        }
        else
        {
            printf("Please enter one.");
        }
    }
}
void my_return_book(void)
{
    system("cls");
    FILE *fp;
    char line[100], i[100];
    int j = 0;
    struct return_book *start = NULL, *temp = NULL, *end = NULL;
    fp = fopen("Return Book.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct return_book));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->user_name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->name, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date_trust, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date_take, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date_return, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->id, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    temp = start;
    printf("                                                  1. Back\n");
    while(temp != NULL)
    {
        if(strcmp(temp->user_name, ozve) == 0)
        {
            printf("NAME'S BOOK:                        ");
            puts(temp->name);
            printf("ID:                                 ");
            puts(temp->id);
            printf("TRUST REGISTRATION DATE:            ");
            puts(temp->date_trust);
            printf("BOOK RETURN DATE:                   ");
            puts(temp->date_take);
            printf("--------------------------------------------------------------------\n");
            j++;
        }
        temp = temp->link;
    }
    while(temp != NULL)
    {
        struct return_book *next;
        next = temp ->link;
        free(temp);
        temp = next;
    }
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            my_book_list();
        }
        else
        {
            printf("Please enter one.");
        }
    }
}
void books(void)
{
    system("cls");
    char i[100];
    printf("1. List of books available for borrowing.\n");
    printf("2. List of books available in the library.\n");
    printf("3. Back.\n");
    printf("\n");
    printf("Please Enter Your Choice:");
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            book_list_borrowing();
        }
        else
        {
            if(strcmp(i, two) == 0)
            {
                book_list();
            }
            else
            {
                if(strcmp(i, three) == 0)
                {
                    Member_menu();
                }
                else
                {
                    printf("Please enter the number of above :\n");
                }
            }
        }
    }
}
void book_list_borrowing(void)
{
    system("cls");
    FILE *fp;
    char line[100], i[100];
    struct book *start = NULL, *temp = NULL, *end = NULL;
    fp = fopen("Book Profile.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct book));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->publication, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->author, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->year, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->id, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->genre, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username_member, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date_trust, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date_take, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    printf("                                                  1. Back\n");
    temp = start;
    while(temp != NULL)
    {
        if(strcmp(temp->username_member, "NULL") == 0)
        {
            printf("NAME'S BOOK:                        ");
            puts(temp->name);
            printf("NAME'S PUBLICATION:                 ");
            puts(temp->publication);
            printf("NAME'S AUTHOR:                      ");
            puts(temp->author);
            printf("ID:                                 ");
            puts(temp->id);
            printf("GENRE:                              ");
            puts(temp->genre);
            printf("--------------------------------------------------------------------\n");
        }
        temp = temp->link;
    }
    temp = start;
    while(temp != NULL)
    {
        struct book *next;
        next = temp ->link;
        free(temp);
        temp = next;
    }
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            books();
        }
        else
        {
            printf("Please enter one.\n");
        }
    }
}
void book_list(void)
{
    system("cls");
    FILE *fp;
    char line[100], i[100];
    struct book *start = NULL, *temp = NULL, *end = NULL;
    fp = fopen("Book Profile.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct book));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->publication, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->author, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->year, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->id, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->genre, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username_member, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date_trust, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date_take, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    printf("                                                  1. Back\n");
    temp = start;
    while(temp != NULL)
    {
        printf("NAME'S BOOK:                        ");
        puts(temp->name);
        printf("NAME'S PUBLICATION:                 ");
        puts(temp->publication);
        printf("NAME'S AUTHOR:                      ");
        puts(temp->author);
        printf("ID:                                 ");
        puts(temp->id);
        printf("GENRE:                              ");
        puts(temp->genre);
        printf("--------------------------------------------------------------------\n");
        temp = temp->link;
    }
    temp = start;
    while(temp != NULL)
    {
        struct book *next;
        next = temp ->link;
        free(temp);
        temp = next;
    }
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            books();
        }
        else
        {
            printf("Please enter one.\n");
        }
    }
}
void setting_member(void)
{
    system("cls");
    char i[100];
    printf("%s\n", ozve);
    printf("\n1. Change Password\n");
    printf("2. Change Email\n");
    printf("3. Change Phone Number\n");
    printf("4. Back\n");
    printf("\n");
    printf("Please Enter Your Choice:");
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            Change_Password_Member();
        }
        if(strcmp(i, two) == 0)
        {
            Change_Email_Member();
        }
        if(strcmp(i , three) == 0)
        {
            Change_Phone_Member();
        }
        if(strcmp(i, four) == 0)
        {
            Member_menu();
        }
        else
        {
            printf("Please enter number of above:\n");
        }
    }
}
void Change_Password_Member(void)
{
    system("cls");
    struct member *start = NULL, *end = NULL, *temp = NULL;
    char line[100], i[100];
    FILE *fp;
    fp = fopen("Member Profile.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct member));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->family, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->end_date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->phone, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->code_meli, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->email, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->active, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->password, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    temp = start;
    while(temp != NULL)
    {
        if(strcmp(temp->username, ozve) == 0)
        {
            printf("Please enter the New password:                              1.Back\n");
            scanf("%s", temp->password);
            if(strcmp(temp->password, one) == 0)
            {
                setting_member();
            }
        }
        temp = temp->link;
    }
    temp = start;
    fp = fopen("Member Profile.txt", "w");
    while(temp != NULL)
    {
        fputs(temp->name,fp);
        fprintf(fp, "\n");
        fputs(temp->family,fp);
        fprintf(fp, "\n");
        fputs(temp->date, fp);
        fprintf(fp, "\n");
        fputs(temp->end_date, fp);
        fprintf(fp, "\n");
        fputs(temp->phone,fp);
        fprintf(fp, "\n");
        fputs(temp->code_meli,fp);
        fprintf(fp, "\n");
        fputs(temp->email,fp);
        fprintf(fp, "\n");
        fputs(temp->active, fp);
        fprintf(fp, "\n");
        fputs(temp->username,fp);
        fprintf(fp, "\n");
        fputs(temp->password,fp);
        fprintf(fp, "\n");
        temp = temp->link;
    }
    fclose(fp);
    temp = start;
    while(temp != NULL)
    {
        struct member *next;
        next = temp ->link;
        free(temp);
        temp = next;
    }
    system("cls");
    printf("The operation was successful.\n");
    Sleep(1000);
    printf("1. Back\n");
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            setting_member();
        }
        else
        {
            printf("Please enter 1.\n");
        }
    }
}
void Change_Email_Member(void)
{
    system("cls");
    struct member *start = NULL, *end = NULL, *temp = NULL;
    char line[100], i[100];
    FILE *fp;
    fp = fopen("Member Profile.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct member));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->family, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->end_date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->phone, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->code_meli, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->email, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->active, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->password, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    temp = start;
    while(temp != NULL)
    {
        if(strcmp(temp->username, ozve) == 0)
        {
            printf("Please enter the New email:                              1.Back\n");
            scanf("%s", temp->email);
            if(strcmp(temp->email, one) == 0)
            {
                setting_member();
            }
        }
        temp = temp->link;
    }
    temp = start;
    fp = fopen("Member Profile.txt", "w");
    while(temp != NULL)
    {
        fputs(temp->name,fp);
        fprintf(fp, "\n");
        fputs(temp->family,fp);
        fprintf(fp, "\n");
        fputs(temp->date, fp);
        fprintf(fp, "\n");
        fputs(temp->end_date, fp);
        fprintf(fp, "\n");
        fputs(temp->phone,fp);
        fprintf(fp, "\n");
        fputs(temp->code_meli,fp);
        fprintf(fp, "\n");
        fputs(temp->email,fp);
        fprintf(fp, "\n");
        fputs(temp->active, fp);
        fprintf(fp, "\n");
        fputs(temp->username,fp);
        fprintf(fp, "\n");
        fputs(temp->password,fp);
        fprintf(fp, "\n");
        temp = temp->link;
    }
    fclose(fp);
    temp = start;
    while(temp != NULL)
    {
        struct member *next;
        next = temp ->link;
        free(temp);
        temp = next;
    }
    system("cls");
    printf("The operation was successful.\n");
    Sleep(1000);
    printf("1. Back\n");
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            setting_member();
        }
        else
        {
            printf("Please enter 1.\n");
        }
    }
}
void Change_Phone_Member(void)
{
    system("cls");
    struct member *start = NULL, *end = NULL, *temp = NULL;
    char line[100], i[100];
    FILE *fp;
    fp = fopen("Member Profile.txt", "r");
    while(1)
    {
        temp = malloc(sizeof(struct member));
        if(fgets(line, sizeof(line), fp) == NULL)
        {
            break;
        }
        // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp->name, line);
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->family, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->end_date, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->phone, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->code_meli, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->email, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->active, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->username, line);
        }
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->password, line);
        }
        temp->link = NULL;
        if(start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->link = temp;
            end = temp;
        }
    }
    fclose(fp);
    temp = start;
    while(temp != NULL)
    {
        if(strcmp(temp->username, ozve) == 0)
        {
            printf("Please enter the New number phone:                              1.Back\n");
            scanf("%s", temp->phone);
            if(strcmp(temp->phone, one) == 0)
            {
                setting_member();
            }
        }
        temp = temp->link;
    }
    temp = start;
    fp = fopen("Member Profile.txt", "w");
    while(temp != NULL)
    {
        fputs(temp->name,fp);
        fprintf(fp, "\n");
        fputs(temp->family,fp);
        fprintf(fp, "\n");
        fputs(temp->date, fp);
        fprintf(fp, "\n");
        fputs(temp->end_date, fp);
        fprintf(fp, "\n");
        fputs(temp->phone,fp);
        fprintf(fp, "\n");
        fputs(temp->code_meli,fp);
        fprintf(fp, "\n");
        fputs(temp->email,fp);
        fprintf(fp, "\n");
        fputs(temp->active, fp);
        fprintf(fp, "\n");
        fputs(temp->username,fp);
        fprintf(fp, "\n");
        fputs(temp->password,fp);
        fprintf(fp, "\n");
        temp = temp->link;
    }
    fclose(fp);
    temp = start;
    while(temp != NULL)
    {
        struct member *next;
        next = temp ->link;
        free(temp);
        temp = next;
    }
    system("cls");
    printf("The operation was successful.\n");
    Sleep(1000);
    printf("1. Back\n");
    while(1)
    {
        scanf("%s", i);
        if(strcmp(i, one) == 0)
        {
            setting_member();
        }
        else
        {
            printf("Please enter 1.\n");
        }
    }
}
