/* 
 * File: grade_needed.c
 * Desc: Compute score required on the final exam to achieve a certain grade in
 * a course.
 * Author: Sayed Yoseph Sadat (914290757) <sysadat@ucdavis.edu>
 */

#include <stdio.h> /* Access to scanf()/ printf() */

int main(void)
{
	int minimumAverage, finalPercentage;
	double currentAverage, scoreRequired;
	char desiredGrade;
	double scoreRequiredDecimal, finalPercentageDecimal, 
		minimumAverageDecimal, currentAverageDecimal;

	/* Input phase for initial information to compute score */
	scanf("%c %d %lf %d",
	 &desiredGrade, &minimumAverage, &currentAverage, &finalPercentage);

	/* Output phase for initial information */
	printf("Minimum average of %d required to get %c\n",
		 minimumAverage, desiredGrade);
	printf("Your current average is %.2lf and final is worth %d%%\n", 
		 currentAverage,finalPercentage);

	finalPercentageDecimal = (finalPercentage / 100.0);
	minimumAverageDecimal = (minimumAverage / 100.0);
	currentAverageDecimal = (currentAverage / 100.0);
	
	/* Computation to find required percentage */
	scoreRequiredDecimal = (minimumAverageDecimal -
	 (1.0 - finalPercentageDecimal) * (currentAverageDecimal)) /
	 (finalPercentageDecimal);
	scoreRequired = scoreRequiredDecimal * 100;	

	/* Output phase */
	printf("You need a score of %.2lf on the final to get %c\n",
		 scoreRequired, desiredGrade); 

	/* Exit with no error */
	return 0;
}
