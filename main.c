#include <stdio.h>
#include <string.h>
#include "roster.h"

Roster students;

int get_validated_int(int min, int max, const char *prompt, const char *err);

int main(void){
    int choice;
    do {
        printf("\n= Student Roster System =\n");
        printf("1. Add student\n");
        printf("2. Remove student (by ID)\n");
        printf("3. Find student (by ID)\n");
        printf("4. Find student (by last name)\n");
        printf("5. Sort by name\n");
        printf("6. Sort by GPA\n");
        printf("7. Print roster\n");
        printf("8. Quit\n");

        choice = get_validated_int(1, 8, "Enter choice (1-8): ", "Invalid choice. Try again.");

        switch (choice) {
            case 1: {  
                char first[32];
                char last[32];
                int id = 0;
                double gpa = 0.0;
                printf("First Name: ");
                fgets(first,sizeof(first),stdin);
                first[strcspn(first,"\n")] = '\0';
                printf("Last Name: ");
                fgets(last,sizeof(last),stdin);
                last[strcspn(last,"\n")] = '\0';
                printf("Student ID: ");
                fscanf(stdin,"%d",&id);
                getchar();
                printf("GPA: ");
                fscanf(stdin,"%lf",&gpa);
                getchar();
                Student s = create_student(first, last, id, gpa);
                int success = roster_add(&students,s); 
                if (success == 0) printf("Roster Full, Student Not Added.\n");
                if (success == 1) printf("Student added.\n");
                if (success == -1) printf("ID Already Exists, Student Not Added.\n");
                break;}
            case 2: {
                int id = 0;
                printf("Enter student ID: ");
                fscanf(stdin,"%d",&id);
                getchar();
                int success = roster_remove(&students,id);
                if (success == 0) printf("Student Not Found\n");
                if (success == 1) printf("Student removed.\n");
                break;}
            case 3: {
                int id = 0;
                printf("Enter student ID: ");
                fscanf(stdin,"%d",&id);
                getchar();
                if (roster_find_by_id(&students,id) == NULL) printf("Student Not Found\n");
                else print_student(roster_find_by_id(&students,id));
                break;}
            case 4: {
                char last[32];
                printf("Enter last name: ");
                fgets(last,sizeof(last),stdin);
                last[strcspn(last,"\n")] = '\0';
                if (roster_find_by_name(&students,last) == NULL) printf("Student Not Found\n");
                else print_student(roster_find_by_name(&students,last));
                break;}
            case 5: {
                roster_sort_by_name(&students);
                break;}
            case 6: {
                roster_sort_by_gpa(&students);
                break;}
            case 7: {
                print_roster(&students);
                break;}
            case 8: {printf("Goodbye!\n");  break;}
        }

    } while (choice != 8);

    return 0;

}

int get_validated_int(int min, int max, const char *prompt, const char *err){
    int pick;

    do {
    printf("%s", prompt);   //prompts an input
    fscanf(stdin, "%d", &pick); //takes in the input to integer pick
    getchar();
    if (pick < min || pick > max){  //checks if pick is not within given range
        printf("%s\n", err);    //returns error message if not within range
    }
    } while (pick < min || pick > max); //reprompts input if pick is outside range
    return pick;
}