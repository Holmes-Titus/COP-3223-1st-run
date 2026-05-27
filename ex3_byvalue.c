#include <stdio.h>

void triple(int x){
    printf("%d\n",(x*3));
}

int triple_return(int x){
    return (x*3);
}

void add_ten(int a, int b){
    printf("Both numbers plus 10 is a: %d and b: %d\n",(a+10),(b+10));
}

int main(void){

    int a = 3;
    int b = 4;
    add_ten(a,b);

    int n = 7;
    triple(n);
    printf("n after triple(n): %d\n", n);
    int result = triple_return(n);
    printf("result: %d, n: %d\n", result, n);

}