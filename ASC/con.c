/* program "con" replaced sequence of following ascii characters
    it checks if the ascii value of the character is greater by
    one than the last character, and if it finds sequence greater
    than 3 following characters replaces it with a shortened version */

#include <stdio.h>
#include <string.h>

#define MAXLINE 81

void contract(char s1[], char s2[]);

int main()
{
    char s1[MAXLINE]; /* for the original input */
    char s2[MAXLINE]; /* for the sortened version */
    int c, i;
	
    printf("Please insert a line of characters:\n");

	for (i=0; i<MAXLINE-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s1[i] = c;
	if (c == '\n') {
		s1[i] = c;
		++i;
	}
	s1[i] = '\0';
    
    contract(s1, s2);
    
    printf("s1:%s\n", s1);
    printf("s2:%s\n", s2);
    return 0;
}

/* a function that checks if an input charcer is "alpha numeric":
    if it is - returns 1
    otherwise - returns 0 */
int is_alpha_numeric(char c)
{
    if(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9'))
        return 1;
    return 0;
}

/* a function that gets a string and returns a shortened version of it -
    every following sequence of ascii characters greater than 2 will be replaced by:
    "the first character" + "-" + "the last character in the sequence" */
void contract(char s1[], char s2[])
{
    int i = 0, start_i = 0, s2_i = 0;
    
    for (i = 1; i < strlen(s1);) {
        s2[s2_i++] = s1[start_i];

        if(!is_alpha_numeric(s1[start_i])) {
            /* just copy to s2 */
            start_i++;
            i++;
            continue;
        }

        while((s1[i] - s1[i-1]) == 1 && i < strlen(s1))
            i++;

        if((i - 1) == start_i) {
            start_i = i;
            i++;
            continue;
        }

        /*  only need '-' if series is greater than 2 */
        if(i-1 - start_i > 1)
            s2[s2_i++] = '-';

        s2[s2_i++] = s1[i - 1];
        start_i = i;
        i++;
    }
    s2[s2_i++] = '\0';
}