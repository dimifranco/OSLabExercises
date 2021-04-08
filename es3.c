#include <stdio.h>

int main() {

    FILE *file = fopen("/dev/urandom", "rb");
    int arr[10] = { 0 };

    if(!file) {
        perror("Impossibile aprire il file /dev/urandom.");
        return 1;
    }

    int items = fread(arr, sizeof(int), 10, file);

    if(items != 10) {
        perror("Errore nella lettura del file.");
        return 2;
    }

    for(int i=0; i<10; i++) {
        printf("%d ", arr[i]);
    }

    fclose(file);

    return 0;
}