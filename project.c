#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
void date(char datestr[11]);
void validity(char val_date[11]);
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
char one[2] = {'1'}, two[2] = {'2'}, three[2] = {'3'}, four[2] = {'4'}, five[2] = {'5'}, six[2] = {'6'}, seven[2] = {'7'}, eight[2] = {'8'}, nine[2] = {'9'};
char karmand[20];
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
    struct book *link;
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
void validity(char val_date[11])
{
    time_t t;
    t = time(NULL);
    // tm = mohtavay khane t.
    struct tm tm = *localtime(&t);
    sprintf(val_date,"%04d-%02d-%02d", tm.tm_year + 1901, tm.tm_mon + 1 , tm.tm_mday);
}
void remainder(void)
{
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
            // vaghti ramz dorost bashad vared menu Admin mishavad.
            Admin_menu();
        }
        if(strcmp(i, two) == 0)
        {
            Staff_login();
            // vaghti karmand login kone vared menu karmand mishim.
            Staff_menu();
        }
        if(strcmp(i, three) == 0)
        {

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
    int i = 0;
    system("cls");
    char username[6];
    char defult_username[6]={'A','d','m','i','n'};
    char password[11];
    //enja password admin ro tarif mikonim.
    char defult_password[11] = {'@','A','m','i','r','_','1','3','8','5'};
    printf("Please enter the your username: ");
    scanf("%s", username);
    if(strcmp(username, defult_username) == 0)
    {
        system("cls");
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
    else
    {
        printf("Username is False.\n");
        printf("1. Try again.");
        printf("2. back");
        while(1)
        {
            scanf("%d", &i);
            if(i = 1)
            {
                Admin_Login();
            }
            if(i = 2)
            {
                menu();
            }
            else
            {
                printf("\nPlease enter the one or two: ");
            }
        }
    }
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
        while(j != 1)
        {
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

        }
        if(strcmp(i , three) == 0)
        {

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
    char line[100], Ramz[20], i[100];
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
        struct member *next;
        next = temp ->link;
        free(temp);
        temp = next;
    }
    system("cls");
    printf("The operation was successful.");
    Sleep(1000);
    printf("1. Back\n");
    scanf("%s", i);
    if(strcmp(i, one) == 0)
    {
        setting_employee();
    }
    else
    {

    }
}
