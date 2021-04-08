#include <stdio.h>

int main() {
	
	int i, c, n;
	n=0; 
	while ((c = getchar()) != EOF ) {

		if ( c != ' ' && c != '\n' && c != '\t' ) {
			n++;
		} else {
			for (i=0; i<n; i++) {
				printf("-");
			} 
			
			if (n>0)
				printf("\n");
			n=0;
		}

	}
	return 0;
}
