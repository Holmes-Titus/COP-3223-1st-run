#include <stdio.h>
#include "strlib.h"
#include <string.h>

int get_validated_int(int min, int max, const char *prompt, const char *err);

int main(void) {
    int choice;


    do {
        printf("\n= String & Array Toolkit =\n");
        printf("1. String length\n");
        printf("2. String copy (with truncation demo)\n");
        printf("3. String compare\n");
        printf("4. Reverse a string\n");
        printf("5. Count a character\n");
        printf("6. Convert to uppercase\n");
        printf("7. Array stats (min/max/avg)\n");
        printf("8. Find value in array\n");
        printf("9. Quit\n");
        
        choice = get_validated_int(1, 9, "Enter choice (1-9): ", "Invalid choice. Try again.");
        
        
        switch (choice) {
            case 1: {char length[64];  printf("Enter string: "); fgets(length,sizeof(length),stdin);    printf("Length: %d\n",str_length(length)); break;}
            case 2: {char throwaway[64];    int dst_size = 0; printf("Enter dst: "); char dst[64] = {'\0'}; fgets(throwaway,sizeof(dst),stdin); while (throwaway[dst_size] != '\0') {dst_size ++;} printf("Enter src: "); char src[64];  fgets(src,sizeof(src),stdin);    str_copy(dst,src,dst_size); printf("string copied: %s\n",dst); break;}
            case 3: {char a[64];char b[64];  printf("Enter a: ");   fgets(a,sizeof(a),stdin);  printf("Enter b: ");   fgets(b,sizeof(b),stdin);  int result = str_compare(a,b); if (result == 1){printf("%s comes after %s\n",a,b);} else if (result < 0) {printf("%s comes before %s\n",a,b);} else{printf("%s equals %s\n",a,b);} break;}
            case 4: {char s[64]; printf("Enter string: ");   fgets(s,sizeof(s),stdin);  str_reverse(s);  printf("Reversed: %s\n",s); break;}
            case 5: {char str[64]; char c = ' ';   printf("Enter string: "); fgets(str,sizeof(str),stdin); printf("Enter string: "); fscanf(stdin, "%c", &c);    getchar();   printf("Count: %d\n",str_count_char(str,c));   break;}
            case 6: {char str_upper[64]; printf("Enter string: ");   fgets(str_upper,sizeof(str_upper),stdin);  str_to_upper(str_upper);  printf("Upper: %s\n",str_upper); break;}
            case 7: {int len = 0; int out_min,out_max = 0; double out_avg = 0.0;   printf("Enter count then values: ");  fscanf(stdin, "%d", &len); getchar(); if (len<=0) {printf("min=0 max=0 avg=0.00\n");  break;}  int values[len];   for (int i =0;i<len;i++) {fscanf(stdin, "%d", &values[i]);}  getchar(); array_stats(values,len,&out_min,&out_max,&out_avg);  printf("min=%d max=%d avg=%.2f\n",out_min,out_max,out_avg);   break;}
            case 8: {int count = 0; int goal = 0; int answer = -1;  printf("Enter count then values: ");  fscanf(stdin, "%d", &count); getchar(); if (count<=0) {printf("Enter target: ");    fscanf(stdin,"%d",&goal); getchar();  printf("Not found.\n");  break;}  int values[count];   for (int i =0;i<count;i++) {fscanf(stdin, "%d", &values[i]); getchar();}  printf("Enter target: "); fscanf(stdin,"%d",&goal); getchar(); answer = array_find(values,count,goal); if (answer > 0) { printf("Found at index %d.\n",answer); } else {printf("Not found.");} break;}
            case 9: {printf("Goodbye!\n");  break;}
        }

    } while (choice != 9);

    return 0;
}

/* TODO: implement the functions below */

int get_validated_int(int min, int max, const char *prompt, const char *err){
    int pick;

    do {
    printf("%s", prompt);   //prompts an input
    fscanf(stdin, "%d", &pick); //takes in the input to integer pick
    getchar();
    if (pick < min || pick > max){  //checks if pick is not within given range
        printf("%s\n", err);    //returns error message if not within range
    }
    } while (pick < min || pick > max); //reprompts input if pick is outside range
    return pick;
}