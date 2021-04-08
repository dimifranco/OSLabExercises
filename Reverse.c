#include <stdio.h>

#define SIZE 10

void reverse(int *, int);

int main() {

  int array[SIZE] = { };
  int *pa = array;
  printf("Inserire gli elementi dell'array:\n");
  for(int *p=array; p < array + SIZE; p++) {

    scanf("%d", p);
  }

  reverse(pa, SIZE);

  for(int i=0; i<SIZE; i++) {

    printf("L'elemento a[%d] dell'array invertito ha valore: %d\n", i, *pa);
    pa++;
  }
}

void reverse(int *p, int size) {

  int temp = 0;
  switch(size) {

  case 0:
    break;
  case 1:
    break;
  case 2:
    temp = *p;
    *p = *(p+1);
    *(p+1) = temp;
    break;
  default:
    temp = *p;
    *p = *(p+size-1);
    *(p+size-1) = temp;
    reverse(p+1,size-2);
    break;
  }
}
