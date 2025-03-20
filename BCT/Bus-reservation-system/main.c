#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TOTAL_SEATS 32


struct book {
    char customer_name[40];
    long int customer_phonenumber;
    int customer_age;
    int seat_number;
    char destination[30];
} bookings[100];

int seats[TOTAL_SEATS] = {0};
char seat_names[TOTAL_SEATS][40] = {0};
int booking_count = 0;

// Function prototypes
void book();
void detail();
void show_seat_availability();
void load_seat_data();
void save_seat_data();
int get_price(const char* destination);
void cancel_booking();




void load_seat_data() {
    FILE *file = fopen("travel.txt", "r");
    if (file == NULL) {
        printf("No previous bookings found.\n");
        return;
    }
    memset(seats, 0, sizeof(seats));
    memset(seat_names, 0, sizeof(seat_names));
    booking_count = 0;

    char line[256];
    // Read each line from the file.
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = 0;
        struct book temp;
        if (sscanf(line, "%39s %ld %d %d %29s", temp.customer_name,
                   &temp.customer_phonenumber,
                   &temp.customer_age,
                   &temp.seat_number,
                   temp.destination) == 5) {
            int seat_no = temp.seat_number;
            if (seat_no >= 1 && seat_no <= TOTAL_SEATS) {
                seats[seat_no - 1] = 1;  // Mark seat as booked.
                strcpy(seat_names[seat_no - 1], temp.customer_name);
            }
            bookings[booking_count++] = temp;
        }
    }
    fclose(file);
    printf("\n Loaded %d previous bookings from travel.txt\n", booking_count);
}
void save_seat_data()
 {
    FILE *file = fopen("travel.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    for (int i = 0; i < booking_count; i++) {
        fprintf(file, "%s %ld %d %d %s\n",
                bookings[i].customer_name,
                bookings[i].customer_phonenumber,
                bookings[i].customer_age,
                bookings[i].seat_number,
                bookings[i].destination);
    }
    fclose(file);
}

// Returns the fare for the given destination.
int get_price(const char* destination) {
    if (strcmp(destination, "Chitwan") == 0) return 700;
    if (strcmp(destination, "Fulchowk") == 0) return 1100;
    if (strcmp(destination, "Itahari") == 0) return 1500;
    if (strcmp(destination, "Kawasoti") == 0) return 475;
    if (strcmp(destination, "Dharan") == 0) return 1300;
    if (strcmp(destination, "Lahan") == 0) return 1100;
    return -1; // Invalid destination
}

// Displays bus details and fare information.
void detail()
 {
    printf("\n******* SAMYA SEWA YATAYAT - Bus Details *******\n");
    printf("Destinations and fares:\n");
    printf("1. Chitwan    - Rs 700\n");
    printf("2. Fulchowk  - Rs 1100\n");
    printf("3. Itahari    - Rs 1500\n");
    printf("4. Kawasoti   - Rs 475\n");
    printf("5. Dharan     - Rs 1300\n");
    printf("6. Lahan      - Rs 1100\n");
    printf("-------------------------------------------------\n");
}

// Displays seat availability along with the booked passenger's name.
void show_seat_availability() {
    printf("\n=======================================================\n");
    printf("|                  SEAT AVAILABILITY                 |\n");
    printf("=======================================================\n");
    printf("| Seat No |       Status       |   Passenger Name     |\n");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (seats[i] == 1) {
            printf("|   %2d    |    Booked         |  %-20s |\n", i + 1, seat_names[i]);
        } else {
            printf("|   %2d    |  Available        |  -                   |\n", i + 1);
        }
    }
    printf("-------------------------------------------------------\n");
}

// Books a new seat.
void book()
 {
    struct book new_booking;
    int seat_no;
    char destination[30];

    printf("Enter your phone number: ");
    if (scanf("%ld", &new_booking.customer_phonenumber) != 1) {
        printf("Invalid phone number!\n");
        return;
    }
    getchar(); // Consume newline

    printf("Enter your age: ");
    if (scanf("%d", &new_booking.customer_age) != 1 || new_booking.customer_age <= 0) {
        printf("Invalid age!\n");
        return;
    }
    getchar();
    printf("Enter your Name: ");
    fgets(new_booking.customer_name, sizeof(new_booking.customer_name),stdin);
    new_booking.customer_name[strcspn(new_booking.customer_name, "\n")] = 0;

    printf("Enter your destination: ");
    fgets(destination, sizeof(destination), stdin);
    destination[strcspn(destination, "\n")] = 0;

    int price = get_price(destination);
    if (price == -1) {
        printf("Invalid destination!\n");
        return;
    }

    printf("Enter seat number (1-32): ");
    if (scanf("%d", &seat_no) != 1 || seat_no < 1 || seat_no > TOTAL_SEATS || seats[seat_no - 1] == 1) {
        printf("Invalid or already booked seat! Choose another.\n");
        return;
    }
    seats[seat_no - 1] = 1;
    strcpy(seat_names[seat_no - 1], new_booking.customer_name);
    new_booking.seat_number = seat_no;
    strcpy(new_booking.destination, destination);
    bookings[booking_count++] = new_booking;

    save_seat_data();
    printf("\n Booking Successful! Data saved to 'travel.txt'\n");
}

// Cancels an existing booking.
void cancel_booking() {
    int seat_no;
    printf("Enter seat number to cancel booking: ");
    if (scanf("%d", &seat_no) != 1 || seat_no < 1 || seat_no > TOTAL_SEATS) {
        printf("Invalid seat number!\n");
        while(getchar() != '\n');
        return;
    }
    getchar(); // Consume newline

    // Check if the seat is booked.
    if (seats[seat_no - 1] == 0) {
        printf("Seat %d is not booked.\n", seat_no);
        return;
    }

    // Find and remove the booking from the bookings array.
    int found = 0;
    for (int i = 0; i < booking_count; i++) {
        if (bookings[i].seat_number == seat_no) {
            found = 1;
            // Shift remaining bookings left.
            for (int j = i; j < booking_count - 1; j++) {
                bookings[j] = bookings[j + 1];
            }
            booking_count--;
            break;
        }
    }
    if (!found) {
        printf("Booking for seat %d not found.\n", seat_no);
        return;
    }

    // Update seat availability.
    seats[seat_no - 1] = 0;
    memset(seat_names[seat_no - 1], 0, sizeof(seat_names[seat_no - 1]));

    save_seat_data();
    printf("Booking for seat %d has been cancelled.\n", seat_no);
}

int main()
 {
    // Load existing bookings from the file.
    load_seat_data();

    int choice;
    do {
        printf("\n******* HAMRO SEWA YATAYAT *******\n");
        printf("===========================================\n");
        printf("|   Option   |        Description         |\n");
        printf("===========================================\n");
        printf("|     1      | Check bus details & fare   |\n");
        printf("|     2      | Book your seat             |\n");
        printf("|     3      | View seat availability     |\n");
        printf("|     4      | Cancel a booking           |\n");
        printf("|     5      | Exit                       |\n");
        printf("===========================================\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');  // Clear input buffer
            continue;
        }
        getchar();  // Consume newline
        switch (choice) {
            case 1:
                detail();
                break;
            case 2:
                book();
                break;
            case 3:
                show_seat_availability();
                break;
            case 4:
                cancel_booking();
                break;
            case 5:
                save_seat_data();
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);
    return 0;
}
