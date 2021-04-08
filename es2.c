#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>

char *fgetline(char *line, FILE *file);
char **firstarg(char *line);
char **secondarg(char *line);
char *getword(char *line, int *p);

int main(int argc, char **argv) {

    if(argc < 2) {
        perror("Inserire il nome di un file");
        return 1;
    }

    int pipes[2] = { };
    if(pipe(pipes) == -1) {
        perror("pipe() ");
        return 2;
    }

    FILE *file = fopen(argv[1], "r");
    char *line;
    int counter = 0;
    char **argv1;
    char **argv2;
    int second, first;

    
    while((line = fgetline(line, file)) != NULL){
        
        argv1 = firstarg(line);
        argv2 = secondarg(line);
        counter++;
        first = fork();
        switch(first) {
            case -1:
                perror("fork()");
                return 3;
            case 0:
                close(pipes[0]);
                dup2(pipes[1], 1);
                execvp(argv1[0], argv1);
                fprintf(stderr, "Errore nell'esecuzione del primo comando della riga %d", counter);
                return 4;
        }

        second = fork();
        switch(second) {
            case -1:
                perror("fork()");
                return 3;
            case 0:
                close(pipes[1]);
                dup2(pipes[0], 0);
                execvp(argv2[0], argv2);
                fprintf(stderr, "Errore nell'esecuzione del secondo comando della riga %d", counter);
                return 4;
        }
    } 

    close(pipes[0]);
    close(pipes[1]);
    waitpid(first, NULL, 0);
    waitpid(second, NULL, 0);
    return 0;
}

char *fgetline(char *line, FILE *file) {
    int size = 0;
    int read = 0;

    if(feof(file)) {
        free(line);
        return NULL;
    }

    if(line != NULL)
        size = strlen(line) + 1;

    for(char c = fgetc(file); c != '\n' && c != EOF; c = fgetc(file), ++read) {
        if(read == size) {
        size = size * 2 + 1;
        line = realloc(line, size);
        }

        line[read] = c;
    }

  line[read] = 0;

  return line;
}

char **firstarg(char *line) {

    int n = 0;
    int i = 0;
    int *p = &n;
    char **arg;

    while(line[n] != '|') {
        arg[i] = getword(line, p);
        i++;
    }

    return arg;
}

char **secondarg(char *line) {

    int n = 0;
    int i = 0;
    int *p = &n;
    char **arg;

    while(line[n] != '|') {
        getword(line, p);
    }

    getword(line, p);

    while(line[n]) {
        arg[i] = getword(line, p);
        i++;
    }

    return arg;
}

char *getword(char *line, int *p) {

    char *word;
    int i=0;
    
    while(*(p) != ' ') {
        word[i] = *p;
        i++;
        p++;
    }

    p++;
    return word;
    
}