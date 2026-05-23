#include <stdio.h>

/* Conversion constants */
const double C_TO_F_SCALE  = 9.0 / 5.0;
const double C_TO_F_OFFSET = 32.0;
const double MI_TO_KM      = 1.60934;
const double LB_TO_KG      = 0.453592;

void convert_temperature(void);
void convert_distance(void);
void convert_weight(void);
void convert_speed(void);

int get_validated_int(int min, int max, const char *prompt, const char *err);

int main(void) {
    int choice;

    do {
        printf("\n= Unit Conversion Station =\n");
        printf("1. Temperature  (Celsius <-> Fahrenheit)\n");
        printf("2. Distance     (Miles <-> Kilometers)\n");
        printf("3. Weight       (Pounds <-> Kilograms)\n");
        printf("4. Speed        (MPH <-> KPH)\n");
        printf("5. Quit\n");
        
        choice = get_validated_int(1, 5, "Enter choice (1-5): ", "Invalid choice. Try again.");
        

        switch (choice) {
            case 1: convert_temperature(); break;
            case 2: convert_distance();    break;
            case 3: convert_weight();      break;
            case 4: convert_speed();       break;
            case 5: printf("Goodbye!\n");  break;
        }

    } while (choice != 5);

    return 0;
}

/* TODO: implement the functions below */

int get_validated_int(int min, int max, const char *prompt, const char *err){
    int pick;

    do {
    printf("%s", prompt);
    fscanf(stdin, "%d", &pick);
    if (pick < min || pick > max){
        printf("%s\n", err);
    }
    } while (pick < min || pick > max);
    return pick;
}

void convert_temperature(void) {
    
    int selection_T;
    float temp1;
    float temp2;

    printf("\n--- Temperature ---\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");

    selection_T = get_validated_int(1, 2, "Enter choice (1-2): ", "Invalid direction. Try again."); // Prompt whether to convert degrees Fahrenheit to Celsius or vice-versa
    
    switch (selection_T) {
        case 1: 
            printf("\nEnter temperature in Celsius: "); 
            fscanf(stdin, "%f", &temp1);
            temp2 = temp1 * C_TO_F_SCALE + C_TO_F_OFFSET;   // Calculate the value
            printf("%.2f°C = %.2f°F\n",temp1,temp2);    // Print the value and its unit
                break;
        default: 
            printf("\nEnter temperature in Fahrenheit: "); 
            fscanf(stdin, "%f", &temp1);
            temp2 = (temp1 - C_TO_F_OFFSET) / C_TO_F_SCALE; // Calculate the value
            printf("%.2f°F = %.2f°C\n",temp1,temp2);    // Print the value and its unit
                break;
    }
 
};

void convert_distance(void) {
    
    int selection_D;
    float dist1;
    float dist2;

    printf("\n--- Distance ---\n");
    printf("1. Miles to Kilometers\n");
    printf("2. Kilometers to Miles\n");

    selection_D = get_validated_int(1, 2, "Enter choice (1-2): ", "Invalid direction. Try again."); // Prompt whether to convert Miles to Kilometers or vice-versa
    
    switch (selection_D) {
        case 1: 
            printf("\nEnter distance in miles: "); 
            fscanf(stdin, "%f", &dist1);
            dist2 = dist1 * MI_TO_KM;   // Calculate the value
            printf("%.2f miles = %.2f km\n",dist1,dist2);    // Print the value and its unit
                break;
        default: 
            printf("\nEnter distance in kilometers: "); 
            fscanf(stdin, "%f", &dist1);
            dist2 = dist1  / MI_TO_KM; // Calculate the value
            printf("%.2f km = %.2f miles\n",dist1,dist2);    // Print the value and its unit
                break;
    }

};

void convert_weight(void) {
    
    int selection_W;
    float weight1;
    float weight2;

    printf("\n--- Weight ---\n");
    printf("1. Pounds to Kilograms\n");
    printf("2. Kilograms to Pounds\n");

    selection_W = get_validated_int(1, 2, "Enter choice (1-2): ", "Invalid direction. Try again."); // Prompt whether to convert Miles to Kilometers or vice-versa
    
    switch (selection_W) {
        case 1: 
            printf("\nEnter weight in pounds: "); 
            fscanf(stdin, "%f", &weight1);
            weight2 = weight1 * LB_TO_KG;   // Calculate the value
            printf("%.2f lbs = %.2f kg\n",weight1,weight2);    // Print the value and its unit
                break;
        default: 
            printf("\nEnter weigth in kilograms: "); 
            fscanf(stdin, "%f", &weight1);
            weight2 = weight1  / LB_TO_KG; // Calculate the value
            printf("%.2f kg = %.2f lbs\n",weight1,weight2);    // Print the value and its unit
                break;
    }

};

void convert_speed(void) {
    // Prompt whether to convert MPH to KPH or vice-versa
    // Calculate the value
    // Print the value and its unit 
};