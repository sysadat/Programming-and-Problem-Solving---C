/*
 * File: coin_change.c
 * Desc: Converts amount of cents into appropriate coins.
 * Author: Sayed Yoseph Sadat (914290757) <sysadat@ucdavis.edu>
 */

#include <stdio.h> /* Access to scanf()/printf() */

#define QUARTERVALUE 25 /* Constant for quarter, dime, nickel and penny values */
#define DIMEVALUE 10
#define NICKELVALUE 5	 
#define PENNYVALUE 1

int main(void)
{
	int amountCents;
	int quartersChange, dimesChange, nickelsChange, penniesChange; 

	/* Input phase */ 	
	printf("What is the amount of cents?\n");
	scanf("%d", &amountCents);	

	/* Computational and output  phase for change */
	quartersChange = amountCents / QUARTERVALUE;
	printf("Number of quarters: %d\n", quartersChange);
	amountCents = amountCents - (quartersChange * QUARTERVALUE);

	dimesChange = amountCents / DIMEVALUE;
	printf("Number of dimes: %d\n", dimesChange);
	amountCents = amountCents - (dimesChange * DIMEVALUE);

	nickelsChange = amountCents / NICKELVALUE;
	printf("Number of nickels: %d\n", nickelsChange);
	amountCents = amountCents - (nickelsChange * NICKELVALUE);

	penniesChange = amountCents / PENNYVALUE;
	printf("Number of pennies: %d\n", penniesChange);
	amountCents = amountCents - (penniesChange * PENNYVALUE);
	
	/* Exit with no error */
	return 0;
}
