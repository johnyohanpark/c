/*
 * from k&r exercise 1-23 p.34
 * Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants properly.
 * C comments do not nest.
 */
#include <stdio.h>
#define MAXLINE 1000
#define IN  1
#define OUT 0
int getLine(char buffer[], int limit);
int deleteComments(char buffer[], int lineLength);

int main()
{
	int nc;
	char buf[MAXLINE];

	while ((nc = getLine(buf, MAXLINE)) > 0) {
		deleteComments(buf, nc);
		printf("%s", buf);
	}
	return 0;
}

int getLine(char s[], int lim)
{
	int c, i;

	for (i = 0; (i<lim-1 && ((c=getchar()) != EOF) && c != '\n') ; ++i)
		s[i] = c;
	if (c == '\n')
		s[i++] = '\n';
	s[i] = '\0';

	return i;
}

int deleteComments(char line[], int len)
{
	int i, flag;

	flag = OUT;
	for (i = 0; i < len; ++i) {
		if (line[i] == '/' && line[i+1] == '/' && flag == OUT) {
			line[i] = '\0';
			break;
		}
		if ((line[i] == '"' || line[i] == '\'') && flag == OUT) {
			flag = IN;
			continue;
		}
		if ((line[i] == '"' || line[i] == '\'') && flag == IN) {
			flag = OUT;
			continue;
		}
	}
	return 0;
}
