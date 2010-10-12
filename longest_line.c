#include <stdio.h>
#define MAXLINE 1000
int getaline(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
	/* while (there's another line)
	 * 		if (it's longer than the previous longest)
	 * 			save it
	 * 			save its length
	 * print longest line
	 */
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];
	int i;
	char c;

	max = 0;
	while ((len = getaline(line, MAXLINE)) > 0)
	{
		if (len > max)
		 {
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0)
		printf("%s", longest);
	return 0;
}


int getaline(char s[], int lim)
{
	int c, i;

	/* while (
	 * 		we have not reached line limit
	 * 		it is not EOF
	 * 		c is not the newline char)
	 * 			read c into s
	 * if (c is newline char)
	 * 		append to s
	 * append NULL char '\0' to s
	 */
	for (i = 0; i<lim-1 && (c = getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n')	/* this is necessary for when input file has blank lines */
	{
		s[i] = c;
		++i;		/* so i is at least 1 */
	}
	s[i] = '\0';	/* terminate s */

	return i;
}

void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
