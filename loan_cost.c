/*
 * File: loan_cost.c
 * Desc: Computes the cost of a loan, duration in years, and an interest rate in * percent.
 * Author: Sayed Yoseph Sadat (914290757) <sysadat@ucdavis.edu>
 */

#include <math.h> /* Needed to access pow() */
#include <stdio.h> /* Access to scanf()/printf() */

int main(void)
{
	int loanAmount, durationOfTheLoan;
	double yearlyInterest, totalCostOfLoan;
	int p, n; /* Variable names for loan amount and duration of the loan,
		   * respectively */
	double r; /* Variable name for monthly loan rate */	
	
	/* Input phase for loan amount */
	printf("Loan amount (in $)?\n");
	scanf("%d", &loanAmount);

	/* Input phase for duration of loan */
	printf("Duration of the loan (in yrs)?\n");
	scanf("%d", &durationOfTheLoan);

	/* Input phase for yearly interest */
	printf("Yearly interest (in %%)?\n");
	scanf("%lf", &yearlyInterest);

	/* Computational phase */
	r = (yearlyInterest) / 1200;
	p = loanAmount;
	n = durationOfTheLoan * 12;
	totalCostOfLoan = (r * p * n) / ( 1 - (pow(1 + r,-n)));
	
	/* Output phase */
	printf("Total cost of loan: $%.2lf\n", totalCostOfLoan);

	/* Exit with no error */
	return 0;
}
