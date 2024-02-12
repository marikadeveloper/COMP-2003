/**
 * Write a function that takes three arguments: a character
and two integers. The character is to be printed. The first
integer specifies the number of times that the character
is to be printed on a line, and the second integer
specifies the number of lines that are to be printed.
*/

#include <stdio.h>

void printChars(char c, int *numChars, int *numLines);

int main() {
  char c;
  int times, lines;

  printf("Enter a character: ");
  scanf("%c", &c); 

  printf("Enter the number of chars per line: ");
  scanf("%d", &times); 

  printf("Enter the number of lines: ");
  scanf("%d", &lines); 

  printChars(c, &times, &lines);

  return 0;
}

void printChars(char c, int *numChars, int *numLines) {
  for (int i = 0; i < *numLines; i++) {
    for (int j = 0; j < *numChars; j++) {
      printf("%c", c);
    }
    printf("\n");
  }
}
