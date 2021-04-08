#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

char *fgetline(char *line, FILE *file);
int exec_line(char *line, int cmdargc, char **argvcmd);
char **argsdup(int argc, char **args, char *line);

int main(int argc, char **argv) {

    char *cmd = argv[2];
    int cmdargc = argc - 2;
    char **argvcmd = argv + 2;
    char *filename = argv[1];
    char *line = NULL;
    int counter = 0;
    FILE *file = fopen(filename, "r");

    if(!file) {
        printf("Impossibile aprire il file\n");
        return 1;
    }

    do {
        line = fgetline(line, file);
        counter++;

        if(line) {
            if(strlen(line) == 0) 
                continue;

            int result = exec_line(line, cmdargc, argvcmd);

            if(result == -1) {
                fprintf(stderr, "file_exec: impossibile eseguire il comando per la riga %d: %s\n", counter, strerror(errno));
                return 2;
            }
        }
    } while(line != NULL);

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

int exec_line(char *line, int cmdargc, char** argvcmd) {

    if(!line) 
        return 1;

    char **newargs = argsdup(cmdargc, argvcmd, line);
    int pid = fork();
    switch(pid) {
        case -1: 
            fprintf(stderr, "file_exec: impossibile creare un processo figlio: %s \n", strerror(errno));
            free(newargs);
            return -1;
        case 0:
            if(execvp(newargs[0], newargs) == -1) {
                fprintf(stderr, "file_exec: impossibile eseguire %s: %s\n", newargs[0], strerror(errno));
                exit(1);
            }
        default:
            wait(NULL);
    }

    free(newargs);
    return 0;
}

char **argsdup(int argc, char **args, char *line) {
    char **newargs = (char **)malloc((argc + 1) * sizeof(char *));

    for(int i=0; i<argc; i++) {
        if(strcmp(args[i], "@") == 0) 
            newargs[i] = line;
        else
            newargs[i] = args[i];
        
    }

    newargs[argc] = NULL;

    return newargs;
}