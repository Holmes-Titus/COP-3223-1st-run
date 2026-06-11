#include <stdio.h>
int main(void){
    int x; printf("Enter count then values: ");  fscanf(stdin, "%d", &x); int values[x];    for (int i =0;i<x;i++) fscanf(stdin, "%d", &values[i]); 
    printf("%d\n",values[3]);
}