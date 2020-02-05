/* 
 * File: can_cost.c
 * Desc: Find the surface area of a can and the cost of produciton.
 * Author: Sayed Yoseph Sadat (914290757) <sysadat@ucdavis.edu>
 */

#include <math.h> /* Access to the constant PI */
#include <stdio.h> /* Access to scanf()/ printf() */

int main(void)
{
	int canQuantity;
	double radiusBases, heightCylinder, costCentimeter, surfaceArea, cost;

	/* Input phase for can information */
	scanf("%lf %lf %lf %d",
	&radiusBases, &heightCylinder, &costCentimeter, &canQuantity);

	/* Output phase for initial can information */
	printf("Radius of bases is %.2lf, height of cylinder is %.2lf\n",
		radiusBases, heightCylinder);
	printf("Cost per square centimeter is %.4lf and quantity is %d\n",
		costCentimeter, canQuantity);	
	
	/* Computation of surface area and total cost */
	surfaceArea = 2 * M_PI * (radiusBases * radiusBases) + 2 * M_PI * 
	radiusBases * heightCylinder;	
	cost = costCentimeter * surfaceArea * canQuantity;	

	/* Output phase for surface area and total cost */
	printf("Each can has a surface of %.3lf cm2 and the run will cost "
		"$%.2lf\n", surfaceArea, cost);

	/* Exit with no error */
	return 0;
}
