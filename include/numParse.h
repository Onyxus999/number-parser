/***						***
 ***	This library includes functions		***
 ***	to parse numbers into their		***
 ***	digits.					***
 ***						***
 ***	Author: Onyxus999 (Jacob Rogers)	***/

/*
 *	This function takes an int and returns the number of digits
 */
extern int count_dig(int num);

/*
 *	This function takes an int and returns a pointer to an array of its digits
 */
extern int* digitize(int num);

/*
 *	This function takes an int and returns a c-string of its digits
 */
extern char* charitize(int num);

/*
 *	This function takes an int and an index and returns the number's ith digit
 */
extern int digital(int num, int i);

/*
 *	This function takes an int and an index and returns the number's ith digit as a char
 */
extern char charital(int num, int i);
