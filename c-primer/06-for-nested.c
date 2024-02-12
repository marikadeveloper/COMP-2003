/** Use nested FOR loops to produce the following pattern:
$
$$
$$$
$$$$
$$$$$
$$$$$$*/

#include <stdio.h>

int main(void) {
  int i, j, treeHeight;

  do {
    printf("Enter the height of the dollar tree\n");
    scanf("%d", &treeHeight);
  } while (treeHeight < 1);

  for (i = 1; i <= treeHeight; i++) {
    // i-loop is for counting the rows
    for (j = 1; j <= i; j++) {
      // j-loop is for printing the right nr of $ for each row
      printf("$");
    }
    // Print a new line to end the current row of $
    printf("\n");
  }

  return 0;
}