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
void Staff_login(void);
void Staff_menu(void);
void New_member(void);
void New_book(void);
char ID_book(void);
int i;
char one[2] = {'1'}, two[2] = {'2'};
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
    char phone[12];
    char code_meli[11];
    char email[40];
    char active[20];
    char username[20];
    char password[20];
    struct member *link;
};
struct book{
    char name[20];
    char publication[20];
    char author[20];
    char year[5];
    char date[11];
    char id;
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
        Staff_login();
        // vaghti karmand login kone vared menu karmand mishim.
        Staff_menu();
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
    if(i == 4)
    {

    }
    if(i == 5)
    {
        menu();
    }
}
void New_employee(void)
{
    int i;
    struct employee *start, *temp;
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
    printf("2. Back\n");
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
    struct employee *start = NULL, *end = NULL, *temp = NULL;
    int i;
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
    printf("                                                  1. Back\n");
    temp = start;
    while(temp != NULL)
    {
       puts(temp->name);
       puts(temp->family);
       puts(temp->date);
       puts(temp->phone);
       puts(temp->code_meli);
       puts(temp->email);
       puts(temp->username);
       puts(temp->password);
       printf("-----------------------------------------\n");
       temp = temp->link;
    }
    while(temp != NULL)
    {
        struct employee *next;
        next = temp ->link;
        free(temp);
        temp = next;
    }
    scanf("%d", &i);
    if(i == 1)
    {
        Admin_menu();
    }
}
void delet_employee(void)
{
    struct employee *start = NULL, *end = NULL, *temp = NULL;
    int i, j = 0;
    char delet[20];
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
    printf("Please enter The name of the employee to be deleted:");
    scanf("%s", delet);
    temp = start;
    fp1 = fopen("Employee Profile.txt","w");
    fp2 = fopen("Deleted Employee Profile.txt", "a");
    while(temp != NULL)
    {

        if(strcmp(delet, temp->name) == 0)
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
    scanf("%d", &i);
    if(i == 1)
    {
        Admin_menu();
    }
}
void Staff_login(void)
{
    system("cls");
    int i = 0;
    char user_name[20], user_password[20];
    struct employee *start = NULL, *end = NULL, *temp = NULL;
    char line[100];
    FILE *fp;
    fp = fopen("Employee Profile.txt", "r");
    while(feof(fp) == 0)
    {
        temp = malloc(sizeof(struct employee));
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->name, line);
        }
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
        scanf("%d", &i);
        if(i == 1)
        {
            Staff_login();
        }
        else
        {
            menu();
        }
    }
    else
    {
        //baray inke dar tol ejra barname username karmand ro dashtebashim.
        strcpy(karmand,temp->username);
        system("cls");
        printf("Please enter the your password:                            1.back   2.exit\n");
        while(i != 1)
        {
            //inaja yek password az karbar gerefte mishavad
            scanf("%s", user_password);
            // va ba password karbar moghyese mishavad
            if(strcmp(user_password, temp->password) == 0)
            {
                //agar barabar bod az halghe kharej mishavad.
                i++;
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
    int i;
    // inja safe menu karmand namayesh dade mishavad.
    system("cls");
    printf("Staff");
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
    printf("Please Enter Your Choice:");
    scanf("%d", &i);
    if(i == 1)
    {
        New_member();
    }
    if(i == 2)
    {

    }
    if(i == 3)
    {

    }
    if(i == 4)
    {

    }
    if(i == 5)
    {
        New_book();
    }
    if(i == 6)
    {

    }
    if(i == 7)
    {

    }
    if(i == 8)
    {
        menu();
    }
}

void New_member(void)
{
    int i;
    struct member *start, *temp;
    FILE *fp;
    system("cls");
    fp = fopen("Member Profile.txt","a");
    start = malloc(sizeof(struct member));
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
    printf("2. Back\n");
    printf("Please Enter Your Choice:");
    scanf("%d", &i);
    if(i == 1)
    {
        New_member();
    }
    else
    {
        Staff_menu();
    }
}
void New_book(void)
{
    int i;
    struct book *start, *temp = NULL;
    FILE *fp;
    system("cls");
    fp = fopen("Book Profile.txt","a");
    start = malloc(sizeof(struct book));
    printf("Please enter the name's book:");
    scanf("%s",start->name);
    printf("\n");
    printf("Please enter the family name's publication:");
    scanf("%s",start->publication);
    printf("\n");
    printf("Please enter the name's author:");
    scanf("%s", start->author);
    printf("\n");
    printf("Please enter the year of publication:");
    scanf("%s",start->year);
    printf("\n");
    printf("the registration date:");
    date(start->date);
    puts(start->date);
    printf("\n");
    printf("the ID book: ");

    printf("Please enter the user name for employee:");
    puts(karmand);
    strcpy(start->username,karmand);
    printf("\n");
    printf("Please enter the genre's book:");
    scanf("%s",start->genre);
    fprintf(fp,"\n");
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
    fprintf(fp, "%d", start->id);
    fprintf(fp,"\n");
    fputs(start->username,fp);
    fprintf(fp,"\n");
    fputs(start->genre,fp);
    system("cls");
    printf("The operation was successful.");
    fclose(fp);
    Sleep(2000);
    printf("\n");
    printf("1. New book registration");
    printf("\n");
    printf("2. Back\n");
    printf("Please Enter Your Choice:");
    scanf("%d", &i);
    if(i == 1)
    {
        New_book();
    }
    else
    {
        Staff_menu();
    }
}
char ID_book(void)
{
    int i;
    struct book *start = NULL, *end = NULL, *temp = NULL;
    char line[100];
    FILE *fp;
    fp = fopen("Book Profile.txt", "r");
    while(feof == 0)
    {
        temp = malloc(sizeof(struct book));
        if(fgets(line, sizeof(line), fp) != NULL)
        {
            // ba estefade as strcspn \n ra peida va bejash \0 garar midahim.
            line[strcspn(line, "\n")] = '\0';
            strcpy(temp->name, line);
        }
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
    while(temp != NULL)
    {

    }
}
