#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>

void usage() {
    printf("Usage: program.c nFiles\n");
    printf("Please introduce the number of files to be generated\n");
}

int main (int argc, char *argv[]) {
  
    if(argc <= 1) {
        usage();
        exit(1);
    }

    int n = atoi(argv[1]);

    clock_t begin = clock();

    // Creación de ficheros encriptados y no encriptados
    for (int i = 0; i < n; ++i) {
        // Crea un fichero sin cifrar y escribe una linea, luego escribe i linias
        // Hace una copia de este fichero que sera el que se cifra
        FILE *fpr;
        char x[128];
        sprintf(x, "out/file%d.txt", i);
        fpr = fopen(x, "w+");
        fprintf(fpr, "El contenido del fichero numero %d es:\n", i);
        for (int j = 0; j < i; ++j) {
            fprintf(fpr, "Esto es un contenido aleatorio\n");
        }
        fclose(fpr);
    }

    clock_t end = clock();

    FILE *fpr = fopen("results.txt", "a");
    FILE *fp = fopen("raw.txt", "a");
    fprintf(fpr, "Test for %d files: %ld miliseconds\n", n, end);
    fprintf(fp, "%d %ld\n", n, end);
}

