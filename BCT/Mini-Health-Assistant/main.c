#include <stdio.h>
#include <string.h>
#include<stdlib.h>


void Fever() {
    printf("\t\t\t\t\tYOU ARE DIAGNOSED FOR FEVER\n\n");
    printf("\nInstructions:\n");
    printf("1. Stay hydrated by drinking plenty of fluids.\n");
    printf("2. Get adequate rest and sleep.\n");
    printf("3. Eat a balanced diet to boost your immune system.\n");
    printf("4. Keep your surroundings clean and well-ventilated.\n");
    printf("5. Seek medical attention if fever persists for more than a few days.\n");

    printf("Do you want some medecine prescription?\n");
    printf("y/n:");
    char fo;
    scanf(" %c", &fo);  
    if (fo == 'y') {
        printf("Prescribed Medications:\n");
        printf("1. Paracetamol 500mg - Take 1 tablet every 4-6 hours as needed for fever (max 4 doses per day).\n");
        printf("2. Ibuprofen 400mg - Take 1 tablet every 6-8 hours for body pain (max 3 doses per day).\n");
    } else {
        printf("Thank you for visiting us.\n");
        exit(0);
    }
}

void Stomach_Ache() {
    printf("\t\t\t\t\tYOU ARE DIAGNOSED FOR STOMACH ACHE\n\n");
    printf("\nInstructions:\n");
    printf("1. Eat fresh, well-cooked, and hygienic food.\n");
    printf("2. Avoid spicy, oily, and junk food.\n");
    printf("3. Stay hydrated by drinking enough water.\n");
    printf("4. Eat at regular intervals and avoid overeating.\n");
    printf("5. Exercise regularly to maintain a healthy digestive system.\n");

    printf("Do you want some medecine prescription?\n");
    printf("y/n:");
    char so;
    scanf(" %c", &so);  
    if (so == 'y') {
        printf("Prescribed Medications:\n");
        printf("1. Antacid (e.g., Tums or Rolaids) - Take 1 tablet every 4-6 hours as needed for relief.\n");
        printf("2. Domperidone 10mg - Take 1 tablet 30 minutes before meals for nausea or indigestion.\n");
        printf("3. Buscopan 10mg - Take 1 tablet every 8 hours for abdominal cramping or spasms.\n");
    } else {
        printf("Thank you for visiting us.\n");
        exit(0);
    }
}

void HBloodPressure()
{
    printf("\t\t\t\t\tYOU ARE DIAGNOSED FOR HIGH BP\n\n");
    printf("\nInstructions:\n");
    printf("1. Follow a balanced diet rich in fruits, vegetables, and whole grains.\n");
    printf("2. Reduce salt intake and avoid processed foods.\n");
    printf("3. Exercise regularly, at least 30 minutes a day.\n");
    printf("4. Limit alcohol consumption.\n");
    printf("5. Monitor your blood pressure regularly.\n");
    printf("6. Follow your doctor's recommendations, including prescribed medication.\n");

    printf("Do you want some medecine prescription?\n");
    printf("y/n:");
    char ho;
    scanf(" %c", &ho);
    if (ho == 'y')
    {
        printf("Prescribed Medications:\n");
        printf("1. Lisinopril 10mg - Take 1 tablet daily in the morning.\n");
        printf("2. Amlodipine 5mg - Take 1 tablet daily in the evening.\n");
        printf("3. Hydrochlorothiazide 25mg - Take 1 tablet daily in the morning.\n");
    }
    else
    {
        printf("Thankyou for visiting us.");
    }
}
void LBloodPressure()
{
    printf("\t\t\t\t\tYOU ARE DIAGNOSED FOR LOW BP\n\n");
    printf("\nInstructions:\n");
    printf("1. Increase your salt intake.\n");
    printf("2. Drink plenty of fluids, especially water.\n");
    printf("3. Avoid alcohol, which can lower blood pressure further.\n");
    printf("4. Monitor blood pressure regularly to detect any drastic changes.\n");
    printf("5. Take medications as prescribed by a healthcare professional.\n");

    printf("Do you want some medecine prescription?\n");
    printf("y/n:");
    char lo;
    scanf(" %c", &lo);
    if (lo == 'y')
    {
        printf("Prescribed Medications:\n");
        printf("1. Fludrocortisone 0.1mg - Take 1 tablet daily in the morning.\n");
        printf("2. Midodrine 2.5mg - Take 1 tablet 2-3 times daily as directed.\n");
    }
    else
    {
        printf("Thankyou for visiting us.");
    }
}


