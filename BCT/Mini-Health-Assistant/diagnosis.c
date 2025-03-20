#include<stdio.h>


int main()
{
    char Diagnosis()
    {
        
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
        char disease;
        printf("Choose for your related symptoms: ");
        scanf(" %c", &disease);  
        return disease;
    }

    return 0;
}