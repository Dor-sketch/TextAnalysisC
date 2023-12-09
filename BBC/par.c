/* the program "par" check the if the brackets in the input are correct
    while skipping brackets inside strings and comments.
    it does it with an array functioned as a stack:
    it copies every opening bracket (outside a string or comment)
    to the top and remove the top if reads a matching closing brackets.
    it also keep track of lines with a single curly brace.*/

#include <stdio.h>

#define LIMIT 101 /*maximum line size is 100 + 1 for '\0' */
#define BALANCED 1
#define UNBALANCED 0

void check(void);

int main()
{
    check();
    return 0;
}

/* a function that check if the curent input starts a string
    if it does - return the 1st char after the string
    otherwise - return the current input */
int string_check(int c, int *line_count)
{
    int t = 0;
    if(c == '"'){ /* true if current character starts a string */
        while(t != '"'){
            t = getchar();
            if (t == '\n') {
                line_count++;
            }
            putchar(t);
        }
        c = t;
    }
    return c;
}

/* a function to find the end of a comment */
int find_end_of_comment(int *line_count)
{
    int c = getchar(), d;

    putchar(c);

    while(c != EOF) {/* getchar until end of comment and returns the 1st char afterwards */
        if(c == '\n') {
            (*line_count)++;
            printf("%s:%d: %s\n", "input.txt", *line_count, "comment");
        }
        if(c == '*') {
            d = getchar();
            putchar(d);
            if(d=='\n') {
                line_count++;
            }
            if(d == '/'){ /* end of comment */
                return d;
            } else {
                c = d;
            }
        } else {
            c = getchar();
            putchar(c);
        }
    }
    return -1;
}

/* a function that checks if the curent input starts a comment:
    if it does - returns the 1st char after the comment
    otherwise - reutrunt the current input */
int comment_start_check(int c, int *line_count)
{
    int t;
    if(c == '/'){ /*true if the current character maybe starts a comment */
        t = c;
        c = getchar();
        putchar(c);
        if(c == '*') /*true if the last character started a comment */
            c = find_end_of_comment(line_count);
        else
            c = t;
    }
    return c;
}

/* a function that copy the input stream to an array while skipping comments and strings */
int copy_clean_line(char arr[], int *line_count)
{
    int i, c;
    c = getchar();

    for(i=0; i<101 && c!='\n' && c!=EOF;) {
        putchar(c);
        c = string_check(c , line_count);
        c = comment_start_check(c, line_count);
        if(c!=' ' && c!='\t'){ /* copy if not white scaces */
            arr[i]=c;
            i++;
        }
        c = getchar();
    }

    if (c == '\n') { /* true if the current line ended */
        ++(*line_count);
        arr[i] = c;
        ++i;
        arr[i] = '\0';
    }

    if (c == EOF)
        return EOF;
    else
        return arr[i];
}

/* function tha check if the brackets in a given line are balanced */
int is_balanced(char s[])
{
    char temp[LIMIT];/*an array to store open brackets */
    int c=0, i=0, d=0;

    while(s[i]!='\n'){
        c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            temp[d] = c;
            ++d;
        }
        if (c == ')' || c == '}' || c == ']') {
            if (d>0 && (((temp[d-1]=='(') && (c==')')) || ((temp[d-1]=='[') && (c==']')) || ((temp[d-1]=='{') && (c=='}'))))/* true if the closing bracket matching the last open one*/
                --d;/* remove the last open bracket */
            else /* true if there is not an opening bracket -> unbalanced*/
                d=100;
        }
        ++i;
    }

    if(!d)
        return 1;
    else
        return 0;
}

void arr_reset(char line[LIMIT])
{
    int i;
    for(i=0; i<LIMIT; i++)
        line[i] = 0;
}

/* the function "check" tests if the brackets in a given input are balanced
    it prints every line and the test results (comments and strings are excluded from the test).
    At the the end of the input it prints the final result, including single line braces */
void check(void)
{
	char line[LIMIT];
    int result = BALANCED;
    int c = 0;
    int curly_count = 0;
    int line_count = 0;

    printf("Wellcome!\nThe program will check if the brackets in the text are correct.\n");
    printf("It will print the result after each line\nand the final resutls at the end of the text.\n");
    printf("Lines with a single curly brace will be marked as \"unbalanced\"\nbut won't effect the final result unless they're unbalance along the whole text.\n");
    printf("Please enter a text to check:\n");

    while(!(c = copy_clean_line(line, &line_count) && c!=EOF)){
        if(is_balanced(line))
            printf("\n%80s\n", "__/Balanced Line");
        else{
            printf("\n%80s\n", "__/Unbalanced Line!");
            /* TODO: Implant the line count with input file */
            /* printf("%s:%d: %s\n", "input.txt", line_count, line); */
            if(line[0]=='{' && line[1] == '\n')
                curly_count++;
            else if(line[0]=='}' && line[1]=='\n' && curly_count>0)
                curly_count--;
            else /* if not a sinlge curly brace line OR if the curly braces in the whole text are uncorrect  */
                result = UNBALANCED;
        }
        arr_reset(line);
    }

    if (result == BALANCED)
        printf("\nEND OF FILE\nThe text is balanced! (:\nEnd of Program. Thank you!\n");
    else
        printf("\nEND OF FILE\nThe text is unbalanced...\nEnd of Program. Thank you!\n");
    return;
}