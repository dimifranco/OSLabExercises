#include <stdio.h>

#define SIZE 10

int main() {

  int sum=0;
  int addendi[SIZE]={ };
  
  for(int *p=addendi; p<addendi+SIZE; p++) {

    printf("Inserire addendo\n");
    scanf("%d", p);
    sum += *p;
  }

  printf("La somma dei numeri inseriti e': %d",sum);
}
