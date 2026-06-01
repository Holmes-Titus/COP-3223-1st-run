#include <stdio.h>

#define MAX_SIZE 100    /*
replaces all instances of MAX_SIZE with the string 100
This is a substitution
doesn't follow scoping rules
file wide
reserve for incluse gaurds and macros
*/
const double PI = 3.14159265358979;
/*
this is a typed, scoped variable
void print_score(const int *score, int *output); can only read through the value, not change it, nbut output can/will be changed
function promises not to modify the value

const int *p; only p can change
int *const *p; only *p can change
const int *const *p; neither can change

int* p, q;   only the p is a pointer
int *p, q;   community convention: only p is a pointer
int *p, *q;  both p and q are pointers


all pointers are 8 bytes
pointer types tells the compiler how many bytes to read when dereferencing and how to interpret them

dereferencing through the wrong type reads the wrong number of bytes, causing inaccurate interpretation

uniitialized pointers are dangerous
int *p = NULL;, safe to dereference and explicitly points to nothing
*/

void round_to(double *starting_value, int decimals){
    double temp = *starting_value;
    int i = 0;
    while (i < decimals){
        temp *= 10;
        i++;
    }
    
    //double final = temp % 1;


}

int main(void){
    int x = 42;
    int *p = &x;
    int a = 3;
    int b = 4;
    int c = a *b;
    printf("Hi\n");
    printf("%p\n",p);
    *p = 100;   //this changes the value at the address
    printf("This is the new value of x: %d\n",x);
    printf("%lf\n",PI); // remember byte limits
    printf("%d\n",c);
    double set = 27.8955;
    round_to(&set,3);
    printf("this is: %lf\n",set);
}

/* * is pointer to or go to the address of
& is the address of
this can be used to follow values instead of taking the instant value
*/