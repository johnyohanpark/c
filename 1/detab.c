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
void insertSpaces(char s[]);
void copy(char to[], char from[], int offset);

int main()
{
    char buf[MAXLINE], res[MAXLINE];
    int n, del, end;

    end = 0;
    while ((n = getLine(buf, MAXLINE)) > 0) {       // get line, store in buf[]
        del = detab(buf, n);                        // detab the line, return new index to m
        copy(res, buf, end);                     // copy buffer to res
        end = end + n + (del * TABSTOP) - del;          // update res offset, EOF index
    }
    res[end] = '\0';
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
    line[i] = '\0';
    return i;
}

int detab(char s[], int idx)
{
    char tmp[MAXLINE];
    int del;

    --idx;                      //would be on null char now newline char
    del = 0;                    //number of tabs deleted
    for (; idx >= 0; --idx) {   //parse through line back to front
        if (s[idx] == '\t') {   //if tab found
            ++del;                      //+1 tab deleted
            copy(tmp, &s[idx+1], 0);    //copy line from found tab into temp
            insertSpaces(&s[idx]);      //insert spaces from index where tab was found
            copy(&s[idx+TABSTOP], tmp, 0);  //paste after spaces rest of line stored in tmp
        }
    }
    return del;
}

void insertSpaces(char s[])
{
    int i;

    for (i = 0; i < TABSTOP; ++i)
        s[i] = ' ';
}
void copy(char to[], char from[], int offset)
{
    int i;

    i = 0;
    while ((to[i + offset] = from[i]) != '\n')
        ++i;
    //to[i + offset] = '\0';
}