#include <stdio.h>

#define MAXLINE 1000

/* Function declarations */
int getaline(char line[], int maxline);
void reverseline(char in[], char out[], int len);
void copy(char to[], char from[]);

int main(void) {
	int len;
	char line[MAXLINE];
	char out[MAXLINE];

	while ((len = getaline(line, MAXLINE)) > 0) {
		reverseline(line, out, len);
		printf("%s", out);
	}
	return 0;
}

void reverseline(char line[], char out[], int len) {
		int i;

		len = len -1; /* skip '\n' */
		i = 0;
		while (len > 0) { 
			out[i++] = line[--len];
		}
		out[i++] = '\n';
		out[i] = '\0';
}


/* Stores text up to \n in line and returns its length. */
int getaline(char line[], int lim) {
	int len;
	int c;

	/* while (
	 * 		we have not reached line limit and
	 * 		it is not End Of File and
	 * 		c is not the newline char)
	 * 			read c into line
	 * if (c is newline char)
	 * 		append to s
	 * append NULL char '\0' to line
	 */
	for (len = 0; len<lim-1 && (c = getchar())!=EOF && c!='\n'; ++len) line[len] = c;

	if (c == '\n') { /* this is necessary for when input file has blank lines */
		line[len] = c;
		++len;		/* so len is at least 1 */
	}
	line[len] = '\0';	/* terminate line */

	return len;
}

/* Copies contents of to into from. */
void copy(char to[], char from[])
{
	int i = 0;

	while ((to[i] = from[i]) != '\0') {
		++i;
	}
}
