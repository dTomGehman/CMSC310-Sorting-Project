#include "tester.h"
#include <stdio.h>

void qsort_helper(short*buffer, int start, int end);

void quicksort(short*buffer, int n_data) { 
    qsort_helper(buffer, 0, n_data);
}

void qsort_helper(short*buffer, int start, int end) {
    if (end - start <= 1) return;
    int partition = -1;
    if (end - start < 101) partition = start;
    else {
        int mid = (start + end - 1) / 2;
        if (buffer[start] < buffer[end - 1]) {
            if (buffer[mid] < buffer[start]) {
                partition = start;
            } else if (buffer[mid] < buffer[end - 1]) {
                partition = mid;
            } else partition = end - 1;
        } else {
            if (buffer[mid] < buffer[end - 1]) {
                partition = end - 1;
            } else if (buffer[mid] < buffer[start]) {
                partition = mid;
            } else partition = start;
        }
    }
    if (partition == -1) fprintf(stderr, "An error has occurred");

    short partvalue = buffer[partition];
    short temp;

    int i = start, j = start, k = (end - 1);

    while (j <= k) {
        if (buffer[j] < partvalue) {
            temp = buffer[j];
            buffer[j] = buffer[i];
            buffer[i] = temp;
            i++; j++;
        } else if (buffer[j] > partvalue) { 
            temp = buffer[j];
            buffer[j] = buffer[k];
            buffer[k] = temp;
            k--;
        } else j++;
    }
    //printf("partition %d  partvalue %hu  i %d j %d k %d\n", partition, partvalue, i, j,k);

    qsort_helper(buffer, start, i);
    qsort_helper(buffer, k+1, end);
}
