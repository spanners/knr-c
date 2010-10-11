#include <stdio.h>

#define IN	1 /* inside a space */
#define OUT	0 /* outside a space */

/* prints input one word per line */
int main(void)
{
	int c, state;
	state = IN;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\t' || c == '\n')
		{
			if (state == OUT)
			{
				state = IN;
				putchar('\n');
			}
		}
		else
		{
			state = OUT;
			putchar(c);
		}
	}
	return 0;
}
