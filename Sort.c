#include <stdio.h>

#define SIZE 10

void sort(int *, int);

int main() {

  int array[SIZE] = { };
  int *pa = array;
  printf("Inserire gli elementi dell'array:\n");
  for(int *p=array; p < array + SIZE; p++) {

    scanf("%d", p);
  }

  sort(pa, SIZE);

  for(int i=0; i<SIZE; i++) {

    printf("L'elemento a[%d] dell'array ordinato ha valore: %d\n", i, *pa);
    pa++;
  }

}

void sort(int *p, int size) {

  int i, key;

  for(int j=1; j<size; j++) {

    i = j-1;
    key = *(p+j);
    while(i>=0 && *(p+i)>key) {

      *(p+i+1) = *(p+i);
      i = i-1;
    }
    *(p+i+1) = key;
  }
}
