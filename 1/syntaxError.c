/*
 * from k&r exercise 1-24 p.34 Write a program to check a C program for rudimentary
 * syntax errors like unbalanced parentheses, brackets, and braces. Don't forget about
 * quotes, both single and double, escape sequences, and comments.
 */

#include <stdio.h>
#define MAXLINE 1000
#define TRUE  1
#define FALSE 0
int paren=0, bracket=0, brace=0, inDQ=FALSE, inQ=FALSE;

void checkSyntax(char buffer[], int length);
int getLine(char buffer[], int limit);

int main()
{
	char buf[MAXLINE];
	int len;

	while ((len = getLine(buf, MAXLINE)) > 0) {
		checkSyntax(buf, len);
	}
	return 0;
}

void checkSyntax(char line[], int len)
{
	int i;
	extern int paren, bracket, brace, inDQ, inQ;
	for (i = 0; i < len; ++i) {
		if (line[i] == '"' && !inDQ)
			inDQ = TRUE;
		else if (line[i] == '"' && inDQ)
			inDQ = FALSE;
		else if (line[i] == '\'' && !inQ)
			inQ = TRUE;
		else if (line[i] == '\'' && inQ)
			inQ = FALSE;				
		
		if (line[i] == '(')
			paren++;
		else if (line[i] == ')')
			paren--;
		else if (line[i] == '[')
			bracket++;
		else if (line[i] == ']')
			bracket--;
		else if (line[i] == '{')
			brace++;
		else if (line[i] == '}')
			brace--;
	}

}

int getLine(char line[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n')
		line[i++] = c;
	line[i] = '\0';

	return i;
}
