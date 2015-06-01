#include <stdio.h>

#define MAXLINE 1000
#define TAB2SPACE 4

/* Function declarations */
int getaline(char line[], int maxline);

int main(void) {
	int len;
	int i;
	int t;
	int spacecount;
	char line[MAXLINE];

	while ((len = getaline(line, MAXLINE)) > 0) {
		for (i = 0, spacecount = 0; i < len; ++i) {
			if (line[i] == ' ') spacecount++;
			if (line[i] != ' ') spacecount = 0;
			if (spacecount == TAB2SPACE) {
				i -= (TAB2SPACE - 1);
				len -= (TAB2SPACE - 1);
				line[i] = '\t';
				for (t=i+1; t<len; ++t) line[t] = line[t+3];
				spacecount = 0;
				line[len] = '\0';
			}
		}
		printf("%s", line);
	}
	return 0;
}

/* Stores text up to \n in line and returns its length. */
int getaline(char line[], int lim) {
	int len;
	int c;

	for (len = 0; len<lim-1 && (c = getchar())!=EOF && c!='\n'; ++len) line[len] = c;

	if (c == '\n') {
		line[len] = c;
		++len;
	}
	line[len] = '\0';

	return len;
}
