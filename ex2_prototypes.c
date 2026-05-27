#include <stdio.h>

int clamp(int val, int lo, int hi);
int absolute_value(int x);
double celsius_to_fahrenheit(double c);
int is_even(int n);

int main(void){

    int x = 7;
    int y = 0;
    int z = 10;
    printf("The value is: %d \n", clamp(x,y,z));
    int a = -4;
    printf("The absolute value of a is: %d \n",absolute_value(a));
    double temp = 100;
    printf("The temperature in Fahrenheit is: %lf \n",celsius_to_fahrenheit(temp));
    printf("This shows whether x is even: %d \n", x);


}

int clamp(int val, int lo, int hi){
    if (lo <= val || val <= hi) return val;
    if (val < lo) return lo;
    return hi;
}

int absolute_value(int x){
    if (x < 0) return x*(-1);
    return x;
}

double celsius_to_fahrenheit(double c){
    return (c*(9/5) + 32);
}

int is_even(int n){
    if (n%2) return 0;
    return 1;
}