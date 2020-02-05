/* 
 * File: cobalt_decay.c 
 * Desc: Reads initial mass of cobalt and a number of years, and prints the 
 * amount of this isotope that remains after each year until the end of the 
 * specified period of time. 
 * Author: Sayed Yoseph Sadat (914290757) <sysadat@ucdavis.edu>
 */
#include <math.h> 

#include <stdio.h> 

#define H 5.272 /* Constant for half-life of Cobalt-60 */
int main(void)
{
	int massCobalt, numberYears, i;
	double remainingAmount, C;

	scanf("%d %d", &massCobalt, &numberYears);

	/* Error message if an invalid is inputted */
	if ((massCobalt <= 0) || (numberYears <= 0)) {
	   printf("Invalid values\n");
	/* Return with error code 1 if invalid input detected */
	   return 1;
	}
	i = 1; 

	/* do while loop to calculate remaining amount after select years */
	do {
	   /* Computational phase for remaining amount of cobalt */
	   C = pow(M_E, -0.693);
	   remainingAmount = massCobalt * (pow(C, (i / H)));
	
	   /* Output phase */
	   printf("After %d years, the remaining amount is %.2lf grams\n",
		   i, remainingAmount);
	} while (++i <= numberYears);
	
	return 0;
}
