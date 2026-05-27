#include <stdio.h>
#include "temperature.h"

int main(void) {
    print_conversion_table(0, 100, 10);
    printf("\n32F = %.2fC\n", fahrenheit_to_celsius(32.0));
    printf("100C = %.2fF\n", celsius_to_fahrenheit(100.0));
    return 0;
}