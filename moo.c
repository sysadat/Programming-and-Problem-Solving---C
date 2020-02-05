/*
 * File: m
 c: Implementation of bulls and cow game where computer chooses a secret
 * number composed of 4 digits (from 0 to 9), all different from one another.
 * The other player  has 10 tries to guess the secret number.
 * Author: Sayed Yoseph Sadat (914290757) <sysadat@ucdavis.edu>
 * Received tutoring in CS room
 */
#include <ctype.h>

#include <stdio.h>

#include <stdlib.h>

void randomNumber(char *array);
void compare(char *guesss, char *secretNumber);
void getGuess(char *guess);
int inArray(char *guess, char *secretNumber);
int main (void)
{
  char guess[4];
  char secretNumber[4];
  int winCondition = 0;
  int numTries = 0;

  srand(0);
  randomNumber(secretNumber);

  while(numTries < 10) {
    printf("What is your guess?\n");
    getGuess(guess);
    for(int i = 0; i < 4; i++) {
      if(guess[i] == secretNumber[i]) {
        winCondition ++;
      }
    }
    if(winCondition == 4) {
      printf("You guessed correctly in %d tries!\n", numTries + 1);
      return 0;
    }
	winCondition = 0;
  compare(guess,secretNumber);
  numTries++;
  }
  printf("You lose!\n");
  return 0;
}

/* Generates random number */
void randomNumber(char *array)
{
  int digits = rand() % 10;
  array[0] = '0' + digits;
  digits = rand() % 10;
  array[1] = '0' + digits;
  digits = rand() % 10;
  array[2] = '0' + digits;
  digits = rand() % 10;
  array[3] = '0' + digits;
}

/* Comepares user guess and to the secret number */
void compare(char *guess, char *secretNumber)
{
  int numTries = 0;
  int tracker = 0;
  for (int i = 0; i < 4; i++) {
  if (guess[i] == secretNumber[i]) {
     printf("X");
     tracker++;
  }
  }
  for (int a = 0; a < 4; a++) {
    for(int b = 0; b < 4 ; b++) {
      if(guess[a] == secretNumber[b] && a != b) {
      printf("O");
      tracker++;
      }
    }
  }
  for(int i = tracker; i < 4 ; i++) {
    printf("-");
  }
  printf("\n");
  numTries++;
}

/* Get 4 guesses from the user */
void getGuess(char *guess)
{
  char a = 'a';
  int i = 0;
  while (i < 4) {
    scanf("%c", &a);
    if(isdigit(a)) {
      guess [i] = a;
    } else {
  continue;
  }
  i++;
}
while(getchar() != '\n');
}

/* Check if number in user guess is in the secret number somewhere */
int inArray(char *guess, char *secretNumber)
{
  for (int i = 0; i < 4; i++) {
    if (guess[i] == secretNumber[i]) {
      return 1;
    }
  }
  return 0;
}
