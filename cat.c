#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char **argv) {

    if(argc < 2 || argc > 2) {
        perror("./cat.c: <filename>");
        return 1;
    }

    int pipes[2] = { };
    if(pipe(pipes) == -1) {
        perror("pipe call");
        return 2;
    }

    int fd = open(argv[1], O_RDONLY);
    if(fd == -1) {
        fprintf(stderr, "Impossibile aprire il file %s: %s", argv[1], strerror(errno));
        return 3;
    }

    int cat = fork();
    switch(cat) {
        case -1:
            perror("fork() ");
            return 4;
        case 0:
            dup2(fd, 0);
            execlp("cat", "cat", NULL);
            perror("Impossibile eseguire il comando cat");
            return 5;
        default:
            wait(NULL);
            close(fd);
    }

    return 0;
}