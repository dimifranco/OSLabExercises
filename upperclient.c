#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <ctype.h>

#include "freadline.h"
#include "common.h"
#define MAXLENGTH 80

int main() {

    int sock = socket(AF_LOCAL, SOCK_STREAM, 0);
    check(sock, 1, "socket()");

    struct sockaddr_un addr = {
        .sun_family = AF_LOCAL,
        .sun_path = SOCKADDR
    };
    
    int fd = connect(sock, (struct sockaddr *)&addr, sizeof addr);
    check(fd, 2, "connect()");

    int length; 
    int read = recv(sock, &length, sizeof(length), 0);
    check(read, 3, "connessione al server interrotta");

    char *welcome = malloc(length);
    read = recv(sock, welcome, length, 0);
    check(read, 3, "connessione al server interrotta");

    fprintf(stdout, "%s\n", welcome);
    free(welcome);

    char *line = NULL;

    while(1) {
        line = freadline(stdin, line);
        if(!line)
            goto close;
        int linelen = strlen(line) + 1;
        int sent = send(sock, line, linelen, 0);
        check(sent, 4, "send()");
        int read = recv(sock, line, MAXLENGTH, 0);
        check(read, 5, "recv()");
        line[read] = 0;
        fprintf(stdout, "%s\n", line);
    }

close:
    close(fd);
    return 0;
}