#include <stdio.h>
int main(void) {
int a = 10;
int b = 20;
int *p = &a;
printf("a = %d\n", a); /* predict: _____ */
printf("b = %d\n", b); /* predict: _____ */
printf("*p = %d\n", *p); /* predict: _____ */
printf("p == &a? = %d\n", p == &a); /* predict: _____ */
*p = 99;
printf("\nAfter *p = 99:\n");
printf("a = %d\n", a); /* predict: _____ */
printf("*p = %d\n", *p); /* predict: _____ */
p = &b;
printf("\nAfter p = &b:\n");
printf("*p = %d\n", *p); /* predict: _____ */
printf("a = %d\n", a); /* predict: _____ */
*p = *p + 5;
printf("\nAfter *p = *p + 5:\n");
printf("b = %d\n", b); /* predict: _____ */
return 0;
}