// File Name: Simple_Sort.c
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MAX 200 // For maximum character

// Function to accept number of lines.
// Validate the number and returns it
int get_nlines(void)
{
// To store number of lines
int lines;
// Loops till valid number of lines entered by the user
do
{
// Accepts the number of lines
printf("\n Enter number of lines: ");
scanf("%d", &lines);
// Checks if the number of lines is between 0 and 80 then valid
if(lines >= 0 && lines <= 80)
// Come out of the loop
break;
// Otherwise invalid number of lines
else
printf("\n Invalid lines. Must between (0 - 80 inclusive).");
}while(1); // End of do - while loop
}// End of function

// Function to allocate memory to character pointer to pointer variable
// Accepts string based on number of lines
// Returns it
char **get_lines(int nlines)
{
// Loops variable
int c;
// Dynamically allocates memory for number of rows
char **arr = (char**) calloc(nlines, sizeof(char*));

// Loops till number of lines
for (c = 0; c < nlines; c++ )
// Dynamically allocates memory for each column of size MAX
arr[c] = malloc(MAX * sizeof(char));
// Loops till number of lines
for(c = 0; c < nlines; c++)
{
fflush(stdin);
printf("\n Enter Line %d string data: ", (c+1));
scanf("%[^\n]s", arr[c]);
}// End of for loop
return arr;
}// End of function

// Function to sort the lines of string
void sort_lines(char **lines, int nlines)
{
// Loops variable
int r, c;
// Dynamically allocates memory for temporary character pointer
char *temp = malloc(MAX * sizeof(char));
// Loops till number of lines
for(r = 0; r < nlines; r++)
{
// Loops till number of lines
for(c = r + 1; c < nlines; c++)
{
// Checks if the r index position string data is greater than c index position string data
if(strcmp(lines[r], lines[c]) > 0)
{
// Swapping process
strcpy(temp, lines[r]);
strcpy(lines[r], lines[c]);
strcpy(lines[c], temp);
}// End of if condition
}// End of inner for loop
}// End of outer for loop
}// End of function

// Function to print the data
void print_lines(char **lines, int nlines)
{
// Loops variable
int r;
// Loops till number of lines
for(r = 0; r < nlines; r++)
// Displays each line string
printf("\n%s", lines[r]);
}// End of function

// Function to release the memory
void free_lines(char **lines, int nlines)
{
// Loops variable
int r;
// Loops till number of lines
for(r = 0; r < nlines; r++)
// Release memory of each row
free(lines[r]);
// Release the lines
free(lines);
}// End of function

// main function definition
int main()
{
// Calls the function to accept number of lines
int lines = get_nlines();
// Calls the function to accept string based on number of lines
// Stores the return character pointer to pointer
char **array = get_lines(lines);
printf("\n Original \n");
// Calls the function to display the original data
print_lines(array, lines);
// Calls the function to sort the data
sort_lines(array, lines);
printf("\n Sorted \n");
// Calls the function to display the sorted data
print_lines(array, lines);
// Calls the function to release memory
free_lines(array, lines);
}// End of main function
