/*
 * File: fsm_c.c
 * Desc: Can process a sequence of characters and properly identify each data
 * item.
 * Author: Sayed Yoseph Sadat (914290757) <sysadat@ucdavis.edu>
 * (Received tutoring in CS room)
 */
#include <ctype.h>

#include <stdio.h>

/* Macros used to represent name of the states */
#define START 0
#define IDENTIFIER 1
#define DIGIT 2
#define BUILD_ID 3
#define BUILD_NUM 4
#define NUMBER 5
#define ERROR 6
#define STOP 7

/* Prototype function */
int nextState(int currentState, char myChar);

/* Contains main processing loop */
int main(void)
{
	char myCharacter;

	int currentState = START;
	do{
	if(currentState == IDENTIFIER) {
	   printf(": Identifier\n");
	   currentState = START;
      } else if(currentState == NUMBER) {
          printf(": Number\n");
          currentState = START;
      }
      scanf("%c", &myCharacter);

      currentState = nextState(currentState, myCharacter);

	if (!isblank(myCharacter) && currentState != STOP) {
	   printf("%c", myCharacter);
      }
}	
	while(currentState != STOP && currentState != ERROR);

	if(currentState == ERROR) {
  	   printf(": Invalid input\n");
	   return 1;
}
}

/* Receives an argument as the current state and inputted character and returns  * the next state */
int nextState(int currentState, char myChar)
{
	if(myChar == ';') {
	return(STOP);
	}
	if(isspace(myChar)) {
	if(currentState == BUILD_ID) {
	   return(IDENTIFIER);
	} else if(currentState == BUILD_NUM) {
	   return(NUMBER);
	}
	}
	if(currentState == START && isalpha(myChar)) {
	   return(BUILD_ID);
	} else if(currentState == START && isdigit(myChar)) {
	   return(BUILD_NUM);
	} else if(currentState == BUILD_ID) {
    	   return(BUILD_ID);
	} else if(currentState == BUILD_NUM) {
	   if(isdigit(myChar)) {
              return(BUILD_NUM);
	} else if(isalpha(myChar)) {
           return(ERROR);
	}
	}
  return 0;
}
