#include "tester.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFREADSIZE 4096

double process_file(int n_data, int n_files, short*buffer);

int main(int argc, char**argv){
    short *buffer;

    int nos_data[] = {5, 10000, 100000, 1000000};
    for (int index = 0; index < 4; index++) {
        int n_data=nos_data[index];
        buffer = malloc(sizeof(short) * n_data);
        if (!buffer){ fprintf(stderr, "malloc fail \n"); exit(1);}

        double time_taken;
        for (int i=0; -1 != (time_taken = process_file(n_data, i, buffer)); i++)
            printf("time taken %lf\n", time_taken);
            
        free(buffer);
    }

    return 0;
}

double process_file(int n_data, int file_no, short*buffer){
    FILE *fp;
    char filename[50];
    sprintf(filename, "%s_%d_%03d.dat", "uns", n_data, file_no);
    printf("%s\n", filename);

    fp = fopen(filename, "r");
    if (!fp) {printf("out of files size %d\n", n_data); return (-1);}

    fread(buffer, sizeof(short), n_data, fp);


    for (int i=0; i<n_data; i++){
        printf("%d\n", buffer[i]);
    }
    clock_t start = clock();
    //put sorting function here
    selectionsort(buffer, n_data);
    clock_t end = clock();
    for (int i=0; i<n_data; i++){
        printf("%d\n", buffer[i]);
    }

    fclose(fp);
    return (double) (end - start) / CLOCKS_PER_SEC;
}
