/*
 * File: simple_sort.c
 * Desc: First gets the number of lines it should read, and then prints the
 * collection of lines it read in sorted order
 * Author: Sayed Yoseph Sadat (914290757) <sysadat@ucdavis.edu>
 * Received tutoring in CS room 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getNlines(void);
char **getLines(int nlines);
void sortLines(char **lines, int nlines);
void printLines(char **lines, int nlines);
void freeLines(char **lines, int nlines);

int main(void)
{
  int lines;

  lines = getNlines();
  char **str = getLines(lines);
  sortLines(str, lines);
  printLines(str, lines);
  freeLines(str, lines);
  return 0;
}

/* Returns the numbers of lines to read and if needed, exits with message */
int getNlines(void)
{
  int lines;
  if(scanf("%d", &lines) != 1) {
    printf("Invalid input\n");
    exit(1);
  }
  if (lines < 0){
    printf("Invalid input\n");
    exit(1);
  }
  return lines;
}

/* Dynamically allocattes an array of strings and reads lines frmo the user */
char **getLines(int nlines)
{
  int i;

  char **strArray = malloc(nlines * sizeof(char*));

  if (strArray == NULL){
    printf("malloc failed\n");
    exit(1);
  }
  while (getchar() != '\n');

  for (i = 0; i < nlines; i++){
    strArray[i] = malloc(80 * sizeof(char));
    fgets(strArray[i], 80, stdin);
    if(strlen(strArray[i]) == 0){
      printf("Input error\n");
      exit(1);
    }
  }
  return strArray;
}

/* Sorts the array of string without modifying values */
void sortLines(char **lines, int nlines)
{
  int i, j;
  char temp[80];

  for (i = 0; i < nlines; i++){
    for (j = i + 1; j < nlines; j++){
      if (strcasecmp(lines[i], lines[j]) > 0){
        strcpy(temp, lines[i]);
        strcpy(lines[i], lines[j]);
        strcpy(lines[j], temp);
      }
    }
  }
}
void printLines(char **lines, int nlines)
{
  for (int i = 0; i < nlines; i++){
    printf("%s", lines[i]);
  }
}

/* Frees/deallocates the entire array of strings */
void freeLines(char **lines, int nlines)
{
  for (int i = 0; i < nlines; i++){
    free(lines[i]);
  }
  free(lines);
}
