/** when to use & */

#include <stdio.h>

int main(void) {
  int age;
  float assets;
  char pet[30];

  printf("Enter your age, assets, and pet\n");

  scanf("%d %f", &age, &assets); // use &
  scanf("%s", pet); // no & for char array

  printf("%d $%.2f %s\n", age, assets, pet);

  return 0;
}