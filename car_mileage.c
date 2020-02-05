/* 
 * File: car_mileage.c
 * Desc: Computes the miles per gallon to determine disparity in mielage between * drivers
 * Author: Sayed Yoseph Sadat (914290757) <sysadat@ucdavis.edu>
 */

#include <stdio.h> /* Access to scanf()/printf() */

#define TANK 19.50 /* Constant gallon fuel tank */

int main(void)
{
	float odometerStart, odometerEnd;
	float distanceTraveled;
	float gasMileage;

	/* Initial input phase for odometer */
	printf("Starting odometer reading?\n");
	scanf("%f", &odometerStart);

	/* Input phase for ending odometer reading */
	printf("Ending odometer reading?\n");
	scanf("%f", &odometerEnd);

	/* Computation of total distance traveled */
	distanceTraveled = odometerEnd - odometerStart;
	printf("You traveled %.*f miles.\n", 1, distanceTraveled);
	
	/* Gas mileage computation and output phase */
	gasMileage = distanceTraveled / TANK;
	printf("With a tank of %.*f gallons, your gas mileage is %.*f MPG.\n", 2, 
	TANK, 2, gasMileage);	

	/* Exit with no error */
	return 0;
}
