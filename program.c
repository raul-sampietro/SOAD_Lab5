#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
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


    for (int i = 0; i < n; ++i) {
        int pid = fork();
        if (pid == 0) { // padre
            // Parent CODE
        }
        else { // hijo

            // Crea un fichero sin cifrar y escribe una linia, luego escribe i linias
            // Hace una copia de este fichero que sera el que se cifra
            FILE *fpr;
            FILE *fprC;
            char x[128];
            char z[128];
            sprintf(x, "file%d.txt", i);
            sprintf(z, "Cfile%d.txt", i);
            fpr = fopen(x, "w+");
            fprC = fopen(z, "w+");
            fprintf(fpr, "El contenido del fichero numero %d es:\n", i);
            fprintf(fprC, "El contenido del fichero cifrado numero %d es:\n", i);
            for (int j = 0; j < i; ++j) {
                fprintf(fpr, "Esto es un contenido aleatorio\n");
                fprintf(fprC, "Esto es un contenido aleatorio\n");
            }
                
            fclose(fpr);
            fclose(fprC);
            
            // El programa muta y crea un fichero cifrado a partir del fichero que se acaba de crear
            char y[128];
            sprintf(y, "Cfile%d.txt" , i);
            execlp("vim", "vim", y, "-xs", "input_file.txt",  (char *) 0);
        }

        while(waitpid(pid, NULL, 0) > 0);
    }
}

