#include <stdio.h>

 int main () {
 int i, j;
 for( i=0; i<3; i++) {
    for( j=0; j<i; j++)
        printf ( " " );
    for( j=0; j<(3 - i )*2-1; j ++)
        printf ( "+" );
    printf ( "\n " );
}

 return 0;
 }