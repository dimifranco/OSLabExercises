#include <stdio.h>

int main() {

  int i, key;
  int arr[] = { 16, 6, 92, 23, 57, 2, 30, 83, 61, 46 };

  for(int j=1; j<10; j++) {

    i = j-1;
    key = arr[j];
    while (i>=0 && arr[i]>key) {

      arr[i+1] = arr[i];
      i = i-1;
    }
    arr[i+1] = key;
  }

  printf("Ordered array: ");
  for(int j=0; j<10; j++) {
    printf("%d, ", arr[j]);
  }
}
