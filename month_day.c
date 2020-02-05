/*
 * File: month_day.c
 * Desc: Determine the complete day based on a year and a day number.
 * Author: Sayed Yoseph Sadat (914290757) <sysadat@ucdavis.edu>
 */

#include <stdio.h>

#include <stdlib.h>

int monthDay(int year, int yearday, int *month, int *day);

int leapYear(int year);

int main (void)
{	
	int year, days, month, dayOutput, leapCheck;

	/* If user input does not correspond to year and date, print error 
	 * message and return with error code 1 */
	if (scanf("%d %d", &year, &days) != 2) {
	    printf("Invalid input\n");
	    exit(1);
	}
	/* Check if year inputted is too big for the year or if negative */
	leapCheck = leapYear(year);
	if (((leapCheck == 0 && days > 366) || days < 0) || year < 0 ) {
	    printf("Wrong date\n");
	    return 1;
	} else if (((leapCheck == 1 && days > 365) || days < 0) || year < 0 ) {
	    printf("Wrong date\n");
	    return 1;
	}

	monthDay(year, days,&month,&dayOutput);

	printf("%02d/%02d/%04d\n", month, dayOutput, year);
	return 0;
}
/* Function to check calculate month and day in the year */
int monthDay(int year, int yearday, int *month, int *day)
{
	int dayDifference = 0;
	int monthsArray [] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (leapYear(year) == 0) {
	    monthsArray[1] = 29;
	}
	for (int i = 1; i <= 12; i++) {
	    dayDifference = yearday - monthsArray[i-1];
	    if (dayDifference <= 0) {
	        *month = i;
		*day = yearday;
		break;
	    } else {
		yearday = dayDifference;
	    }
	}
	return 1;
}

/* Function to check if year inputted is a leap year */
int leapYear(int year)
{
	if (year % 4 == 0) {
	    if(year % 100 == 0){
		   if(year % 400 == 0){
			return 0;
		}
		return 1;
	}
	return 0;
	} else {
	    return 1;
	}
}
