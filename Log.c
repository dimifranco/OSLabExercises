#include <stdio.h>

int lg(int);
int power(int, int);

int main () {
  int n = 1500;
  printf("La parte intera del logaritmo in base 10 di %d e': %d\n", n,  lg(n));
  return 0;
  
}

int power(int a, int b) {
  int p = 1;
  for (int i = 0; i < b; ++i)
    p = p * a;
  return p;
}

int lg(int n) {
  int m=0, result=0;
  while( power(10,m) <= n ) {
    result = m;
    m++;
  }
  return result;
  
}
