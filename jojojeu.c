/*
 * File: jojojeu.c
 * Desc: Program picks a number between 1 and 100(inclusive), repeatedly prompts * user for a guess, after each round the user is told if guess was correct,
 * too small, or too big, and has 10 tries in order to win the game.
 * Author: Sayed Yoseph Sadat (914290757) <sysadat@ucdavis.edu>
 */
#include <ctype.h>

#include <stdio.h>

#include <stdlib.h>

#include <time.h>
int randomNumber(void);

int guess(void);

int currentTries(int tries);
int guessCheck(int myRandomNumber, int userGuess, int numTries);
void checkTries(int numTries);

int main(void)
{
	int numTries = 0;
	int myRandomNumber = randomNumber();
	int userGuess = guess();
	numTries++;
	while(guessCheck(myRandomNumber,userGuess,numTries) != 1)
	{
		userGuess = guess();
		numTries++;
		checkTries(numTries);
	}
	if(myRandomNumber == userGuess)
	{
		printf("You guessed correctly in %d tries!\n", numTries);
	}
	return 0;
}
int randomNumber()
{
	srand(0);
	int r = (rand() % 100) + 1;
	return r;
}
int guess() 
{
	int guess = -999;
	printf("What is your guess?\n");
	scanf("%d", &guess);
	while (getchar() != '\n');
	while(guess <= 0 || guess > 100)
	{
		
		if (guess == -999){
		   printf("Invalid input, try again.\n");
		   guess = -999;
		} else {
		printf("Guess out of bounds, try again.\n");
		guess = -999;
		}
		printf("What is your guess?\n");
		scanf("%d", &guess);
		while(getchar() != '\n');
	}
	return guess;
}
int guessCheck(int myRandomNumber, int userGuess, int numTries)
{
	if(userGuess == myRandomNumber)
	{
		return 1;
	} else if(userGuess > myRandomNumber) {
		printf("Your guess is too big! (%d tries left)\n", 
		(10 - numTries));
	} else {
		printf("Your guess is too small! (%d tries left)\n",
		 (10 - numTries));
	}
	return 0;
}
void checkTries(int numTries)
{
	if(numTries > 10)
	{
		printf("You lose!\n");
		exit(0);
	}
}

