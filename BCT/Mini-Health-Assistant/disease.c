#include<stdio.h>
#include<stdlib.h>

int main()
{
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

    return 0;
}