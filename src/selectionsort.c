#include "tester.h"
#include <stdio.h>

void selectionsort(short*buffer, int n_data){
    int mindex;
    int min;
    for (int part=0; part < n_data - 1; part++) {
        mindex = part;
        min = buffer[mindex];
        for (int j = part + 1; j < n_data; j++) {
            if (buffer[j] < min) {
                mindex = j;
                min = buffer[mindex];
            }
        }
        if (part != mindex) {
            buffer[mindex] = buffer[part];
            buffer[part] = (short) min;
        }
    }
}

