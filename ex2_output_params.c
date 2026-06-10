#include <stdio.h>



void swap(int *a, int *b) {
int temp = *a;
*a = *b;
*b = temp;
}
void stats(const int arr[], int len, int *out_min, int *out_max,double *out_avg){ //only will work for all values >0
    *out_min = arr[0];
    *out_max = arr[0];
    for (int i=1;i<len;i++){
        if (arr[i] < *out_min){
            *out_min = arr[i];
        }
        if (arr[i] > *out_max)*out_max = arr[i];
        *out_avg += arr[i];
    }
    *out_avg /= (double) len;
}

int main(void){
    int x = 5;
    int y = 10;
    swap(&x,&y);
    printf("swap: x=%d and y= %d\n",x,y);

    int data[] = {34, 12, 78, 56, 23};
    int len = sizeof(data)/sizeof(data[0]);
    double avg;
    int min;
    int max;
    stats(data, len,&min,&max,&avg);
    printf("min=%d, max=%d, avg=%.2f\n",min,max,avg);

}