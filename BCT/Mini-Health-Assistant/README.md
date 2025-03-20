 ### **MINI HEALTH ASSISTANT**

 https://github.com/sudipmahato11/Mini-Health-Assistant

### **TEAM TECH TITANS**

### **C-Programming Final Project**

### **This project is developed as part of the BCT 2081 course by the following team members:**
  - **Sudip Mahato** (PUR081BCT087)  
  - **Samundra Pariyar** (PUR081BCT071)  
  - **Rupak Subba** (PUR081BCT063)  
  - **Sayesh Dhakal** (PUR081BCT080)  

### **Stepwise Process to Run and Use the Medical Diagnosis Program**  

#### **1. Compile and Run the Program**  
- Open a C compiler (e.g., GCC, Code::Blocks, or Dev-C++).  
- Save the program as `medical_diagnosis.c`.  
- Compile using the command:  
  ```
  gcc medical_diagnosis.c -o medical_diagnosis
  ```
- Run the program:  
  ```
  ./medical_diagnosis
  ```

#### **2. Choose an Option from the Menu**  
- The program will display:  
  ```
  1. Enter new health data  
  2. Display previous health data  
  3. Need Consultation?  
  Choose the option:
  ```
- Enter the number corresponding to your choice.

#### **3. If You Choose Diagnosis (Option 1)**  

#### ** Enter the Current Date**  
- The program will prompt:  
  ```
  Enter today's date:
  ```
- Type the date (e.g., `11-03-2025`) and press **Enter**.
- 
- The system displays symptom categories (Fever, Stomach Ache, High/Low Blood Pressure, Diabetes).  
- Select a category by entering the corresponding letter (e.g., `a` for Fever).  
- The program provides a diagnosis with health instructions.  
- It asks:  
  ```
  Do you want some medicine prescription? (y/n)
  ```
- Enter `y` for medicine recommendations or `n` to exit.

#### **4. If You Choose to View Past Health Data (Option 2)**  
- The program retrieves and displays the last recorded health data from `medical_report.txt`.

#### **5. If You Choose Doctor Consultation (Option 3)**  
- The system lists available doctors along with their experience, contact details, and hospitals.

#### **7. Exit the Program**  
- The program will terminate after displaying the requested information.  
- To restart, rerun the executable file (`./medical_diagnosis`). 


### **ABOUT THE PROGRAM**

### **Key Features**
1. **Symptom-Based Diagnosis:**
   - The program asks the user about symptoms and suggests possible diagnoses, such as:
     - Fever
     - Stomach Ache
     - High Blood Pressure (HBP)
     - Low Blood Pressure (LBP)
     - Diabetes

2. **Health Instructions & Medicine Prescription:**
   - After diagnosing a condition, the program provides general health instructions.
   - Users can choose whether they want medicine recommendations.

3. **Medical Report Storage:**
   - The program stores the user’s health data in a file (`medical_report.txt`).
   - It allows retrieving past health data.

4. **Doctor Consultation:**
   - Displays a list of doctors, their experience, contact details, and hospital names.
   - This is handled using a `struct` to store doctor details.

5. **User Menu Options:**
   - **Option 1:** Enter new health data (diagnosis and prescriptions).
   - **Option 2:** Display previous health data from the file.
   - **Option 3:** View details of available doctors.


### **PROJECT CONTRIBUTIONS**  

- **Sudip Mahato** (PUR081BCT087)  
  - Implemented file handling to store previous reports  
  - Merged and executed all components for the final version  

- **Samundra Pariyar** (PUR081BCT071)  
  - Developed the structure to display the doctors' list  
  - Contributed project ideas  

- **Rupak Subba** (PUR081BCT063)  
  - Created user-defined functions for disease specification  
  - Designed the user menu  

- **Sayesh Dhakal** (PUR081BCT080)  
  - Developed user-defined functions for diagnosis  
  - Worked on project design  

