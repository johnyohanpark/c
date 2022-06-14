/*
 * From k&r exercise 2-2, p.42
 * Write a for loop equivalent to
 *   '''
 *      for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
 *      	s[i] = c;
 *   '''
 * without using && or ||
 */

#include <stdio.h>
int main()
{
	int i;
	char c, s[100];

	for (i=0; i<100-1; ++i) {
		c = getchar();
		if (c == '\n')
			break;
		if (c == EOF)
			break;

		s[i] = c;
	}
	return 0;
}
