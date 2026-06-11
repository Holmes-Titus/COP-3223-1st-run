#include "mathlib.h"

int clamp(int value, int lo, int hi) {
    if (lo<=value){
        if (hi >= value)    return value;//if lo<=value<=hi
        return hi;//if only lo<=value
    }
    return lo;//if lo>value
}

double power(double base, int exp) {
    double original_b = base;
    if (exp == 0) return 0.0;
    if (exp > 0) {
    for (int i = 0; i<(exp-1);i++)  base *=original_b;    return base;
    }
    for (int i = 0; i>(exp+1);i--)  base *=original_b;  return (1/base);
}

int is_prime(int n) {
    double check;
    if (n<2) return 0;
    for (int i =2; i<(n/2)+1;i++){
        check = ((double)n)/i;
        if (check == (int) check){
            return 0;
        }
    }
    return 1;
}

int gcd(int a, int b) {
    int dividend;
    int divisor;
    int remainder = 1;
    if (a>b) {dividend = a; divisor = b;}
    else {dividend = b; divisor = a;}
    while (remainder > 0){
        remainder = dividend % divisor;
        dividend = divisor;
        divisor = remainder;
    }
    return dividend;
}

double average(int arr[], int len) {
    double avg = 0.0;
    if (len <=0) return 0.0;
    for (int i = 0; i < len; i++){
        avg += arr[i];
    }
    return avg / len;
}

int count_digits(long long n) {
    if (n==0) return 1;
    int count = 0;
    if (n<0) n*= (-1);
    while (n > 0){
        n/=10;
        count++;
    }
    return count;
}