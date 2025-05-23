# Personal-Budget-Tracker

## C -Programming Final Project
This project was developed as a part of the ACES C-Project Demonstration by the following team members:
 - Carol Lama(@Carollama)
- Chomina Poudel(@chominap12)
- Nikky Singh(@Nikkysingh16)
- Nandani Mahato(@Nandani324)

 ##### Project Description
 This project is a simple Personal Budget Tracker that helps users to :
 - Manage their finances by tracking income and expenses.
 - Input transaction, categorized them, and displays summaries like total income,expenses ,and savings.
 - Monitor where your money is coming from and where it is going,helping you to make informed decision about your financial conditions.

##### Key Features
1. Expense Management
- Add Expenses: Users can enter year, month, income details, and multiple expenses.
- Modify Expenses: Allows editing income and expense details for a given month and year.
- Delete Expenses: Users can delete records by year or by both year and month.
2. File-Based Storage
- Data is stored in a file (personal.dat) using binary file handling.
- Ensures data persistence even after the program is closed.
3. Data Validation & Error Handling
- Input Validation: Ensures numeric inputs fall within acceptable ranges (e.g., year between 2000 and 2100, month between 1 and 12).
- Buffer Clearing: Prevents input errors by handling newline characters correctly.
- Error Handling: Displays appropriate error messages if file operations fail.
4. Budget Calculation & Review
- Automatically calculates total expenses and savings.
 Provides a review summary:
- Profit (Savings > 0) → "You are in gain!"
- Loss (Savings < 0) → "You are in loss!"
- Break-even (Savings = 0) → "No gain or loss."
5. Search Functionality
Users can search expense records based on:
- Year
- Month
- Year & Month (combined)
6. User-Friendly Interface
- Menu-driven system with numbered options for easy navigation.
- Prompts users for confirmation before making major changes (e.g., modifying/deleting records).
7. Structured Data Handling
Uses struct budget to organize financial records, including:
- Year, Month
-Income & Description
- List of Expenses
- Total Expenses & Savings
8. Efficient File Operations
- Appending Data (fopen("a")) ensures new expenses are added without overwriting previous ones.
- Reading & Searching (fopen("r")) allows efficient retrieval of records.
- Modifying & Deleting (fopen("w") with temporary files) ensures records are updated correctly.
9. Loop for Continuous Operation
- Runs in a loop until the user chooses to exit (case 6).
- Prevents accidental exits by asking for confirmation before closing.

  ## Instruction to Run the project

  #### 1 . Running the project in VS Code
 - Open Terminal in VS Code (Ctrl + ~)

- Compile the project using:

  gcc main.c -o main.exe 

- And run the program using:
./main.exe
 
    
