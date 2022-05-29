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
    printf("hola\n");
    if(argc <= 2) {
        usage();
        exit(1);
    }
    printf("hola\n");
    int n = atoi(argv[1]);
    int l = atoi(argv[2]);
    printf("hola\n");
    clock_t begin = clock();

    // Creación de ficheros encriptados y no encriptados
    for (int i = 0; i < n; ++i) {
        printf("ini\n");
        // Crea un fichero sin cifrar y escribe una linea, luego escribe l linias
        FILE *fpr;
        char *x;
        printf("hola\n");
        sprintf(x, "./out/file%d.txt", i);
        fpr = fopen(x, "w+");
        printf("hola\n");
        for (int j = 0; j < l; ++j) {
            fprintf(fpr, "ihbfiasbvizvfjhznvlibxvkjxnlvjdbjdhbvjbvjdhbdvjhdjhvbd\n");
        }
        printf("hola\n");
        fclose(fpr);
        printf("fin\n");
    }
    printf("hola\n");
    clock_t end = clock();

    FILE *fpr = fopen("results.txt", "a");
    FILE *fp = fopen("raw.txt", "a");
    fprintf(fpr, "Test for %d files: %ld miliseconds\n", n, end);
    fprintf(fp, "%d %ld\n", n, end);
    fclose(fpr);
    fclose(fp);
}

