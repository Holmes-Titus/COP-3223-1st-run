#include <stdio.h>  //for stdin/stdout
#include <stdlib.h> //for malloc/calloc/realloc
#include <string.h> //for string functions

int main(void){

    //Pointers pointers pointers

    //why malloc?
    /*
    no room for growth in the stack
    saves the state or statframe (what function it is within)
    you must give array length as space needs to be allocated ahead of time
    stack has stack pointers, that move as we pull/push stack frames
    typically the array elements are contiguous in memory
    if you tried to modify the array length then it would mess up the stack pointer
    The heap on the otherhand lets you manually change th ememory allocation
    too much information can blow the stack
    you can declare anything in the heap
    tne stack is automatic storage, where the compiler cotrols the memory
    don't worry about the stack except overloading it

    Use temp arrays in order to prevent memory loss if realloc fails
    
    
    */

    int len = 0;
    printf("%d\n",len++);
    printf("%d\n",len++);
    len++;
    printf("%d\n",++len);


    //  free each row before freeing the array itself
    /*
    Memory leak, malloc without free
    Double free, 2 frees on one pointer
    Use after free, Dereferencing after free
    Buffer overflow, Writing past the end of allocation
    Unititialized read, Using malloc'd memory before writing
    Freeing stack memory, free on a non-heap pointer
    
    */

    return 1;}