#include <stdio.h>

//Titus Holmes: Week 2 Assignment — Unit Conversion Station

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
    printf("%s", prompt);   //prompts an input
    fscanf(stdin, "%d", &pick); //takes in the input to integer pick
    if (pick < min || pick > max){  //checks if pick is not within given range
        printf("%s\n", err);    //returns error message if not within range
    }
    } while (pick < min || pick > max); //reprompts input if pick is outside range
    return pick;
}

void convert_temperature(void) {
    
    int Selection_T;
    float Temp_Inital;
    float Temp_Final;

    printf("\n--- Temperature ---\n");      //header setup
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");

    Selection_T = get_validated_int(1, 2, "Enter choice (1-2): ", "Invalid direction. Try again."); // Prompt whether to convert degrees Fahrenheit to Celsius or vice-versa
    
    switch (Selection_T) {
        case 1: 
            printf("\nEnter temperature in Celsius: "); 
            fscanf(stdin, "%f", &Temp_Inital);    //take in temperature in Celcius
            Temp_Final = Temp_Inital * C_TO_F_SCALE + C_TO_F_OFFSET;   // Calculate the value
            printf("%.2f°C = %.2f°F\n",Temp_Inital,Temp_Final);    // Print the value and its unit
                break;
        default: 
            printf("\nEnter temperature in Fahrenheit: "); 
            fscanf(stdin, "%f", &Temp_Inital);    //take in temperature in Fahrenheit
            Temp_Final = (Temp_Inital - C_TO_F_OFFSET) / C_TO_F_SCALE; // Calculate the value
            printf("%.2f°F = %.2f°C\n",Temp_Inital,Temp_Final);    // Print the value and its unit
                break;
    }
 
};

void convert_distance(void) {
    
    int Selection_D;
    float Distance_Initial;
    float Distance_Final;

    printf("\n--- Distance ---\n");     //header setup
    printf("1. Miles to Kilometers\n");
    printf("2. Kilometers to Miles\n");

    Selection_D = get_validated_int(1, 2, "Enter choice (1-2): ", "Invalid direction. Try again."); // Prompt whether to convert Miles to Kilometers or vice-versa
    
    switch (Selection_D) {
        case 1: 
            printf("\nEnter distance in miles: "); 
            fscanf(stdin, "%f", &Distance_Initial);    //take in distance in miles
            Distance_Final = Distance_Initial * MI_TO_KM;   // Calculate the value
            printf("%.2f miles = %.2f km\n",Distance_Initial,Distance_Final);    // Print the value and its unit
                break;
        default: 
            printf("\nEnter distance in kilometers: "); 
            fscanf(stdin, "%f", &Distance_Initial);    //take in distance in kilometers
            Distance_Final = Distance_Initial  / MI_TO_KM; // Calculate the value
            printf("%.2f km = %.2f miles\n",Distance_Initial,Distance_Final);    // Print the value and its unit
                break;
    }

};

void convert_weight(void) {
    
    int Selection_W;
    float Weight_Initial;
    float Weight_Final;

    printf("\n--- Weight ---\n");       //header setup
    printf("1. Pounds to Kilograms\n");
    printf("2. Kilograms to Pounds\n");

    Selection_W = get_validated_int(1, 2, "Enter choice (1-2): ", "Invalid direction. Try again."); // Prompt whether to convert Pounds to Kilograms or vice-versa
    
    switch (Selection_W) {
        case 1: 
            printf("\nEnter weight in pounds: "); 
            fscanf(stdin, "%f", &Weight_Initial);  //take in weight in pounds
            Weight_Final = Weight_Initial * LB_TO_KG;   // Calculate the value
            printf("%.2f lbs = %.2f kg\n",Weight_Initial,Weight_Final);    // Print the value and its unit
                break;
        default: 
            printf("\nEnter weight in kilograms: "); 
            fscanf(stdin, "%f", &Weight_Initial);  //take in weight in kilograms
            Weight_Final = Weight_Initial  / LB_TO_KG; // Calculate the value
            printf("%.2f kg = %.2f lbs\n",Weight_Initial,Weight_Final);    // Print the value and its unit
                break;
    }

};

void convert_speed(void) {
    
    int Selection_S;
    float Speed_Initial;
    float Speed_Final;

    printf("\n--- Speed ---\n");        //header setup
    printf("1. MPH to KPH\n");
    printf("2. KPH to MPH\n");

    Selection_S = get_validated_int(1, 2, "Enter choice (1-2): ", "Invalid direction. Try again."); // Prompt whether to convert MPH to KPH or vice-versa
    
    switch (Selection_S) {
        case 1: 
            printf("\nEnter speed in MPH: "); 
            fscanf(stdin, "%f", &Speed_Initial);   //take in speed in MPH
            Speed_Final = Speed_Initial * MI_TO_KM;   // Calculate the value
            printf("%.2f MPH = %.2f KPH\n",Speed_Initial,Speed_Final);    // Print the value and its unit
                break;
        default: 
            printf("\nEnter speed in KPH: "); 
            fscanf(stdin, "%f", &Speed_Initial);   //take in speed in KPH
            Speed_Final = Speed_Initial  / MI_TO_KM; // Calculate the value
            printf("%.2f KPH = %.2f MPH\n",Speed_Initial,Speed_Final);    // Print the value and its unit
                break;
    }

};