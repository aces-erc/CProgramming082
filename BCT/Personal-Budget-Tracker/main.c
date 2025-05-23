#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 50
#define DESCRIPTION_LENGTH 100

struct expense {
    char description[DESCRIPTION_LENGTH];
    int amount;
};

struct budget {
    int year;
    int month;
    int income;
    char incomeDescription[DESCRIPTION_LENGTH];
    int totalAmount;
    int saving;
    int numExpenses;
    struct expense expenses[MAX_EXPENSES];
};

void clearInputBuffer() {
    while (getchar() != '\n'); 
}

int getValidInteger(int min, int max) {
    int value;
    while (1) {
        if (scanf("%d", &value) != 1 || value < min || value > max) {
            printf("Invalid input. Please enter a number between %d and %d: ", min, max);
            clearInputBuffer();
        } else {
            clearInputBuffer(); 
            return value;
        }
    }
}

void addExpense() {
    struct budget b = {0}; 
    char next;

    FILE *fp = fopen("personal.dat", "a");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    printf("\nEnter expense details:\n");
    printf("Enter year: ");
    b.year = getValidInteger(2000, 2100); 
    printf("Enter month (1-12): ");
    b.month = getValidInteger(1, 12);
    printf("Enter income description: ");
    scanf(" %[^\n]", b.incomeDescription);
    printf("Enter income: ");
    b.income = getValidInteger(0, 1000000); 

    do {
        if (b.numExpenses >= MAX_EXPENSES) {
            printf("Maximum number of expenses reached!\n");
            break;
        }

        printf("Enter expense description: ");
        scanf(" %[^\n]", b.expenses[b.numExpenses].description);
        printf("Enter expense amount: ");
        b.expenses[b.numExpenses].amount = getValidInteger(0, 1000000); 

        b.totalAmount += b.expenses[b.numExpenses].amount;
        b.numExpenses++;
        printf("Press 'y' to add more expenses or any other key to stop: ");
        scanf(" %c", &next);
    } while (next == 'y');

    b.saving = b.income - b.totalAmount;

    fwrite(&b, sizeof(struct budget), 1, fp);
    fclose(fp);

    printf("Expenses added successfully!\n");
}

void reviewBudget(const struct budget *b) {
    if (b->saving > 0) {
        printf("\nReview: You are in gain! Savings: %d\n", b->saving);
    } else if (b->saving < 0) {
        printf("\nReview: You are in loss! Loss: %d\n", -b->saving);
    } else {
        printf("\nReview: You have a break-even budget. No gain or loss.\n");
    }
}

void displayBudget(const struct budget *b) {
    printf("\nYear: %d", b->year);
    printf("\nMonth: %d", b->month);
    printf("\nIncome Description: %s", b->incomeDescription);
    printf("\nIncome: %d", b->income);
    printf("\n--- Expenses Breakdown ---\n");
    for (int i = 0; i < b->numExpenses; i++) {
        printf("%d. %s - %d\n", i + 1, b->expenses[i].description, b->expenses[i].amount);
    }
    printf("------------------------------\n");
    printf("\nTotal Expense: %d", b->totalAmount);
    printf("\nSaving: %d\n", b->saving);
    reviewBudget(b);
}

void viewExpenses() {
    FILE *fp = fopen("personal.dat", "r");
    struct budget b;

    if (fp == NULL) {
        printf("No expenses recorded yet!\n");
        return;
    }

    printf("\n----- Expense Records -----\n");
    while (fread(&b, sizeof(struct budget), 1, fp)) {
        displayBudget(&b);
    }

    fclose(fp);
}

void searchExpenses() {
    int choice;
    FILE *fp = fopen("personal.dat", "r");
    struct budget b;

    if (fp == NULL) {
        printf("No expenses recorded yet!\n");
        return;
    }

    printf("\nEnter search criteria:\n");
    printf("1. Search by Year\n");
    printf("2. Search by Month\n");
    printf("3. Search by Year & Month\n");
    printf("Enter choice (1-3): ");
    choice = getValidInteger(1, 3);

    int year, month;
    switch (choice) {
        case 1:
            printf("Enter the year you want to search: ");
            year = getValidInteger(2000, 2100);
            break;
        case 2:
            printf("Enter the month you want to search: ");
            month = getValidInteger(1, 12);
            break;
        case 3:
            printf("Enter the year and month you want to search: ");
            year = getValidInteger(2000, 2100);
            month = getValidInteger(1, 12);
            break;
    }

    while (fread(&b, sizeof(struct budget), 1, fp)) {
        int match = 0;
        if (choice == 1 && b.year == year) match = 1;
        if (choice == 2 && b.month == month) match = 1;
        if (choice == 3 && b.year == year && b.month == month) match = 1;

        if (match) {
            displayBudget(&b);
        }
    }

    fclose(fp);
}

