/* 
 * File: jet_accleration.c
 * Desc: Compute the accleration that a jet fighter would have to sustain given 
 * the jet's take off speed in, distance over which the catapult accelerates the * jet from rest to takeoff, and time for the fighter to be accelerated to
 * takeoff speed.
 * Author: Sayed Yoseph Sadat (914290757) <sysadat@ucdavis.edu>
 */

#include <stdio.h> /* Access to scanf()/ printf() */

int main(void)
{
	/* Variables used in conversion and computation */
	int takeoffSpeed, distanceToTakeoff;
	double jetAccelerate, jetTime, conversionSeconds, newTakeoffSpeed; 
	
	/* Input phase for takeoff speed and distance to takeoff */
	scanf("%d %d", &takeoffSpeed, &distanceToTakeoff);	

	/* Output phase for takeoff speed and distance to takeoff */
	printf("Takeoff speed is %d km/h and distance to takeoff is %d m\n",
		takeoffSpeed, distanceToTakeoff);

	/* Computation for converting km/h to m/s^2 */
	conversionSeconds = 3600.00;
	newTakeoffSpeed = (takeoffSpeed * 1000) / conversionSeconds; 

	/* Computation for caluclating jet acceleration and time to be 
	 * accelerated */
	jetAccelerate = (newTakeoffSpeed * newTakeoffSpeed) /
			(2 * distanceToTakeoff);
	jetTime = newTakeoffSpeed / jetAccelerate;

	/* Output phase */
	printf("The jet would need to accelerate at");
	printf(" %.2lf m/s^2 for %.2lf seconds\n", jetAccelerate, jetTime);	

	/* Exit with no error */
	return 0;
}
