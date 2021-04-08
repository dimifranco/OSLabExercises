#include <stdio.h>
#include "es1.h"

    void sort(int *p, int size, int order) {

        quicksort(p, 0, size-1);
        if(order == 1) {
            reverse(p, size);
        }
    }

    void quicksort(int *p, int head, int tail) {

        int r = 0;

        if(head<tail) {

            r = partition(p, head, tail);
            quicksort(p, head, r-1);
            quicksort(p, r+1, tail);
        }
    }

    int partition(int *p, int head, int tail) {

        int i = head-1;
        int x = *(p+tail);
        for(int j=head; j<=tail; j++) {
            if(*(p+j) <= x) {
                i++;
                swap(p, i, j);
            }
        }

        return i;
    }

    void swap(int *p, int i, int j) {

        int temp = *(p+i);
        *(p+i) = *(p+j);
        *(p+j) = temp;
    }
 
    void reverse(int *p, int size) {

        if(size == 1)
            *p = *p;
        if(size == 2) {
            swap(p, 0, 1);
        } else {
            swap(p, 0, size-1);
            reverse(p+1, size-2);
        }
    }
