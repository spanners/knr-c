/*********************************************************************
Mr Dearman's code assumes that there will be at least one blank before
the 'Fold-point".  Since this assumption is unfounded, his code will
fail on the first long line.  In addition, he fails to initialize a
variable 'spaceholder' that he subsequently uses as an array index.
I hope this is a better algorithm.
-- Pilcrow
*********************************************************************/
#include <stdio.h>

#define MAXLINE 1000        /* input line max */
#define FOLDLENGTH 80          /* fold point max */

char line[MAXLINE+1];
char fold_segment[MAXLINE+1];

int getaline(void);

int main(void)
{
    int space_spot, f_move, col, lapse;
    int len; /* len is len of input line or segment still unfolded */
    int last_space;  /* index of rightmost space before fold point */

    while ((len = getaline()) > 0) {
        while (len > 0) {
            if (len > FOLDLENGTH) {  /* folding needed */
                last_space = FOLDLENGTH-1; /* fold here if no spaces */

                /* find last space (if any) before FOLDLENGTH */
                for (space_spot = FOLDLENGTH-1; space_spot > 0; space_spot--) {
                    if (line[space_spot] == ' ') {
                        last_space = space_spot;
                        break;
                    }
                }

                /* format & print segment before last_space */
                for (f_move=0; f_move <= last_space; ++f_move) {
					fold_segment[f_move] = line[f_move];
				}
                fold_segment[f_move] = '\0'; /* terminate new line */
                puts(fold_segment);               /* and output it */

                /* collapse input line to eliminate segment printed */
                for (col=0, lapse = f_move; lapse <= len; ++col, ++lapse) {
					line[col] = line[lapse];
				}

                len -= last_space; /* adjust remaining line length */
            } else {
                int l;
                for (l=0; line[l] != '\0'; l++) { /* homegrown strlen */
					; 
				}
                if (l > 0) {
					puts(line); /* short segment out */
				}
                len = 0; /* force more input */
            }
        }
    }
    return 0;
}

int getaline(void)
{
    int c, i;
    for(i = 0; i < MAXLINE && (c=getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    line[i] = '\0';
    if(c == '\n') ++i;
    return i;
}
