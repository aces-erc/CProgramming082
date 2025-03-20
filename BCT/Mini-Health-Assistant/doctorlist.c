#include<stdio.h>
#include<string.h>

int main()
{
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
    return 0;
}