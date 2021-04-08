#include <stdio.h>

#define SIZE 10

void selection_sort(int *, int, int);

void swap(int *, int, int);

int min_search(int *, int, int);

int main() {

  int array[SIZE] = { };
  int *pa = array;
  printf("Inserire gli elementi dell'array:\n");
  for(int *p=array; p < array + SIZE; p++) {

    scanf("%d", p);
  }

  selection_sort(pa, SIZE, 0);

  for(int i=0; i<SIZE; i++) {

    printf("L'elemento a[%d] dell'array ordinato ha valore: %d\n", i, *pa);
    pa++;
  }

}

void selection_sort(int *p, int size, int pos) {

  int i=0;

  if(pos<size) {

    i = min_search(p, pos, size);
    swap(p, i, pos);
    selection_sort(p, size, pos+1);
  }
}

int min_search(int *p, int pos, int size) {

  int min = *(p+pos);
  int min_pos = pos;
  for(int i = pos+1; i<=size; i++) {

    if(*(p+i)<min) {

      min = *(p+i);
      min_pos = i;
    }
  }
  return min_pos;
}

void swap(int *p, int i, int j) {

  int temp = *(p+i);
  *(p+i) = *(p+j);
  *(p+j) = temp;
}
