/** Write a program that asks for a starting integer and an ending integer, then 
 * prints all the integers from (and including) the first value up to (and including) 
 * the second value. Be sure to separate each output value by a space.*/

#include <stdio.h>

int main(void) {
  int start, end;

  do {
    // Starting number should be >= 0
    printf("Enter the starting number\n");
    scanf("%d", &start);
  } while (start < 0);

  do {
    // End number should be >= starting number
    printf("Enter the end number\n");
    scanf("%d", &end);
  } while (end < start);

  while (start <= end) {
    // Keep adding 1 to start number until you reach end
    printf("%d ", start);
    start++;
  }

  printf ("\n");
  return 0;
}