void Diabetes()
{
    printf("\t\t\t\t\tYOU ARE DIAGNOSED FOR DIABETES\n\n");
    printf("\nInstructions:\n");
    printf("1. Eat foods high in fiber, such as fruits, vegetables, and whole grains.\n");
    printf("2. Limit sugary foods and drinks, and avoid excessive consumption of processed carbs.\n");
    printf("3. Avoid smoking, as it increases the risk of diabetes complications.\n");
    printf("4. Consult a healthcare provider regularly for check-ups and advice on managing risk factors.\n");

    printf("Do you want some medecine prescription?\n");
    printf("y/n:");
    char co;
    scanf(" %c", &co);
    if (co == 'y')
    {
        printf("Prescribed Medications:\n");
        printf("1. Metformin 500mg - Take 1 tablet twice a day with meals.\n");
        printf("2. Glibenclamide 5mg - Take 1 tablet daily before breakfast.\n");
        printf("3. Insulin (e.g., Novolog) - Follow insulin regimen as instructed by healthcare provider.\n");
    }
    else
    {
        printf("Thankyou for visiting us.");
    }
}
char Diagnosis() {
    char disease;
    printf("What are the primary symptoms?\n");
    // Fever Symptoms
    printf("\n(a)Fever Symptoms:\n");
    printf("1. Elevated body temperature.\n");
    printf("2. Sweating or chills.\n");
    printf("3. Headache.\n");
    printf("4. Muscle aches.\n");
    printf("5. Fatigue or weakness.\n");
    printf("6. Loss of appetite.\n");
    printf("7. Dehydration.\n");

    // Stomach Ache Symptoms
    printf("\n(b)Stomach Ache Symptoms:\n");
    printf("1. Abdominal pain or cramping.\n");
    printf("2. Nausea or vomiting.\n");
    printf("3. Bloating.\n");
    printf("4. Diarrhea or constipation.\n");
    printf("5. Indigestion or heartburn.\n");
    printf("6. Loss of appetite.\n");

    // High Blood Pressure (HBP) Symptoms
    printf("\n(c)High Blood Pressure (HBP) Symptoms:\n");
    printf("1. Headaches (especially in the morning).\n");
    printf("2. Dizziness or lightheadedness.\n");
    printf("3. Shortness of breath.\n");
    printf("4. Chest pain.\n");
    printf("5. Fatigue or confusion.\n");
    printf("6. Vision problems.\n");
    printf("7. Nosebleeds.\n");

    // Low Blood Pressure (LBP) Symptoms
    printf("\n(d)Low Blood Pressure (LBP) Symptoms:\n");
    printf("1. Dizziness or lightheadedness.\n");
    printf("2. Fainting.\n");
    printf("3. Blurry vision.\n");
    printf("4. Fatigue.\n");
    printf("5. Nausea.\n");
    printf("6. Rapid, shallow breathing.\n");

    // Diabetes Symptoms
    printf("\n(e)Diabetes Symptoms:\n");
    printf("1. Frequent urination.\n");
    printf("2. Excessive thirst (polydipsia).\n");
    printf("3. Increased hunger (polyphagia).\n");
    printf("4. Fatigue.\n");
    printf("5. Blurred vision.\n");
    printf("6. Slow-healing wounds.\n");
    printf("7. Unexplained weight loss.\n");
    printf("8. Tingling or numbness in hands or feet.\n");

    printf("\n\n");
    printf("Choose for your related symptoms: ");
    scanf(" %c", &disease);  
    return disease;
}

int user_menu() {
    int choice;
    printf("1. Enter new health data\n");
    printf("2. Display previous health data\n");
    printf("3. Need Consultation?\n");
    printf("Choose the option: ");
    scanf("%d", &choice);
    return choice;
}

void Drpresent() {
    struct doctor {
        char Name[20];
        int Experience;
        long int Contact;
        char Hospital[50]; 
    };

    struct doctor d1, d2, d3, d4;

    // Enter data for d1
    strcpy(d1.Name, "Dr. Ram Bahadur");
    d1.Experience = 10;
    d1.Contact = 985112233;
    strcpy(d1.Hospital, "Shree Hospital");

    // Enter data for d2
    strcpy(d2.Name, "Dr. Sita Kumari");
    d2.Experience = 8;
    d2.Contact = 984556677;
    strcpy(d2.Hospital, "MediCare Hospital");

    // Enter data for d3
    strcpy(d3.Name, "Dr. Hari Prasad");
    d3.Experience = 15;
    d3.Contact = 983445566;
    strcpy(d3.Hospital, "Santoshi Hospital");

    // Enter data for d4
    strcpy(d4.Name, "Dr. Aarti Sharma");
    d4.Experience = 12;
    d4.Contact = 981234567;
    strcpy(d4.Hospital, "LifeCare Hospital");

    printf("Doctor 1: %s, Experience: %d years, Contact: %ld, Hospital: %s\n", d1.Name, d1.Experience, d1.Contact, d1.Hospital);
    printf("Doctor 2: %s, Experience: %d years, Contact: %ld, Hospital: %s\n", d2.Name, d2.Experience, d2.Contact, d2.Hospital);
    printf("Doctor 3: %s, Experience: %d years, Contact: %ld, Hospital: %s\n", d3.Name, d3.Experience, d3.Contact, d3.Hospital);
    printf("Doctor 4: %s, Experience: %d years, Contact: %ld, Hospital: %s\n", d4.Name, d4.Experience, d4.Contact, d4.Hospital);
}

int main() {
    char date[20];

    switch (user_menu()) {
        case 1:
            {
                printf("Enter today's date:\n");
                scanf("%s", date);  // Corrected scanf for date input
                FILE *ptr = fopen("medical_report.txt", "a+");
                if (ptr == NULL) {
                    printf("Error opening file.\n");
                    return 1;
                }
                fputs(date, ptr);
                switch (Diagnosis()) {
                    case 'a':
                        fputs("FEVER\t\t\t", ptr);
                        Fever();
                        break;
                    case 'b':
                        fputs("STOMACH ACHE\t\t\t", ptr);
                        Stomach_Ache();
                        break;
                    case 'c':
                        fputs("H BP\t\t\t", ptr);
                        HBloodPressure();
                        break;
                    case 'd':
                        fputs("L BP\t\t\t", ptr);
                        LBloodPressure();
                        break;
                    case 'e':
                        fputs("DIABETES\t\t\t", ptr);
                        Diabetes();
                        break;
                    default:
                        break;
                }
                fclose(ptr);
            }
            break;
        case 2:
            {
                FILE *ptr = fopen("medical_report.txt", "r");
                if (ptr == NULL) {
                    printf("Error opening file.\n");
                    return 1;
                }
                char op[100];
                fgets(op, 100, ptr);
                printf("Previous report: %s\n", op);
                fclose(ptr);
            }
            break;
        case 3:
            printf("Data of some professional Doctors:\n");
            Drpresent();
            break;

        default:
            break;
    }
    return 0;
}
