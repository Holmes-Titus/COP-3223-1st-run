#include <stdio.h>
#include <stdlib.h> //for malloc/calloc
#include <string.h>

int main(void){

    /*
    Stack -> Local variables and fixed arrays
    Data segment-> sttics, global vars
    Heap-> malloc/calloc until you call free
    Stack allocation is automatic
    Heap allocation is manual, this memory escapes the scope of the function
    malloc -> memory allocator
    returns a pointer to the start of the allocated memory
    Stack is only valid for the function scope

    */

    //2-D arrays
    int grid[3][4]; //3 rows, 4 columns
    //memory is flat (row-major order) grid[0][0] -> grid [0][1] -> grid [0][2]...
    int b[3][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    //arrays still decay into pointers
    //take in number of rows in order to rebuild the array within the function
    //columns must be hard coded, but rows can be a parameter
    //Colmuns must be hard coded because it is used to calculate element adresses

    //3-D and more arrays
    int cube[2][3][4];
    //every bound after the first must be a compile time constant
    //number 42 is the answer to the life the unvirverse the everything
    int arr[3] = {1,2,3};
   // int *p = arr;
    //printf("%d",p[1]);

    //Pointer to a Pointer
    int x = 27;
    int *p = &x;
    int **pp = &p;
    printf("%d\n",**pp);
    //pp is a pointer to p, which is a point to x


    //we can use int ** in order to modify a pointer within a function
    // Absolutely everything in C is pass by vlue, so EVERYTHING is copied
    
    
    //you can change the size of an array on the heap by allocating more/less memory
    // allocate a new extent with the wanted array size, and copy over the contents
    // only when realloc dosen't have contiguos memory for expanding your array

    //if not contiguos, then realloc will make a new allocation of the desired size, and change the original pointer
    //wont work if pointer is set to const
    
    // Deleting items in Linked Lists:
    /*
    
    
    
    */

    //Always check for NULL from malloc, as it can fail when out of space
    //using sizeof(type) is better than sizeof(variable) for malloc arguments when the type doesn't change
    //free(variable name) releases the memory when no longere used
    //nullling the pointer is good practice
    //free(arr)
    //arr = NULL;
    
    //If you malloc but does't free the memory, then a memory leak can occur

    //calloc is zeroed Allocation

    //a void pointer is a memory adress of no type
    //usually involves type casting
    

}