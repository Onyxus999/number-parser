#include <stdlib.h>
#include <stdio.h>
#include <math.h>
/***									***
 ***	This module defines functions to handle parsing of numbers	***
 ***		into strings and strings of digits. 			***
 ***									***
 ***	Author: Onyxus999 (Jacob Rogers)				***/

/*
 *	This function takes an int and returns the number of digits
 */
int count_dig(int num)
{
		
	int up_bound = 10;
	int num_digits = 1;

	while (1==1)
	{
		// If the number is smaller than the upper bound, return the number of digits
		if (num < up_bound) {
			return num_digits;
		}
		// If the number is greater than the upper bound, raise the upper bound by a factor of 10 and add 1 to the number of digits
		// (So e.g. 32 > 10 -> up_bound = 100, num_digits = 2 -> 32 < 100 -> return num_digits)
		else {
			up_bound *= 10;
			num_digits++;
		}
	}

}

/*
 *	This function takes an int and teturns the ith digit of it
 */
int digital(int num, int i)
{
	return ((num % (int) pow(10, i+1)) / pow(10, i));
}

/*
 *	This function takes an int and returns the ith digit as a char
 */
char charital(int num, int i)
{
	char char_dig;
	snprintf(&char_dig, sizeof(char_dig), "%d", digital(num, i));
	return char_dig;
}

/*
 *	This function takes an int and returns a c-string of its digits.	
 */
char* charitize(int num)
{

	char* str_digits = malloc(sizeof(int) * count_dig(num));

	for (int i = 0; i < count_dig(num); i++)
	{
		str_digits[i] = charital(num, i);				
	}

	return str_digits;

}

/*
 *	This function takes an int and returns a pointer to an array of its digits.
 */
int* digitize(int num)
{

	int* lst_digits = malloc(sizeof(int) * count_dig(num));

	for (int i = 0; i < count_dig(num); i++)
	{
		lst_digits[i] = digital(num, i);
	}

	return lst_digits;

}
