#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>



void usage() {
    printf("Usage: program.c nFiles nLines\n");
    printf("Please introduce the number of files to be readed from and the number of lines to read\n");
}

int main (int argc, char *argv[]) {
    if(argc <= 2) {
        usage();
        exit(1);
    }
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    clock_t begin = clock();
    for (int i = 0; i < n; ++i) {
        FILE *fpr;
        fpr = fopen("plantilla.txt", "r");
        char ch;
        for (int j = 0; j < m; ++j) {
            ch = fgetc(fpr);
        }
        fclose(fpr);
    }
    clock_t end = clock();

    FILE *fp;
    fp = fopen("raw.txt", "a");
    fprintf(fp, "%ld\n", (end - begin));
    fclose(fp);
}

