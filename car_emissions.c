/* 
 * File: car_emissions.c 
 * Desc: Reads type of emissions, the number of grams per mile emitted by a 
 * vehicle and the current value of the odometer, and determines if the
 * emissions exceed the permitted level.  
 * Author: Sayed Yoseph Sadat (914290757) <sysadat@ucdavis.edu>
 */

#include <stdio.h> 

int main(void)
{
	int emissionsType, odometer; 
	double numberGramsEmittedPerMile, limitNew, limitOld, carLimit;

	scanf("%d %lf %d", &emissionsType, &numberGramsEmittedPerMile, 
		&odometer);

	/* Switch case to sort pollutant number */	
	switch (emissionsType) {
	   case 1:
	      limitNew = 3.4;
	      limitOld = 4.2;	      	      
	      break;
	   case 2:
	      limitNew = 0.31;
	      limitOld = 0.39;
	      break;
	   case 3:
	      limitNew = 0.4;
	      limitOld = 0.5;
	      break;
	   case 4:
	      limitNew = 0.25;
	      limitOld = 0.31;
	      break;	
	   default:
		/* Error message if type of emissions is incorrect */
	      printf("Unknown pollutant\n");
		/* Return with error code 1 if invalid input detected */
	      return 1; 
	}
	/* if statement to determine if car is new or old and assigns correct 
	 * value */
	if (odometer <= 50000) {
	  carLimit = limitNew; 
	} else {
	   carLimit = limitOld;
	}
	/* if loop to determine if the emitted grams is under the limit */ 	
	if (numberGramsEmittedPerMile < carLimit) {
	   printf("Emissions do not exceed permitted level of %.2lf grams/"
		   "mile\n", carLimit);
	} else { 
	   printf("Emissions exceed permitted level of %.2lf grams/"
		  "mile\n", carLimit);
	} 
	return 0;
}
