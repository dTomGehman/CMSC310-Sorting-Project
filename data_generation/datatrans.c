#include "../src/tester.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFREADSIZE 4096

void process_file(int n_data, int n_files);

int main(int argc, char**argv){
    if (argc != 2) {fprintf(stderr, "Usage:  ./datatrans <FILENAME.dat>\n"); exit(1);}
    
    int n_data, file_no;

    int sc = sscanf(argv[1], "uns_%d_%d.dat", &n_data, &file_no);
    if (sc != 2) {fprintf(stderr, "filename must be of form uns_%d_%d.dat"); exit(1);}
    
//    printf("n data %d ", n_data);
//    printf("fileno %d ", file_no);

    process_file(n_data, file_no);

    return 0;
}

void process_file(int n_data, int file_no){
    FILE *infp, *sorfp, *revfp;
    char infilename[50];
    char sorfilename[50];
    char revfilename[50];

    sprintf(infilename, "%s_%d_%03d.dat", "uns", n_data, file_no);
    sprintf(sorfilename, "%s_%d_%03d.dat", "sor", n_data, file_no);
    sprintf(revfilename, "%s_%d_%03d.dat", "rev", n_data, file_no);
    
    printf("creating %s and %s from %s...", sorfilename, revfilename, infilename);

    short*inbuffer = malloc(sizeof(short) * n_data);
    //short*sorbuffer = malloc(sizeof(short) * n_data);
    short*revbuffer = malloc(sizeof(short) * n_data);
    if (!inbuffer || !revbuffer){ fprintf(stderr, "malloc fail \n"); exit(1);}

    infp = fopen(infilename, "r");
    sorfp = fopen(sorfilename, "w");
    revfp = fopen(revfilename, "w");
    if (!infp || !sorfp || !revfp) {printf("Couldn't open a file\n"); exit(1);}

    int pos = 0;
    for (int i = 0; i < n_data / BUFFREADSIZE; i++) {
        int done = fread(inbuffer + pos, sizeof(short), BUFFREADSIZE, infp);
        pos += BUFFREADSIZE;
        //if (done != BUFFREADSIZE) printf("read %d \n", done);
    }
    fread(inbuffer + pos, sizeof(short), n_data % BUFFREADSIZE, infp);

    //put sorting function here
    quicksort(inbuffer, n_data);

    //reverse into revbuffer
    for (int i=0; i < n_data; i++) {
        revbuffer[n_data - i - 1] = inbuffer[i];
    }

    //write out
    pos = 0;
    for (int i = 0; i < n_data / BUFFREADSIZE; i++) {
        fwrite(inbuffer + pos, sizeof(short), BUFFREADSIZE, sorfp);
        fwrite(revbuffer + pos, sizeof(short), BUFFREADSIZE, revfp);
        pos += BUFFREADSIZE;
        //if (done != BUFFREADSIZE) printf("read %d \n", done);
    }
    fwrite(inbuffer + pos, sizeof(short), n_data % BUFFREADSIZE, sorfp);
    fwrite(revbuffer + pos, sizeof(short), n_data % BUFFREADSIZE, revfp);

    free(inbuffer);
    free(revbuffer);

    fclose(infp);
    fclose(sorfp);
    fclose(revfp);

    printf("done\n");
    
}
