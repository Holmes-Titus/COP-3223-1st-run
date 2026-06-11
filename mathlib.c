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
    /* TODO */
    return 0;
}

int gcd(int a, int b) {
    /* TODO */
    return 0;
}

double average(int arr[], int len) {
    /* TODO */
    return 0.0;
}

int count_digits(long long n) {
    /* TODO */
    return 0;
}