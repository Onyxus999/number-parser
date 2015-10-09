#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cs50.h>

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
	printf("\n")

	printf("The number you input is: %ld\n", credit_number);

	return 0;
}
