#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main() {

    int file = open("/dev/urandom", O_RDONLY);
    int arr[10] = { 0 };

    if(file == -1) {
        perror("Errore nell'apertura del file.");
        return 1;
    }

    int bytes = read(file, arr, 10*sizeof(int));

    if(bytes != sizeof(int)*10) {
        perror("Errore nella lettura del file.");
        return 2;
    }

    for(int i=0; i<10; i++) {
        write(1, "%d ", arr[i]);
    }

    close(file);

    return 0;
}