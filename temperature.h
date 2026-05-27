#include <stdio.h>
#ifndef TEMPERATURE_H
#define TEMPERATURE_H

int celsius_to_fahrenheit_int(int c);
double celsius_to_fahrenheit(double c);
int fahrenheit_to_celsius_int(int f);
double fahrenheit_to_celsius(double f);
void print_conversion_table(int start, int end, int step);

#endif