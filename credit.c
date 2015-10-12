#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cs50.h>

void clear(void)
{
	printf("\033[2J\033[1;1H");
}

int main(void)
{

	clear();
	
	printf("Enter the CC Number you'd like to test: ");
	long long credit_number = GetLongLong();

	int length_ccnum = 0;
	for (long long i = credit_number; i > 0; i /= 10)
		length_ccnum++;

	int* digitized_ccnum = malloc(sizeof(int) * length_ccnum);
	for (int i = 0; i < length_ccnum; i++)
	{
		digitized_ccnum[length_ccnum-i] = ( credit_number % (long) pow(10, i+1) ) / pow(10, i);

	}

	int* product_list = malloc(sizeof(int) * (length_ccnum/2));
	int product_index = 0;
	for (int i = length_ccnum-2; i > 0; i -= 2)
	{
		product_list[product_index] = digitized_ccnum[i]*2;
		product_index++;
	}

	int length_of_products = 0;
	for (int i = 0; i < (length_ccnum/2); i++)
	{
		for (int j = product_list[i]; j > 0; j =/ 10)
			length_of_products++;
	}

	

	free(product_list);
	free(digitized_ccnum);
	return 0;
}
