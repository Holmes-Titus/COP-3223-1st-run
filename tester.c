#include <stdio.h>
#include <stdlib.h>

#ifndef COMBAT_H    //if this macro isn't yet defined
#define COMBAT_H    //then now define it
//combat.h becomes COMBAT_H

//.o is an object file
//gcc combat.o main.o -o game       //This makes a game file using combat and main c files


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

#endif COMBAT_H //end the if statement