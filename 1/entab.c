/*
 * k&r exercise 1-21 p.34 Write a program "entab" that replaces strings of blanks by
 * the minimum number of tabs and blanks to achieve the same spacing. Use the same
 * tab stops as for "detab". When either a tab or single blank would suffice to reach
 * a tab stop, which should be given preference?
 */

#include <stdio.h>
#define TABSTOP 4
#define MAXLINE 1000

int getline(char s[], int lim);
void copy(char to[], char from[], int offset);

int main()
{
    int len, offset;
    char buf[MAXLINE], res[MAXLINE];

    offset = 0;
    while ((len = getline(buf, MAXLINE)) > 0) {
        copy(res, buf, offset);
        offset += len;
    }
    printf("%s%d\n", res, offset);
    return 0;
}

int getline(char s[], int lim)
{
    int c, i, j, k, m, n, q, num_spc, num_tab;

    i = 0;
    while ((i<lim && ((c = getchar()) != EOF) && c != '\n')) {
        if (c != ' ') {     //if c is a non-space char, write it and continue
            s[i++] = c;
            continue;
        }                   //else, c == ' '
        for (num_spc=0; c == ' '; c = getchar()) //count until c is non_space char
            ++num_spc;
        num_tab = num_spc/TABSTOP;              //number of tabs needed integer div
        num_spc = num_spc%TABSTOP;              //remainder of spaces left
        for (k=0; k < num_tab; ++k)            
            s[i++] = '\t';
        for (m=0; m < num_spc; ++m)            
            s[i++] = ' ';
        s[i++] = c;                             //need to insert letter from last getchar() call
    }
    if (c == '\n')
        s[i++] = '\n';
    s[i] = '\0';
    return i;
}


void copy(char to[], char from[], int offset)
{
    int i;
    
    i=0;
    while((to[i + offset] = from[i]) != '\0')
        ++i;
}