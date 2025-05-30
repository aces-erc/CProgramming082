#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//==================== Structure and Global Variables ==================//
typedef struct score // to store score of player
{
    char game[20];
    char score[20];
    char played_at[100];
} Score;

typedef struct Users // player details
{
    char name[50];
    char username[50];
    char password[50];
} User;

char global_username[50], global_name[50]; // detail of logged in user

//==================== Game files =======================//
#include "./games/truth_or_dare.c"       // truth or dare game
#include "./games/tic_tac_toe.c"         // tic tac toe game
#include "./games/coin_flip.c"           // coin flip game
#include "./games/rock_paper_scissors.c" // rock paper scissors game

//==================== Function prototypes ===================//
void getCurrentDateTime(char *dateTimeString, int size);
void create_new_account(char *filename);
bool create_user(char *filename, char *name, char *username, char *password);
bool is_username_exists(char *filename, char *username);
bool is_user_exists(char *filename, char *username, char *password);
bool login(char *filename, char *global_username, char *global_name);
void get_user(char *username, char *name);
void game_menu(char *global_name, char *global_username);
void print_game_history(char *username);
void register_score(char *game, char *username, char *score);
int exit_game(char *msg, int code);

//==================== Main Function ===================//
int main()
{

    while (true)  // infinite loop to show welcome screen again and again until user exits
    {

        // Variables
        int choice;
        // Welcome Screen
        system("cls");
        printf("==========================================\n");
        printf("%-40s", "|| Welcome to C Games");
        printf("||\n");
        printf("==========================================\n");
        printf("%-40s", "||   1. Create a new Account");
        printf("||\n");
        printf("%-40s", "||   2. Login");
        printf("||\n");
        printf("%-40s", "||   0. Exit");
        printf("||\n");
        printf("==========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch case to handle user choice
        switch (choice)
        {
        case 1:
            system("cls");
            create_new_account("./db/users.bin"); // function calling to  create user account and save its details
            break;
        case 2:
            system("cls");
            login("./db/users.bin", global_username, global_name);
            break;
        case 0:
            system("cls");
            exit_game("Thanks for playing C Games.", 0);
            break;
        default:
            system("cls");
            printf("Invalid choice");
            break;
        }
    }
    return 0;
}

//==================== Auth functions ===================//
/*
    *function title: create_new_account
    arguments: filename in which user details are stored
    returns: null
    working mechanism: takes user details as input and creates a new account by calling create_user function
        and checks if the username already exists by calling is_username_exists function ->
        if username already exists then it shows error message else it creates a new account
*/
void create_new_account(char *filename)
{
    char name[50], username[50], password[50];
    User all_user[100];
    printf("Name: ");
    scanf(" %[^\n]", name); // to take input with spaces
    name[0] = toupper(name[0]);
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    // Create new account
    system("cls");
    printf("==========================================\n");
    if (create_user(filename, name, username, password))
    {

        printf("%-40s", "||   Account created successfully");
        printf("||\n");
    }
    else
    {
        printf("%-40s", "||   Account creation failed.");
        printf("||\n");
        printf("%-40s", "||   Username already exists.");
        printf("||\n");
    }
    printf("==========================================\n");
    printf("Press any key to continue...");
    getch();
    system("cls");
    return;
}

/*
    *function title: create_user
    arguments: filename in which user details are stored, name, username, password of the user
    returns: true if account is created successfully else false
    working mechanism: creates a new user and stores it in the file
*/
bool create_user(char *filename, char *name, char *username, char *password)
{
    FILE *fptr;
    User new_user;
    fptr = fopen(filename, "ab");
    if (fptr == NULL)
    {
        return false;
    }
    strcpy(new_user.name, name);
    strcpy(new_user.username, username);
    strcpy(new_user.password, password);
    if (is_username_exists(filename, username) == 1)
    {
        fclose(fptr);
        return false;
    }
    else
    {
        fwrite(&new_user, sizeof(User), 1, fptr);
        fclose(fptr);
        return true;
    }
}

/*
    *function title: is_username_exists
    arguments: filename in which user details are stored, username of the user
    returns: true if username exists else false
    working mechanism: checks if the username exists in the file by comparing it with all the usernames in the file
*/
bool is_username_exists(char *filename, char *username)
{
    FILE *fptr;
    User temp_user;
    fptr = fopen(filename, "rb");
    while (fread(&temp_user, sizeof(User), 1, fptr) == 1)
    {
        if (strcmp(temp_user.username, username) == 0)
        {
            fclose(fptr);
            return true;
        }
    }
    fclose(fptr);
    return false;
}

/*
    *function title: login
    arguments: filename in which user details are stored, username and password of the user
    returns: true if username and password matches else false
    working mechanism: checks if the username and password matches
    with the username and password in the file by comparing it
    with all the usernames and passwords in the file
*/
bool login(char *filename, char *global_username, char *global_name)
{
    // Variables
    char username[50], password[50];

    system("cls");
    // Input username and password
    printf("\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    // Compare username and password
    if (is_user_exists(filename, username, password))
    {

        system("cls");
        printf("==========================================\n");
        printf("%-40s", "||   Login Successful");
        printf("||\n");
        printf("==========================================\n");
        // get user details
        strcpy(global_username, username);
        get_user(global_username, global_name);
        printf("Press any key to continue...");
        getch();
        system("cls");
        game_menu(global_name, global_username);
        return true;
    }
    else
    {
        system("cls");
        printf("==========================================\n");
        printf("%-40s", "||   Login Failed");
        printf("||\n");
        printf("%-40s", "||   Invalid username or password");
        printf("||\n");
        printf("==========================================\n");
        printf("Press any key to continue...");
        getch();
        system("cls");
        return false;
    }
}

/*
    *function title: is_user_exists
    arguments: filename in which user details are stored, username and password of the user
    returns: true if username and password matches else false
    working mechanism: checks if the username and password matches
        with the username and password in the file by comparing it
        with all the usernames and passwords in the file
*/
bool is_user_exists(char *filename, char *username, char *password)
{
    FILE *fptr;
    User temp_user;
    fptr = fopen(filename, "rb");
    while (fread(&temp_user, sizeof(User), 1, fptr) == 1)
    {
        if (strcmp(temp_user.username, username) == 0 && strcmp(temp_user.password, password) == 0)
        {
            fclose(fptr);
            return true;
        }
    }
    fclose(fptr);
    return false;
}

/*
    *function title: get_user
    arguments: username of the user, variable to store the name of the user
    returns: void
    working mechanism: gets the name of the user from the file and stores it in the variable called name
*/
void get_user(char *username, char *name)
{
    FILE *fptr;
    User temp_user;
    fptr = fopen("./db/users.bin", "rb");
    while (fread(&temp_user, sizeof(User), 1, fptr) == 1)
    {
        if (strcmp(temp_user.username, username) == 0)
        {
            strcpy(name, temp_user.name);
            break;
        }
    }
    fclose(fptr);
    return;
}

//==================== Game Functions ===================
/*
    *function title: game_menu
    arguments: name and username of the user
    returns: void
    working mechanism: displays the game menu
*/
void game_menu(char *global_name, char *global_username)
{
    // Variables
    int choice;

    // Menu
    system("cls");
    printf("=========================================\n");
    printf("|| Welcome ");
    printf("%-29s", global_name);
    printf("||\n");
    printf("%-40s", "|| Choose a Game:");
    printf("||\n");
    printf("=========================================\n");
    printf("%-40s", "||   1. Tic Tac Toe");
    printf("||\n");
    printf("%-40s", "||   2. Truth or Dare");
    printf("||\n");
    printf("%-40s", "||   3. Rock Paper Scissor ");
    printf("||\n");
    printf("%-40s", "||   4. Coin Flip ");
    printf("||\n");
    printf("=========================================\n");
    printf("%-40s", "||   5. Game History");
    printf("||\n");
    printf("%-40s", "||   6. Logout");
    printf("||\n");
    printf("%-40s", "||   0. Exit");
    printf("||\n");
    printf("=========================================\n");

    // Input choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Switch case
    switch (choice)
    {
    case 1: // tic tac toe
        system("cls");
        tic_tac_toe(global_name, global_username);
        printf("Press any key to continue...");
        getch();
        system("cls");
        game_menu(global_name, global_username);
        break;
    case 2: // truth or dare
        system("cls");
        truth_or_dare(global_name, global_username);
        game_menu(global_name, global_username);
        break;
    case 3: // rock paper scissor
        system("cls");
        rock_paper_scissor(global_name, global_username);
        game_menu(global_name, global_username);
        break;
    case 4: // coin flip
        system("cls");
        coin_flip(global_name, global_username);
        game_menu(global_name, global_username);
        break;
    case 5: // game history
        system("cls");
        print_game_history(global_username);
        printf("\nPress any key to continue...");
        getch();
        system("cls");
        game_menu(global_name, global_username);
        break;
    case 6: // logout
        system("cls");
        main();
        break;
    case 0: // exit
        system("cls");
        exit_game("Thanks for playing C Games.", 0);
        break;
    default:
        system("cls");
        printf("Invalid choice");
        break;
    }
    return;
}

/*
        *function title: print_game_history
        arguments: username of the user
        returns: void
        working mechanism: prints the game history of the user
*/
void print_game_history(char *username)
{
    FILE *fptr;
    // Score temp_score;
    Score temp_score[100];
    int i = 0;
    char file_name[100];
    sprintf(file_name, "./db/game_history/%s.bin", username);
    fptr = fopen(file_name, "rb"); // opens file path
    if (fptr == NULL)
    {
        printf("No game history found\n");
    }
    else
    {
        while (fread(&temp_score[i], sizeof(Score), 1, fptr) == 1)
        {
            i++;
        }
        printf("Game\t\t\tScore\t\tDate\n\n");
        // print the game history in reverse order
        for (int j = i - 1; j >= 0; j--)
        {
            printf("%-18s\t%s\t\t%s\n", temp_score[j].game, temp_score[j].score, temp_score[j].played_at);
        }
    }
    fclose(fptr);
    return;
}

/*
    *function title: register_score
    arguments: game name, username of the user, score of the user
    returns: void
    working mechanism: registers the score of the user in the game history folder in the file named as username.bin
*/
void register_score(char *game, char *username, char *score)
{
    FILE *fptr;
    Score new_score;
    char dateTimeString[100];
    getCurrentDateTime(dateTimeString, sizeof(dateTimeString));
    char file_name[100];
    sprintf(file_name, "./db/game_history/%s.bin", username);
    fptr = fopen(file_name, "ab");
    if (fptr == NULL)
    {
        return;
    }
    strcpy(new_score.game, game);
    strcpy(new_score.score, score);
    strcpy(new_score.played_at, dateTimeString);
    fwrite(&new_score, sizeof(Score), 1, fptr);
    fclose(fptr);
    return;
}

/*
    *function title: exit_game
    arguments: message to be displayed, exit code
    returns: void
    working mechanism: displays the message and exits the program
*/
int exit_game(char *msg, int code)
{
    printf("==========================================\n");
    printf("||   ");
    printf("%-36s", msg);
    printf("||\n");
    printf("==========================================\n\n\n\n");
    exit(code);
}

/*
    *function title: getCurrentDateTime
    arguments: char array to store the date and time, size of the array
    returns: void
    working mechanism: gets the current date and time and stores it in the char array
*/
void getCurrentDateTime(char *dateTimeString, int size)
{
    // Declare variables to hold time information
    time_t currentTime;         // Represents the current time as seconds since the epoch
    struct tm *localTime;       // Pointer to a structure holding local time components

    // Get the current time
    currentTime = time(NULL);   // Retrieve the current time in seconds since the epoch

    // Convert the current time to local time
    localTime = localtime(&currentTime); // Convert the epoch time to local time components

    // Format the date and time using strftime
    strftime(dateTimeString, size, "%B %d, %Y %H:%M:%S", localTime);
    // The strftime function formats the local time components and stores the result in dateTimeString
    // %B: Full month name, %d: Day of the month (01-31), %Y: Full year, %H: Hour (00-23), %M: Minute (00-59), %S: Second (00-59)
}
