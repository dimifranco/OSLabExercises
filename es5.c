#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    int counter = 0;
    struct stat sb;
    
    if(argc != 3) {
        perror("Insert file name and time in seconds.");
        return 1;
    }

    if(stat(argv[1], &sb) == -1) {
        fprintf(stderr, "%s: errore nell'acceso al file %s: %s\n", argv[0], argv[1], strerror(errno));
        return 2;
    }

    time_t mtime = sb.st_mtime;
    time_t current = time(NULL);
    time_t end = time(NULL) + atoi(argv[2]);

    while(current < end) {
        if(stat(argv[1], &sb) == -1) {
            fprintf(stderr, "%s: errore nell'acceso al file %s: %s\n", argv[0], argv[1], strerror(errno));
            return 2;
        }

        if(sb.st_mtime != mtime) {
            counter++;
            mtime = sb.st_mtime;
        }
        current = time(NULL);
    }

    fprintf(stdout, "Il numero di modifiche al file %s negli scorsi %d secondi e' %d\n", argv[1], atoi(argv[2]), counter);

    return 0;
}