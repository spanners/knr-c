#include <stdio.h>

#define MAXLINE 1000
#define TAB 2

/* Function declarations */
void detab(int maxline);

/* Prints the longest line in STDIN. */
int main(void) {
	detab(MAXLINE);
	return 0;
}

void detab(int lim) {
	int len;
	int c;
	int i;

	i = 0;
	for (len = 0; len<lim-1 && (c = getchar())!=EOF; ++len) 
		if (c == '\t') {
			while (i++ < TAB)
				putchar(' ');
			i = 0;
		}
		else
			putchar(c);
}
