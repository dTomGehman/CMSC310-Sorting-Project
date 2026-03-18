#include "tester.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void mergesort(short*buffer, int n_data) {

    if (n_data <= 1) return; //1 item is already sorted
    
    int divide = (n_data) / 2;

    short*left = malloc(sizeof(short) * (divide));
    short*right = malloc(sizeof(short) * (n_data - divide));
    if (!left || !right) {fprintf(stderr, "malloc failed\n"); exit(1);}
    
    memcpy(left, buffer, sizeof(short) * divide);
    memcpy(right, buffer + divide, sizeof(short) * (n_data - divide));

    mergesort(left, divide);
    mergesort(right, n_data - divide);

    //assume two subarrays are now sorted
    //merge
    int l=0, r=0, c=0;
    while (l<divide && r<(n_data-divide)) {
        if (left[l] < right[r]) {
            buffer[c++] = left[l++];
        } else {
            buffer[c++] = right[r++];
        }
    }
    if (l == divide)
        memcpy(buffer + c, right + r, sizeof(short) * (n_data - divide - r));
    else
        memcpy(buffer + c, left + l, sizeof(short) * (divide - l));
    
}
