#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int count;
long int max;

void printhandler(int x) {

    printf("Numeri casuali generati: %d\n", count);
    printf("Numero massimo generato: %ld\n", max);
}

int main() {

    signal(SIGINT, printhandler);

    count=0;
    max=0;
    srandom(time(NULL));
    int n;
    printf("Inserire la quantita' di numeri casuali da generare: ");
    scanf("%d", &n);
    long int *arr = (long int *)malloc(sizeof(long int) * n);

    for(int i=0; i<n; i++) {
        arr[i] = random();
        if(arr[i] >= max){
            max=arr[i];
        } 
        count++;
        sleep(5);
    }



    printf("\nL'elemento massimo generato e': %li", max);
    return 0;
}

