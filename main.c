#include <stdio.h>
#include "roster.h"

int get_validated_int(int min, int max, const char *prompt, const char *err);

int main(void){
    int choice;
    do {
        printf("\n= String & Array Toolkit =\n");
        printf("1. String length\n");
        printf("2. String copy (with truncation demo)\n");
        printf("3. String compare\n");
        printf("4. Reverse a string\n");
        printf("5. Count a character\n");
        printf("6. Convert to uppercase\n");
        printf("7. Array stats (min/max/avg)\n");
        printf("8. Quit\n");

        choice = get_validated_int(1, 8, "Enter choice (1-8): ", "Invalid choice. Try again.");

        switch (choice) {
            case 1: {Roster r;  Student s;  int success = roster_add(&r,s); break;}
            case 2: {Roster r;  int id;  int success = roster_remove(&r,id); break;}
            case 3: {break;}
            case 4: {break;}
            case 5: {break;}
            case 6: {break;}
            case 7: {break;}
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