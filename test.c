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
    while (i < (decimals+1)){
        temp *= 10;
        i++;
    }
    
    int final = (int) temp % 10;
    if (final >= 5){
        temp += 10;
    }
        i = 0;
    while (i < (decimals+1)){
        temp /= 10;
        i++;
    }
    *starting_value = temp;
    printf("%.3lf and %d\n",temp,final);

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
    double set = 27.89354;
    round_to(&set,3);
    printf("this is: %lf\n",set);


    int matrix[3][5];   //3 rows 5 columns
    //arrays aren't pointers, but can decay into them
    int scores[5] = {10,20,30,40,50};
    //no & needed, array name decays to &scores[0]
    int *p = scores;
    //loses knowledge of size


    //when passing an array to a function, it immidiately decays, into integer pointers losing it's size
    //to keep the size, calculate it beforehand and pass it through another variable
    //becuase its a pointer, a function can modify the array elements


    // null terminator '\0' marks the end of an string. String functions find the end by scanning for \0
    //compiler automatically adds a null terminator
    //string literals are read-only ex: char*p = "Hello";
    //use char buf[] when you need a modifiable string
    
    //don't use == when comparing 2 strings, that compares adresses not values
    // use strncmp instead, if the same = 0

    char greeting[20] = "Hello, ";
    char name[] = "Alice";
    strncat(greeting,name,sizeof(greeting) - strlen(greeting) - 1);
    
    //char buf[8]; reads unlimited input
    //gets(buf); has no size check
}

/* * is pointer to or go to the address of
& is the address of
this can be used to follow values instead of taking the instant value
*/