/*
 * from k&r exercise 2-1. Write a program to determine the ranges of "char", "short", "int", and "long"
 * variables, both signed and unsigned, by printing appropriate values from standard headers and by
 * direct computation. Harder if you compute them: determine the ranges of the various floating-point
 * types.
 */

#include <stdio.h>
#include <math.h>

int main()
{
	char a=0;
	short int short_int=2;
	int integer=2;
	long int long_int=2;
	long long result;

	int i;
	for (i=0; i<256; ++i)
		printf("%c", a++);
	printf("\n");

	i=1;
	printf("range short int\n");
	while(short_int > 0) {
		short_int *= 2;
		++i;
	}

	result = pow(2,i);
	printf("%d, %d\n", -result, result-1); 

	i=1;
	printf("range int\n");
	while(integer > 0) {
		integer *= 2;
		++i;
	}
	result = pow(2,i);
	printf("%d, %d\n", -result, result-1); 

	
	i=1;
	printf("range long int\n");
	while(long_int > 0) {
		long_int *= 2;
		++i;
	}
	result = pow(2,i);
	printf("%lld, %lld\n", -result, result-1); 

	return 0;
}
