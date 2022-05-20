/*
 * from k&r exercise 1-22 p.34 Write a program to "fold" long input
 * lines into two or more shorter lines after the last non-blank
 * character that occurs before the n-th column of input. Make sure
 * your program does something intelligent with very long lines,
 * and if there are no blanks or tabs before the specified column. 
 * 
 */

#include <stdio.h>
#define LIMIT 70
#define MAXLINE 1000

int getline(char line[]);
void fold(char line[], int length);

int main()
{
    int len;
    char buf[MAXLINE];
    
    while ((len = getline(buf)) > 0) {
        if (len > LIMIT)
            fold(buf, len);
        printf("%s\n", buf);
    }
}

int getline(char s[])
{
    int c,i;

    for (i=0; i<MAXLINE && ((c = getchar()) != EOF) && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void fold(char s[], int len)
{
    int i, j, d, idx;
    
    if (len <= LIMIT || s[LIMIT] == '\n')
        return;
    
    i = LIMIT;
    while (s[i] != ' ' && s[i] != '\t')
        --i;
    j = i+1;

    while (s[i] == ' ' || s[i] == '\t')
        --i;
    s[++i] = '\n';
    idx = i+1;
    while (s[j] == ' ' || s[j] == '\t')
        ++j;
    if ((d = j-i-1) > 0) {
        while ((s[++i] = s[j++]) != '\0') //copy
            ;
    }
    fold(&s[idx], len-idx);
}