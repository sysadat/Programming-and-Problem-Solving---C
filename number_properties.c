/* 
 * File: number_properties.c
 * Desc: Reads a positive number from the user, and displays its properties. 
 * Author: Sayed Yoseph Sadat (914290757) <sysadat@ucdavis.edu>
 */

#include <stdio.h> 

#include <stdlib.h>

void divisible(int dividend);

void sumOfDigits(int digits);

void prime(int value);

int prompt(void);

int main (void)
{
/* Calls the other functions so it gets user input and displays properties */
	int number = prompt();
	divisible(number);
	sumOfDigits(number);
	prime(number);
	return 0;
}

/* Function that prompts user for number and returns it, returns error code 1 if * invalid input. */
int prompt(void)
{
	int number;
	if (scanf("%d", &number) == 0 || number < 1 ) {
	   printf("Invalid input\n");
	   exit (1);
	} else {
	printf("Properties of number %d:\n", number);	  
	}
	return number;
	
}

/* Function that determines whether a number is divisible by 7, 11, or 13 */
void divisible(int dividend)
{
	if ((dividend % 7 == 0) || (dividend % 11 == 0) || (dividend % 13 == 0))	{
	   printf("- Multiple of 7, 11 or 13\n");
	} else {
	   printf("- Not a multiple of 7, 11 or 13\n");
	}
}

/* Funciton that computes sum of digits and returns if its even or not */
void sumOfDigits(int digits)
{
	int sum, num;
	sum = 0;
	num = digits;
	while (num > 0) {
	  sum += num % 10; 
	  num /= 10;
	}	
	if (sum % 2 == 0) { 
	   printf("- Sum of digits is even\n");
	} else {
	   printf("- Sum of digits is odd\n");
	}

}

/* Function that computes whether a number is a prime number or not */
void prime(int value)
{
	int i;
	for (i = 2; i <= value- 1; i++)
	   if(value % i == 0){ 
	      break;
	}
	 if (i == value){ 
	   printf("- Prime number\n");
	} else {
	   printf("- Not a prime number\n");
	}
	
}	
