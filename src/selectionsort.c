#include "tester.h"
#include <stdio.h>

void selectionsort(short*buffer, int n_data){
    int mindex;
    short temp;
    for (int part=0; part < n_data - 1; part++) {
        mindex = part;
        for (int j = part + 1; j < n_data; j++) {
            if (buffer[j] < buffer[mindex])
                mindex = j;
        }
        temp = buffer[part];
        buffer[part] = buffer[mindex];
        buffer[mindex] = temp;
    }
}

