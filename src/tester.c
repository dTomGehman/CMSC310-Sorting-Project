#include "tester.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFREADSIZE 4096

double process_file(int n_data, int n_files, short*buffer);

int argh;

int main(int argc, char**argv){
    short *buffer;
    argh = argc;

    int nos_data[] = {5, 1000, 10000, 100000, 1000000};
    for (int index = 0; index < 5; index++) {
        int n_data=nos_data[index];
        buffer = malloc(sizeof(short) * n_data);
        printf("n data %d\n", n_data);
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

    int pos = 0;
    for (int i = 0; i < n_data / BUFFREADSIZE; i++) {
        int done = fread(buffer + pos, sizeof(short), BUFFREADSIZE, fp);
        pos += BUFFREADSIZE;
        if (done != BUFFREADSIZE) printf("read %d \n", done);
    }
    fread(buffer + pos, sizeof(short), n_data % BUFFREADSIZE, fp);

    if (argh > 1) {
        printf("presorting");
        for (int i=0; i<n_data; i++)
            printf("%hu ", buffer[i]);
    }
    clock_t start = clock();
    //put sorting function here
    //selectionsort(buffer, n_data);
    //quicksort(buffer, n_data);
    mergesort(buffer, n_data);
    clock_t end = clock();
    if (argh > 1) {
        printf("\n");
        printf("sorted");
        for (int i=0; i<n_data; i++)
            printf("%hu ", buffer[i]);
    }

    fclose(fp);
    return (double) (end - start) / CLOCKS_PER_SEC;
}
