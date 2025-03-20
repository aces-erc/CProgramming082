#include<stdio.h>


int main()
{
    int user_menu() {
        int choice;
        printf("1. Enter new health data\n");
        printf("2. Display previous health data\n");
        printf("3. Need Consultation?\n");
        printf("Choose the option: ");
        scanf("%d", &choice);
        return choice;
    }
    return 0;
}