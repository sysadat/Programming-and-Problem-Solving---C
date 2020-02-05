/*
 * File: caesar_cipher.c
 * Desc: Reads a key(shift value) and then ciphers every inputted line.
 * Author: Sayed Yoseph Sadat (914290757) <sysadat@ucdavis.edu>
 */
#include <ctype.h>

#include <stdio.h>

#include <stdlib.h>

void cipher(int key, char *c);

int main (void)
{
	int key;
	char c;

	/* Check if key is valid and prints error message with error code 
	 * if invalid */
	scanf("%d", &key);
	if (key < 0 || key > 26) {
		printf("Invalid key\n");	
		exit(1);
	}
	while (getchar() != '\n');
	while (1) {
		c = getchar();
		if (c == EOF) 
		break;
		cipher(key, &c);
	}
	return 0;
}
/* Function that receives shift key and input/output parameter and modifies 
 * it */
void cipher(int key, char *c)
{
	if (isalpha(*c)) {
		if (isupper(*c)) {
			/* Wraps alphabet around for upper case letters */
			if (*c + key > 90) {
				printf("%c", *c + key - 26);
			} else printf("%c", *c + key);
		}
		/* Wraps alphabet around for lower case letters */
		if (islower(*c)) {
			if (*c + key > 122) {
				printf("%c", *c + key - 26);
			} else printf("%c", *c + key);
		}
	}
	else printf("%c", *c);
}
