# Bus Reservation System

https://github.com/acidicsameer/memo

## Team Name:
The memo
## Team Members and Contributions:
- **Sameer Sapkota**: 
  - Developed the core functionality of the system.
  - Implemented the **booking** function, **save seat data** function, and other essential components inside the **main function**.
  - Ensured the logic for booking, seat status, and fare calculation works seamlessly.
  
- **Shailesh Chaudhary**: 
  - Focused on the **seat availability** function.
  - Implemented the logic to display available seats and show passenger names for the booked seats.

- **Sushant Thapa**: 
  - Developed the **cancel booking** function.
  - Worked on removing bookings from the system and updating the seat availability after cancellation.

- **Manish Pandey**: 
  - Worked on the **load seat data** function.
  - Developed the logic to load previous booking data from a file (`travel.txt`) and populate the seating chart with existing bookings.

## Platform Used:
Windows

## How to Run/Use:

### Prerequisites:
- **A C compiler (e.g., GCC) installed on your system.**

### Steps to Run:
1. **Clone the Repository**  
   Download the project files to your local machine by cloning the repository.
   
2. **Open the Project in Your IDE**  
   Open the project folder in your preferred C development environment (e.g., Code::Blocks, Dev-C++, Visual Studio, etc.).

3. **Compile the Code**  
   Compile the 'bus_reservation.c' file using the C compiler in your IDE. The IDE should have a "Build" or "Compile" option in the menu.

4. **Run the Program**  
   After compilation, click the "Run" or "Execute" button in your IDE to start the program.

5. **Follow the On-Screen Instructions**  
   Once the program is running, you will be presented with a menu. Choose an option by entering the corresponding number:
   
   - Option 1: **Check bus details and fare**  
   - Option 2: **Book a seat**  
   - Option 3: **View seat availability**  
   - Option 4: **Cancel a booking**  
   - Option 5: **Exit the program**  
   
   Enter the requested information, such as your name, age, phone number, destination, and seat number to complete the process.

6. **View the Data**  
   All booking information is saved in a file called `travel.txt`. This file is automatically updated whenever you make a booking or cancel one.

### About the Project:
This project is a simple bus reservation system that allows users to:

1. **View bus details and fare information** for various destinations.
2. **Book a seat** by entering personal details (name, age, phone number, destination, and seat number).
3. **Check seat availability** and view the passenger names for booked seats.
4. **Cancel an existing booking** by providing the seat number.
5. The system saves the booking information in a text file (`travel.txt`) so that bookings are persistent across program runs.
