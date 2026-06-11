#include "mathlib.h"

int clamp(int value, int lo, int hi) {
    if (lo<=value){
        if (hi >= value)    return value;//if lo<=value<=hi
        return hi;//if only lo<=value
    }
    return lo;//if lo>value
}

double power(double base, int exp) {
    /* TODO */
    return 0.0;
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
    /* TODO */
    return 0;
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