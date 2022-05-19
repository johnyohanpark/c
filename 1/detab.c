/*
 * k&r exercise 1-20 p.34 
 * Write a program detab that replaces tabs in the input with the proper
 * number of blanks to space to the next tab stop. Assume a fixed set of
 * tab stops, say every n columns. Should n be a variable or a symbolic 
 * parameter? 
 */

#include <stdio.h>
#define TABSTOP 4
#define MAXLINE 1000

int getLine(char line[], int limit);
int detab(char buffer[], int index);
void copy(char to[], char from[], int offset);

int main()
{
    char buf[MAXLINE], res[MAXLINE];
    int n, m, end;

    end = 0;
    while ((n = getLine(buf, MAXLINE) > 0)) {       // get line, store in buf[]
        m = detab(buf, n);                        // detab the line, return new index to m
        copy(res, buf, end);                     // copy buffer to res
        end += m;                              // update res offset, EOF index
    }
    printf("%s%d\n", res, end);
    return 0;
}

int getLine(char line[], int lim)
{
    int c, i;

    for (i=0; i<=lim-1 && ((c = getchar())!=EOF) && c!='\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    //printf("%s", line);
    return i;
}

int detab(char s[], int idx)
{

}
void copy(char to[], char from[], int offset)
{

}