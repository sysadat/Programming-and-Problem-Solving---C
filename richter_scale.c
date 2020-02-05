/* 
 * File: richter_scale.c
 * Desc: Prints the correct characterization given an earthquake's inputed 
 * maginuted. 
 * Author: Sayed Yoseph Sadat (914290757) <sysadat@ucdavis.edu>
 */

#include <stdio.h> 

int main(void)
{
	double richterScaleNumber;
	
	scanf("%lf", &richterScaleNumber);

	/* Error message if invalid input is inputted */
	if (richterScaleNumber <= 0.0){
	   printf("Invalid magnitude\n");
	/* Return with error code 1 if invalid input is inputted */   
	   return 1;
	/* Output phase for characterization of earthquake */
	} else if ((richterScaleNumber < 5.0) && (richterScaleNumber > 0.0)){
	   printf("Little or no damage\n");
	} else if ((richterScaleNumber >= 5.0) && (richterScaleNumber < 5.5)){
	   printf("Some damage\n");
	} else if ((richterScaleNumber >= 5.5) && (richterScaleNumber < 6.5)){
	   printf("Serious damage: walls may crack or fall\n");
	} else if ((richterScaleNumber >= 6.5) && (richterScaleNumber < 7.5)){
	   printf("Disaster: houses and buildings may collapse\n"); 
	} else if ((richterScaleNumber >= 7.5)) {
	   printf("Catastrophe: most buildings destroyed\n");
	}
	return 0;
}
