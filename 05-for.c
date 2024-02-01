/** Write a program that uses a for loop to add all numbers from 1 to a requested 
 * value and display the running total with a space between each number, like so:
 * Enter the upper limit: 5
 * 1 3 6 10 15
*/

#include <stdio.h>

int main(void) {
  int limit, i;
  int sum = 0;

  do {
    // Limit should be at least one
    printf("Enter the upper limit\n");
    scanf("%d", &limit);
  } while (limit < 1);

  for (i = 1; i <= limit; i++) {
    // For each iteration add the current i to the sum
    sum += i;
    printf("%d ", sum);
  }

  printf("\n");
  return 0;
}