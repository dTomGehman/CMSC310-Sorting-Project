#include "tester.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFREADSIZE 4096

int main(int argc, char**argv){

    FILE *fp;
    short *buffer;
    char filename[50];

    char *filename_temp = "%s_%d_%03d.dat";
    sprintf(filename, filename_temp, "uns", 5, 0);
    printf("%s\n", filename);

    fp = fopen(filename, "r");
    if (!fp) {fprintf(stderr, "failed to open %s\n", filename); exit(1);}
    buffer = malloc(sizeof(short) * 5);

    fread(buffer, sizeof(short), 5, fp);
    for (int i=0; i<5; i++){
        printf("%d\n", buffer[i]);
    }

    return 0;
}

