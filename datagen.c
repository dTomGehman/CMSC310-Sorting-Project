#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv){
    if (argc != 3) {
        fprintf(stderr, "usage:  datagen <n_files> <n_data>\n");
        exit(1);
    }
    printf("hello there\n");
    return 0;
}
