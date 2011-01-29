#include <stdio.h>

#define MAXLINE 1000

/* Function declarations */
int getaline(char line[], int maxline);
void copy(char to[], char from[]);

int main(void) {
	int len;
	char temp[MAXLINE];
	char line[MAXLINE];

	while ((len = getaline(temp, MAXLINE)) > 0) {
		while (len-- >=0) { /* walk backwards through temp */
			if (temp[len] != ' ' && temp[len] != '\t' && temp[len] != '\n') {
				temp[len+1] = '\n';
				temp[len+2] = '\0';
				copy(line, temp);
				break;
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
