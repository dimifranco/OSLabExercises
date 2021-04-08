#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) {

    int length = argc - 2;
    char *words = argv + 1;

    char *ordered = sort(words, length);
    
    for(int i=0; i<length; i++) {
        printf("%s, ", *(ordered+i));
    }

    return 0;
}

char *sort(char *words, int length) {

    for(int i=0: i<length; i++) {
        for(int j=i; j<length; j++) {
            if(strcmp(*(words+i), *(words+j)) == 1) {
                swap()...
            }
        }
    }
}