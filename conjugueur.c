/*
 * File: conjugueur.c
 * Desc: receives an -er French verb from the user and conjugates it
 * accordingly.
 * Author: Sayed Yoseph Sadat (914290757) <sysadat@ucdavis.edu>
 */
#include <stdio.h>
#include <string.h>

int verbEnd(char *str, int count);
void conjugate(char *str, int count);

int main (void)
{
    int count, endCheck;
    char verb[30];
    char cont;

    /* Loop to keep checking if the user wants to conjugate */
    while (1) {
	printf("Enter a French verb (-er):\n");
	scanf("%s", verb);

	count = strlen(verb);
	/* Check if verb ends in -er and if it does, conjugate it */
	endCheck = verbEnd(verb, count);
	if (endCheck == 0){
	    conjugate(verb, count);
	}

	printf("Conjugate another verb? [Yy]\n");
	scanf(" %c", &cont);

	if (cont == 'y') {
	    continue;
	} else {
	    break;
	}
}
	return 0;
}

/* Check if the verb ends in -er or not and return value */
int verbEnd(char *str, int count)
{
   if (strncmp(&str[count - 2], "er", 2) == 0) {
	return 0;
    } else {
	printf("Not a correct -er verb\n");
	return 1;
    }
}
/* Conjugate the verb accordingly */
void conjugate(char *str, int count)
{
    int i;
    char dest[30] = "";
    char phrases[6][30] = {
	"je ", "tu ", "elle/il ", "nous ", "vous ", "elles/ils "
	};

    strncpy(dest, str, count - 2);
    for (i = 0; i < 6; i++) {
	if (i == 0 || i == 2) {
	    strcat(phrases[i], dest);
	    strcat(phrases[i], "e");
	    printf("%s\n", phrases[i]);
	} else if (i == 1) {
	    strcat(phrases[i], dest);
	    strcat(phrases[i], "es");
	    printf("%s\n", phrases[i]);
	} else if (i == 3) {
	    strcat(phrases[i], dest);
	    strcat(phrases[i], "ons");
	    printf("%s\n", phrases[i]);
	} else if (i == 4) {
	    strcat(phrases[i], dest);
	    strcat(phrases[i], "ez");
	    printf("%s\n", phrases[i]);
	} else if (i == 5) {
	    strcat(phrases[i], dest);
	    strcat(phrases[i], "ent");
	    printf("%s\n", phrases[i]);
  	}
	}
}
