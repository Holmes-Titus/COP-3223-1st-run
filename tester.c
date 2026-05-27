#include <stdio.h>
#include <stdlib.h>

int test_function(int hit1, int hit2); // prototype or decleration (names of variables are optional but preferred)

int score = 0; //score is a glbal variable that can be modified anywhere

int main(void){

    

    return;
}

int test_function(int hit1, int hit2){ //definition (the actual work)
    //arguments are copied into the function, doesn't manipulate the actual value

    // arrays are pointers, so they son't manipulate a copy but the real thing

    //scope is a region of code where a name is visible and usable. Ex: hit1 has a scope of the test_function

    //

    return 0;
}