void modifyExpense() {
    int year, month, found = 0;
    struct budget b;
    FILE *fp = fopen("personal.dat", "r");
    FILE *temp = fopen("temp.dat", "w");

    if (fp == NULL || temp == NULL) {
        perror("Error opening file");
        return;
    }

    printf("Enter the year of the record to modify: ");
    year = getValidInteger(2000, 2100);
    printf("Enter the month of the record to modify: ");
    month = getValidInteger(1, 12);

    while (fread(&b, sizeof(struct budget), 1, fp)) {
        if (b.year == year && b.month == month) {
            found = 1;
            printf("\nCurrent Record:\n");
            displayBudget(&b);

            printf("Modify income? (1-Yes, 0-No): ");
            int modifyIncome;
            scanf("%d", &modifyIncome);
            if (modifyIncome) {
                printf("Enter new income: ");
                b.income = getValidInteger(0, 1000000);
            }

            printf("Modify expenses? (1-Yes, 0-No): ");
            int modifyExpense;
            scanf("%d", &modifyExpense);
            if (modifyExpense) {
                b.totalAmount = 0;
                b.numExpenses = 0;
                char next;
                do {
                    if (b.numExpenses >= MAX_EXPENSES) {
                        printf("Maximum number of expenses reached!\n");
                        break;
                    }
                    printf("Enter expense description: ");
                    scanf(" %[^\n]", b.expenses[b.numExpenses].description);
                    printf("Enter expense amount: ");
                    b.expenses[b.numExpenses].amount = getValidInteger(0, 1000000);
                    b.totalAmount += b.expenses[b.numExpenses].amount;
                    b.numExpenses++;
                    printf("Press 'y' to add more expenses or any other key to stop: ");
                    scanf(" %c", &next);
                } while (next == 'y');
            }

            b.saving = b.income - b.totalAmount;
            fwrite(&b, sizeof(struct budget), 1, temp);
            printf("Record modified successfully!\n");
        } else {
            fwrite(&b, sizeof(struct budget), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);
    remove("personal.dat");
    rename("temp.dat", "personal.dat");
    if (!found) {
        printf("No record found for %d/%d!\n", month, year);
    }
}

void deleteExpense() {
    int choice;
    FILE *fp = fopen("personal.dat", "r");
    FILE *temp = fopen("temp.dat", "w");
    struct budget b;

    if (fp == NULL || temp == NULL) {
        perror("Error opening file");
        return;
    }

    printf("Enter the delete criteria\n");
    printf("1. Delete by year\n");
    printf("2. Delete by both year and month\n");
    printf("Enter your choice: ");
    choice = getValidInteger(1, 2);

    int year, month, found = 0;
    switch (choice) {
        case 1:
            printf("Enter the year you want to delete: ");
            year = getValidInteger(2000, 2100);
            while (fread(&b, sizeof(struct budget), 1, fp)) {
                if (b.year == year) {
                    found = 1;
                    printf("Record for %d deleted successfully!\n", year);
                } else {
                    fwrite(&b, sizeof(struct budget), 1, temp);
                }
            }
            break;
        case 2:
            printf("Enter the year of the record to delete: ");
            year = getValidInteger(2000, 2100);
            printf("Enter the month of the record to delete: ");
            month = getValidInteger(1, 12);
            while (fread(&b, sizeof(struct budget), 1, fp)) {
                if (b.year == year && b.month == month) {
                    found = 1;
                    printf("Record for %d/%d deleted successfully!\n", month, year);
                } else {
                    fwrite(&b, sizeof(struct budget), 1, temp);
                }
            }
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    fclose(fp);
    fclose(temp);
    remove("personal.dat");
    rename("temp.dat", "personal.dat");
    if (!found) {
        printf("No record found for the specified criteria!\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nPersonal Budget Tracker Menu\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Search expenses\n");
        printf("4. Modify expenses\n");
        printf("5. Delete expenses\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        choice = getValidInteger(1, 6);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                searchExpenses();
                break;
            case 4:
                modifyExpense();
                break;
            case 5:
                deleteExpense();
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
return 0;
}