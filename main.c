#include <stdio.h>
#include <string.h>
#include "es1.h"

int main(int argc, char **argv) {

    int n = 0;
    printf("Inserire la lunghezza del vettore da utilizzare:\n");
    scanf("%d",&n);
    int arr[n];
    int *p = arr;

    printf("Inserire gli elementi dell'array:\n");
    for(int i=0; i<n; i++) {

        scanf("%d", (p+i));
    } 

    if(argc<2) {

        printf("Inserire opzione per il comando\n");
    }
    
    if(strcmp(argv[1],"-i") == 0) {

        sort(p, n, 0);
    }
    if(strcmp(argv[1],"-d") == 0) {

        sort(p, n, 1);
    }

    printf("L'array ordinato e': \n");
    for(int i=0; i<n; i++) {

        printf("%d\n", *(p+i));
    }

    return 0;
}