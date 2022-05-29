#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>

void usage() {
    printf("Usage: program.c nFiles nLines\n");
    printf("Please introduce the number of files to be generated and the number of lines to be written in each file\n");
}

int main (int argc, char *argv[]) {
    if(argc <= 2) {
        usage();
        exit(1);
    }
    int n = atoi(argv[1]);
    int l = atoi(argv[2]);
    clock_t begin = clock();

    // Creación de ficheros encriptados y no encriptados
    for (int i = 0; i < n; ++i) {
        // Crea un fichero sin cifrar y escribe una linea, luego escribe l linias
        FILE *fpr;
        char *x;
        sprintf(x, "./out/file%d.txt", i);
        fpr = fopen(x, "w+");
        for (int j = 0; j < l; ++j) {
            fprintf(fpr, "ihbfiasbvizvfjhznvlibxvkjxnlvjdbjdhbvjbvjdhbdvjhdjhvbd\n");
        }
        fclose(fpr);
    }
    clock_t end = clock();

    FILE *fpr = fopen("results.txt", "a");
    FILE *fp = fopen("raw.txt", "a");
    fprintf(fpr, "Test for %d files: %ld miliseconds\n", n, (end - begin));
    fprintf(fp, "%d %ld\n", n, (end - begin));
    fclose(fpr);
    fclose(fp);
}
