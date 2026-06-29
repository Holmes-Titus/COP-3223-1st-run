#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

    //Big O notations (the preformance of algorithms)
    //as input size N grows, how does the number of operations grow
    /*
    
    Ex: averaging the number of inputs is N
    We want to find the shape of the curve, or how O changes as N -> infinity
    O(1) is the fastest possible time. Time is independent on N
    Ex of O(1): check if even, accessing an array element, inseting a node to the head of a linked list
    O() consideres the worst possible scenario
    Ex: attempting to find index by searching through all values is O(N)
    Ex: attempting to find index of a sorted array by using BNS is O(log(N)) (log is base 2)
    O(N) is when each input requires an independent use
    O(N^2) time grows exponentially with N; Often due to nested loops and dangerous for large data sets
    We only care about the shape, so drop constants O(N) = O(2N)
    Drop smaller terms, so O(N^2+N) = O(N^2)
    Inserting in the front of arrays is O(N), while inserting to the front of linked lists is O(1)
    Knowing O helps us choose the right tool for the job
    
    */

return 1;
}