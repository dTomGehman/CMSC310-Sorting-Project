#include <stdio.h>
#include <stdlib.h>

#define SEED 3
#define MAX_NAME_LEN 51
#define MAX_DATUM 10000
#define BUFFSIZE 4096

int main(int argc, char**argv){
    if (argc != 3) {
        fprintf(stderr, "usage:  datagen <n_files> <n_data>\n");
        exit(1);
    }
    int n_files = atoi(argv[1]);
    int n_data = atoi(argv[2]);

    if (n_files * n_data > 100000000) {
        fprintf(stderr, "I don't think you want to do that\n");
        exit(0);
    }

    srand(SEED);

    char filename[MAX_NAME_LEN];
    short maxdatum = MAX_DATUM;
    short buffer[BUFFSIZE];

    printf("generating %d unsorted files size %d:  ", n_files, n_data);

    for (int fileno=0; fileno<n_files; fileno++){
        sprintf(filename, "uns_%d_%03d.dat", n_data, fileno);
        FILE *fp = fopen(filename, "w");
        if (!fp){
            fprintf(stderr, "couldn't open file\n");
            exit(1);
        }
//        fprintf(fp, "%d\n", n_data);

        int ct = 0;
        for (int i = 0; i < n_data / BUFFSIZE; i++) {
            for (int j=0; j < BUFFSIZE; j++) {
                buffer[j%BUFFSIZE] = ((unsigned short) rand()) % maxdatum;
            }
            fwrite(buffer, sizeof(short), BUFFSIZE, fp);
        }
        for (int j=0; j< n_data % BUFFSIZE; j++){
            buffer[j] = ((unsigned short) rand()) % maxdatum;
//            printf("%d ", buffer[j]);
        }
        fwrite(buffer, sizeof(short), n_data % BUFFSIZE, fp);

        fclose (fp);
        printf("%d ", fileno);
    }
    printf(" done\n");
    return 0;
}
