#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cs50.h>
#include "numParse.h"

/***								***
 ***	This program is for debugging the numParse library	***
 ***								***
 ***	Author: Onyxus999 (Jacob Rogers)			***/

int main(void)
{

	long test_number;

	printf("Input the number to test: ");
	test_number = GetLongLong();

	printf("The number you input is: %ld\n", test_number);
	printf("The number has %d digits.\n", count_dig(test_number));
	
	printf("They are [");
	for (int i = 0; i < count_dig(test_number); i++)
	{
		printf("%d", digital(test_number, i));
		if (  (i + 1) != count_dig(test_number) )
			printf(" ");

	}
	printf("]\n");

	printf("As chars they are [");
	for (int i = 0; i < count_dig(test_number); i++)
	{
		printf("%c", charital(test_number, i));
		if ( (i + 1) != count_dig(test_number) )
			printf(" ");
	}
	printf("]\n");

	int* int_digs = digitize(test_number);

	printf("Which digit would you like to see: ");
	int dig_index = GetInt();
	printf("The digit you've chosen is: %d\n", int_digs[dig_index]);

	char* str_digs = charitize(test_number);

	printf("The number as a string is %s\n", str_digs);

	free(int_digs);
	free(str_digs);

	return 0;
}
