/*
 * File: simple_grep.c
 * Desc: reads entire lines from the user, and only prints back those which
 * match any of the patterns received as program arguments.
 * Author: Sayed Yoseph Sadat (914290757) <sysadat@ucdavis.edu>
 * Received tutoring in CS room
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void matchPattern(int lineNum, char *str, char *line,char *argv[]);
void collectionPattern(int argc, char *argv[], char *line, int lineNum);

int main(int argc, char *argv[])
{
  char *line = malloc(80 * sizeof(char));
  int lineNum;
  if (argc == 1){
    printf("Usage: grep [-n] word ...\n");
    return 1;
 }
 while (fgets(line, 80, stdin)) {
   lineNum++;
   collectionPattern(argc, argv, line, lineNum);
 }
}


void collectionPattern(int argc, char *argv[], char*line, int lineNum)
{
  for (int i = 1; i < argc; i++){
    char *pattern = argv[i];
    matchPattern(lineNum,pattern,line,argv);
  }

}
void matchPattern(int lineNum, char *str, char *line,char *argv[])
{
for(int j = 0; j < strlen(line); j++) {
  if(strncasecmp(str, line + j, strlen(str)) == 0) {
    /* Shows number of line if the user wishes */
     if(strcmp(argv[1], "-n") == 0) {
       printf("%d:%s", lineNum, line);
     } else {
       printf("%s", line);
     }
     break;
  }
}
}
