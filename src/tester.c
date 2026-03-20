#include "tester.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define BUFFREADSIZE 4096

double process_file(int n_data, int file_no, char*unssorrev,
        char*dir, char*salgo, short*buffer);


int main(int argc, char**argv){
    short *buffer;

    if (argc != 7) {
        fprintf(stderr, "Usage: "
                "./tester <dir> <uns|sor|rev> <n_data> <file_start>"
                " \n\t\t\t<file_end> <selection|merge|quick>\n"

                "\nwhere   <dir> is directory of data files\n"
                "\t<uns|sor|rev> indicates data arrangement "
                "\n\t\t\t(i.e., first 3 chars of data filename)\n"
                "\t<n_data> is count of numbers in the file (e.g., 100000)\n"
                "\t<file_start> is the first file number to work with (usu. 0)\n"
                "\t<file_end> is the last file number (usu. 29)\n"
                "\t<selection|merge|quick> indicates what sorting algo to use\n"
                "\n\nSorry for annoying usage; this makes it easier to script\n"
               );
        exit(1);
    }

    char*dir = argv[1];
    char*unssorrev = argv[2];
    int n_data=atoi(argv[3]);
    int file_start=atoi(argv[4]);
    int file_end=atoi(argv[5]);
    char*salgo = argv[6];

    buffer = malloc(sizeof(short) * n_data);
    //printf("n data %d\n", n_data);
    if (!buffer){ fprintf(stderr, "malloc fail \n"); exit(1);}

    double time_taken;
    for (int i=file_start; i<=file_end; i++)
        printf(" %lf\n", process_file(n_data, i, unssorrev, dir, salgo, buffer));
        
    free(buffer);

    return 0;
}

double process_file(int n_data, int file_no, char*unssorrev,
        char*dir, char*salgo, short*buffer){
    FILE *fp;
    char filename[50];
    sprintf(filename, "%s/%s_%d_%03d.dat", dir, unssorrev, n_data, file_no);
    printf("%s ", filename);

    fp = fopen(filename, "r");
    if (!fp) {fprintf(stderr, "can't open file\n"); return (-1);}

    int pos = 0;
    for (int i = 0; i < n_data / BUFFREADSIZE; i++) {
        int done = fread(buffer + pos, sizeof(short), BUFFREADSIZE, fp);
        pos += BUFFREADSIZE;
        if (done != BUFFREADSIZE) printf("read %d \n", done);
    }
    fread(buffer + pos, sizeof(short), n_data % BUFFREADSIZE, fp);

    //if (argh > 1) {
    //    printf("presorting");
    //    for (int i=0; i<n_data; i++)
    //        printf("%hu ", buffer[i]);
    //}
    clock_t start = clock();
    //put sorting function here
    printf(" %s ", salgo);
    if (!strcmp(salgo, "selection"))
        selectionsort(buffer, n_data);
    else if (!strcmp(salgo, "quick"))
        quicksort(buffer, n_data);
    else if (!strcmp(salgo, "merge"))
        mergesort(buffer, n_data);
    clock_t end = clock();
    //if (argh > 1) {
    //    printf("\n");
    //    printf("sorted");
    //    for (int i=0; i<n_data; i++)
    //        printf("%hu ", buffer[i]);
    //}

    fclose(fp);
    return (double) (end - start) / CLOCKS_PER_SEC * 1000;
}
