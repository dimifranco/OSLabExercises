#include <stdio.h>

int main() {
	int  spazi, tabulazioni, newline, c;
	spazi = 0; tabulazioni = 0; newline = 0;
	while ((c=getchar())!=EOF) {
		switch (c) {
			case ' ': 
			 spazi++;
			 break;
			case '\t':
			 tabulazioni++;
			 break; 
			case '\n':
			 newline++; 
			 break;
		}
	}
	
	printf("Numero di spazi: %d\nNumero di tabulazioni: %d\nNumero di newline: %d\n;", spazi, tabulazioni, newline);
	return 0;
}
