#include <stdio.h>
#define MAXBUF 1000

/* Exercise 1-19 p.31 */
void reverse(char s[]);
int getLine(char buf[], int lim);
void copy(char to[], char from[], int offset);

int main() {

    int len, curr;
    char line[MAXBUF], res[MAXBUF];     //buffer, and result buffer

    curr = 0;
    while ((len = getLine(line, MAXBUF)) > 0) { // store inp in line, return length to len
        reverse(line);              //reverse the line
        copy(res, line, curr);      //copy the reversed line into result
        curr += len;                //update current spot in result
    }
    res[curr] = '\0';
    printf("%s\n", res);
    return 0;
}

void reverse(char s[])
{
    int i, len, tmp;

    for (i = 0; s[i] != '\n'; ++i) //find length
        ;
    len = i;                     

    for (i = 0; i < len/2; ++i) {
        tmp = s[i];             // store the i-th letter (near front)
        s[i] = s[len-1-i];      // replace i-th letter len minus i-th letter (near back)
        s[len-1-i] = tmp;       // replace the near-back letter with stored letter (copy of near front letter)
    }
    s[len] = '\n';
    s[len+1] = '\0';
    //printf("%s\n", s);        // FOR DEBUGGING
    return;
}

int getLine(char buf[], int lim)
{
    int i, c;

    for (i = 0; ( i<=lim-1 && (c=getchar())!=EOF && c!='\n'); ++i)
        buf[i] = c;
    if (c == '\n') {
        buf[i] = c;
        ++i;
    }

    return i;
}

void copy(char to[], char from[], int offset)
{
    int i;

    i = 0;
    while ((to[offset+i] = from[i]) != '\0')
        ++i;
}
