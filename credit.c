#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cs50.h>
#include "numParse.h"

/***								***
 ***	This program lets the user input a credit card number	***
 ***	and tests if it is valid. If it is, it will tell you	***
 ***	what type of credit card it is.				***
 ***								***
 ***	Author: Onyxus999 (Jacob Rogers)			***/

int main(void)
{

	long credit_number;

	printf("Input the credit card number to test: ");
	credit_number = GetLongLong();

	printf("The number you input is: %ld\n", credit_number);
	printf("The number has %d digits.\n", count_dig(credit_number));
	
	printf("They are [");
	for (int i = 0; i < count_dig(credit_number); i++)
	{
		printf("%d", digital(credit_number, i));
		if (  (i + 1) != count_dig(credit_number) )
			printf(" ");

	}
	printf("]\n");

	printf("As chars they are [");
	for (int i = 0; i < count_dig(credit_number); i++)
	{
		printf("%c", charital(credit_number, i));
		if ( (i + 1) != count_dig(credit_number) )
			printf(" ");
	}
	printf("]\n");

	int* int_digs = digitize(credit_number);

	printf("Which digit would you like to see: ");
	int dig_index = GetInt();
	printf("The digit you've chosen is: %d\n", int_digs[dig_index]);

	char* str_digs = charitize(credit_number);

	printf("The number as a string is %s\n", str_digs);

	free(int_digs);
	free(str_digs);

	return 0;
}
