#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <math.h>

/*
 *	This program tests credit card numbers that the user inputs.
 *
 *	Author: Onyxus999 (Jacob Rogers)
 */


/*
 *	This function returns the number of digits in a given number
 */
int count_digits(long long num)
{
	int length_num = 0;

	// Every time the number is integer divided by 10
	// the last digit is chopped off
	// and the length var increases by 1
	for (long long i = num; i > 0; i /= 10)
		length_num++;

	return length_num;
}

/*
 *	This function will give you the ith digit of num, where i is index
 */
int digital(long long num, int index)
{
	// e.g. the 4th digit of 153256 is 
	// index = 6 - 4 = 2 (This part is so the indexing goes from left to right)
	// (153256 % 10^(2)) / 10^(1)
	// (153256 % 100) / 10
	// 56 / 10
	// 5
	index = count_digits(num) - index;
	return ((num % (long long) pow(10, index)) / pow(10, index-1));
}

/*
 *	This function returns a pointer to an array of all the digits in num
 */
int* digitize(long long num)
{

	// This creates an array with the size equal to the number of digits
	int* list_of_digits = malloc(sizeof(int) * count_digits(num));

	// This makes the ith element of the array equal to the ith digit
	// of num
	for (int i = 0; i < count_digits(num); i++)
	{
		list_of_digits[i] = digital(num, i);
	}
	
	return list_of_digits;
}


/*
 *	This function clears the screen
 */
void clear(void)
{
	// tbh, no idea how this works. Found it on Stack Exchange
	printf("\033[2J\033[1;1H");
}

/*
 *	This function helps debugging int arrays by printing out all 
 *	their elements between square brackets.
 */
void dbintstar(int* num_array, int length_of_array)
{
	printf("[");
	for (int i = 0; i < length_of_array; i++)
	{
		if (i != length_of_array-1)
			printf("%d ", num_array[i]);
		else
			printf("%d]\n", num_array[i]);
	}
}

int main(void)
{
	
	long long credit_number;
	int ccnum_length;
	int* ccnum_digits;

	clear();
	
	printf("Enter number to test: ");
	credit_number = GetLongLong(); // Get the ccn from the user,
	ccnum_length = count_digits(credit_number); // Calculate its length,
	ccnum_digits = digitize(credit_number); // Create a list of its digits

	int* list_of_products;
	int i, j, start;

	// This is to make sure that the last number calculated is the second to last digit
	if (ccnum_length % 2 == 0)
		start = 0; // if the length of the ccn is even, start from the first digit

	else
		start = 1; // if the length of the ccn is odd, start from the second digit

	list_of_products = malloc(sizeof(int) * (ccnum_length/2));
	i = 0;
	j = start; // this will iterate through the ccn starting with start

	while (i < (ccnum_length/2))
	{
		list_of_products[i] = (ccnum_digits[j] * 2); // set the ith element of the product list to double the jth element of the ccn
		i++;
		j += 2;
	}

	int total_length_of_products = 0;
	total_length_of_products = 0;
	
	// add up the lengths of all the products
	for (int i = 0; i < (ccnum_length/2); i++)
		total_length_of_products += count_digits(list_of_products[i]);

	int* list_of_product_digits = malloc(sizeof(int) * total_length_of_products);
	i = 0;
	j = 0;

	// oh boy
	// we need to get the individual digits of all of the products
	// first we loop through the total length of the products
	// but we are going to want to increment every digit,
	// not every itteration, hence the while loop
	while (i < total_length_of_products)
	{
		
		// if the current is only one digit
		// add it to the digit list and increment by 1
		if (count_digits(list_of_products[j]) == 1)
		{
			list_of_product_digits[i] = list_of_products[j];
			i++;
		}
	
		// otherwise
		else
		{
		
			// for every digit in the current product,
			// add it to the digits list and increment by 1
			for (int k = 0; k < count_digits(list_of_products[j]); k++)
			{
				list_of_product_digits[i] = digital(list_of_products[j], k);
				i++;
			}
		}

		// this sets us to the next number
		j++;
	}

	int total_sum = 0;
	

	// for every digit in the products
	for (int i = 0; i < total_length_of_products; i++)
	{
		total_sum += list_of_product_digits[i]; // add it to the total sum
	}

	// for every digit not doubled in the beginning
	for (int i = !start; i < ccnum_length; i += 2)
		total_sum += ccnum_digits[i]; // add it to the total sum

	// If the last digit of total sum is 0, it is valid
	// otherwise, it isn't
	if (digital(total_sum, count_digits(total_sum)-1) == 0)
	{
		// If the ccn is valid and its first digit is 3
		// its amex
		if (digital(credit_number, 0) == 3)
			printf("AMEX\n");

		// Else if the ccn is valid and its first digit is 4
		// its visa
		else if (digital(credit_number, 0) == 4)
			printf("VISA\n");

		// Else if the ccn is valid and its first digit is 5
		// its mastercard
		else if (digital(credit_number, 0) == 5)
			printf("MASTERCARD\n");
	
		// Else if the ccn is valid but none of the above are true
		// it is another form of valid ccn
		else
			printf("OTHER VALID\n");
	}
	else

		// if the ccn is invalid, say as much
		printf("INVALID\n");


	// This block debugs all of the lists as well as total sum

	/*
	dbintstar(ccnum_digits, ccnum_length);
	dbintstar(list_of_products, (ccnum_length/2));
	dbintstar(list_of_product_digits, total_length_of_products);
	printf("%d\n", total_sum);
	*/

	// LET MY PEOPLE GO!
	free(list_of_product_digits);
	free(ccnum_digits);
	free(list_of_products);

	return 0;
}
