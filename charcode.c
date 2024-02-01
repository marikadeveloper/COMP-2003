/* displays the code number for a character */

#include <stdio.h>

int main(void) {
  char ch;

  printf("Please enter a character.\n");
  scanf("%c", &ch);
  printf("The code for %c is %d.\n", ch, ch);

  return 0;
}

// The code for C is 67