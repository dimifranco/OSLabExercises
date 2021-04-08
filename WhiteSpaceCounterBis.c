#include <stdio.h>

int isWhiteSpace(char);

int main() {
  int  whitespace = 0, i = 0, c;
	while ((c=getchar()) != EOF) {
		if ( isWhiteSpace(c) ) 
			whitespace++;
	}
	
	printf("Number of whitespace characters: %d\n", whitespace);
	return 0;
}

	
int isWhiteSpace( char c ) {
  return c == ' ' || c == '\t' || c == '\n';

}

