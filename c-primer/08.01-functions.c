/**
 * Create a function named doubleNumber that takes an integer as input, doubles 
 * its value, and returns the result. To test, in main prompt the user for the 
 * number, then display the result.
Enter an integer: 5
*Double of 5 is 10
*/

#include <stdio.h>

int doubleNumber(int num);

int main(void) {
  int number, result;

  printf("Enter number: ");
  scanf("%d", &number);

  result = doubleNumber(number);
  printf("The result is %d\n", result);

  return 0;
}

int doubleNumber(int num) {
  return num * 2;
}