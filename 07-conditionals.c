/**
 * Write a program that reads input characters until encountering #, 
 * and prints the result up until the # at 10 characters per line:
 * 
 * Enter text
  (# to quit): thisisatestoftheprogram#doesitwork?
  thisisates
  toftheprog
  ram
*/

#include <stdio.h>

int main(void) {
  char ch;
  int count = 0;

  printf("Enter text (# to quit): ");

  // Read characters until # is found
  while ((ch = getchar()) != '#') {
    printf("%c", ch);
    count++;
    // Conditional if 10th char, print "\n"
    if (count % 10 == 0) {
      printf("\n");
    }
  }

  printf("\n");

  return 0;
}
