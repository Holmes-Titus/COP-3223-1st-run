#include <stdio.h>
#include "mathlib.h"

int get_validated_int(int min, int max, const char *prompt, const char *err);

int main(void) {
    int choice;


    do {
        printf("\n= Math Toolkit =\n");
        printf("1. Clamp a value\n");
        printf("2. Compute a power\n");
        printf("3. Prime check\n");
        printf("4. GCD\n");
        printf("5. Array average\n");
        printf("6. Count digits\n");
        printf("7. Quit\n");
        
        choice = get_validated_int(1, 5, "Enter choice (1-7): ", "Invalid choice. Try again.");
        
        
        switch (choice) {
            case 1: int x,y,z;  printf("Enter value, lo, hi: ");   fscanf(stdin, "%d %d %d", &x,&y,&z);    printf("clamp(%d, %d, %d) = %d",x,y,z,clamp(x,y,z)); break;
            case 2: int y; double w; printf("Enter base and exponent: ");   fscanf(stdin, "%lf %d", &w,&y);    printf("power(%lf, %d) = %d",w,y,power(w,y)); break;
            case 3: int y; printf("Enter n: ");   fscanf(stdin, "%d", &y);    printf("%d is %s",y,is_prime(y)); break;
            case 4: int x,y; printf("Enter a and b: ");   fscanf(stdin, "%d %d", &x,&y);    printf("gcd(%d, %d) = %d",x,y,gcd(x,y)); break;
            case 5: printf("Enter count then values: ");
            case 6: long long v; printf("Enter integer: ");   fscanf(stdin, "%lld", &v);    printf("%lld has %d digits",v,count_digits(v)); break;
            case 7: printf("Goodbye!\n");  break;
        }

    } while (choice != 7);

    return 0;
}

/* TODO: implement the functions below */

int get_validated_int(int min, int max, const char *prompt, const char *err){
    int pick;

    do {
    printf("%s", prompt);   //prompts an input
    fscanf(stdin, "%d", &pick); //takes in the input to integer pick
    if (pick < min || pick > max){  //checks if pick is not within given range
        printf("%s\n", err);    //returns error message if not within range
    }
    } while (pick < min || pick > max); //reprompts input if pick is outside range
    return pick;
}