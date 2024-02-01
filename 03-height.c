/** requests your name and height in inches and outputs in cm */

#include <stdio.h>

int main(void) {
  const float inchesToCmMultiplicator = 2.54;
  char name[30];
  float heightInches, heightCm;

  printf("Enter your name\n");
  scanf("%s", name);

  do {
    // Check if height is >= 0
    printf("Enter your height in inches\n");
    scanf("%f", &heightInches);
  } while(heightInches <= 0);

  heightCm = heightInches * inchesToCmMultiplicator;

  printf("%s, you are %.2f centimeters tall.\n", name, heightCm);

  return 0;
}