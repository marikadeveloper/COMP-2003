/**
 * Write a function that takes three arguments: a character and two integers. 
 * The character is to be printed. The first integer specifies the number of 
 * times that the character is to be printed on a line, and the second integer 
 * specifies the number of lines that are to be printed.
Enter a character: J
Enter the number of times to print the character per line: 8
Enter the number of lines: 3
JUJJJUJJ
JJJJJJJJ
JUJJJJJU
*/

#include <stdio.h>

// Function declaration
void printChar(char ch, int times, int lines);

int main(void) {
  char ch;
  int times, lines;

  printf("Enter a character: ");
  scanf("%c", &ch); 

  printf("Enter the number of chars per line: ");
  scanf("%d", &times); 

  printf("Enter the number of lines: ");
  scanf("%d", &lines); 

  printChar(ch, times, lines);

  return 0;
}

// Function definition
void printChar(char ch, int times, int lines) {
  for (int i = 0; i < lines; i++) {
    for (int j = 0; j < times; j++) {
      printf("%c", ch);
    } // inside for
    printf("\n");
  } // outside for
}