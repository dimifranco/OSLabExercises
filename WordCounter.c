#include <stdio.h> 

int main() {
	int c, n, inizio_parola;
	n = 0; inizio_parola = 0; 
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t' ) {
			if (inizio_parola) {
				n++;
				inizio_parola = 0;
			}
		} else 
			inizio_parola = 1; 
	}
	if (inizio_parola) 
	 n++;

	printf("Number of words : %d ", n);
	return 0;
}
