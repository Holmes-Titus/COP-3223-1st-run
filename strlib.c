#include "strlib.h"
#include <stdio.h> // for testing

int str_length(const char *s) {
    /* TODO: walk s with a pointer until '\0', count steps */
    int count = 0;
    while (s[count]!= '\0'){
        count ++;
    }
    return count-1;
}

void str_copy(char *dst, const char *src, int dst_size) {
    int count = 0;
    char filler[dst_size];
    for (int i = 0; i < dst_size; i++) filler[i] = '\0';
    *dst = *filler;
    while (src[count] != '\0' && count <= dst_size -2){
        dst[count] = src[count];
        count++;
    }
    dst[dst_size - 1] = '\0';
    /* TODO: copy characters one at a time, stop at dst_size-1 or '\0' */
    /* Always null-terminate dst */
}

int str_compare(const char *a, const char *b) {
    /* TODO: walk both strings simultaneously, return first difference */
    int lena = str_length(a);
    int lenb = str_length(b);
    int lenmax = lena;
    if (lenb > lenmax) lenmax = lenb;

    for (int i = 0;i<lenmax;i++){
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return -1;
    }
    return 0;
}

void str_reverse(char *s) {
    /* TODO: swap characters from both ends toward the middle */
    int len = 0;
    while (s[len] != '\0') len ++;
    char copy[len];
    for (int i = 0; i < len-1; i++) {  copy[i] = s[i];  }
    for (int j= 1; j < len; j++) {  s[j-1] = copy[len-j-1]; }
    s[-1] = '\0';
}

int str_count_char(const char *s, char c) {
    /* TODO */
    int tracker = 0;
    int count = 0;
    while (s[count]!= '\0'){
        if (s[count] == c) tracker++;
    count ++;
    }
    return tracker;
}

void str_to_upper(char *s) {
    /* TODO: for each char, if 'a' <= c <= 'z', subtract 32 */
    int count = 0;
    while (s[count]!= '\0'){
        if ('a' <= s[count] && s[count] <= 'z') s[count] -= 32;
    count ++;
    }
}

void array_stats(const int arr[], int len,
                 int *out_min, int *out_max, double *out_avg) {
    /* TODO: handle len <= 0 case; otherwise scan for min/max/sum */
}

int array_find(const int arr[], int len, int target) {
    /* TODO: linear scan; return index or -1 */
    return -1;
}