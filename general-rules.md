# C programming review

## Variables

### Best practices

- do not put initialized and non-initialized variables on the same line
- initialization creates storage location, be careful of how much memory you're using
- unsigned creation means only positive int
- most common system configs give 16/32 bits for int and 32 bits for long

### Chars

- char is used for storing characters (letters, punctuation)
  - but technically this is numbers (ie. ASCII)
  - look at the code below
  - the character typed is stored as type "c"
  - can be displayed as a decimal value (ASCII)

```c
/* 01-charcode.c displays the code number for a character */

#include <stdio.h>

int main(void) {
  char ch;

  printf("Please enter a character.\n");
  scanf("%c", &ch);
  printf("The code for %c is %d.\n", ch, ch);

  return 0;
}

// The code for C is 67
```

### Summary

- signed (positive or negative)
  - `int` - basic integer type (at least 16 bits)
  - `long` - C guarantees at least 32 bits
  - `long long` - C guarantees at least 64 bits
- unsigned integers - zero or positive values only
- characters - by default uses 1 byte per character - can be 16 or more characters
  - `char` - can be signed or unsigned
- `boolean` - true or false (C uses 1 - true, 0 - false)
- floating point
  - `float` - can represent at least 6 significant figures
  - `double` - a larger unit - at least 10 significant figures
  - `long double` - more than double

## printf, scanf

- usage example:

```c
/** 02-printf-scanf.c when to use & */

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
```

## Simple arithmetic calculations

```c
/** 03-height.c requests your name and height in inches and outputs in cm */

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
```

## While loop

```c
/** 04-while.c Write a program that asks for a starting integer and an ending integer, then
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
```

## For loop

```c
/** 05-for.c Write a program that uses a for loop to add all numbers from 1 to a requested
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
  } while (limit <= 0);

  for (i = 1; i <= limit; i++) {
    // For each iteration add the current i to the sum
    sum += i;
    printf("%d ", sum);
  }

  printf("\n");
  return 0;
}
```

## Nested for loop

```c
/** 06-for-nested.c Use nested FOR loops to produce the following pattern:
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
```

## Pointers

TODO

```c
#include <stdio.h>

void interchange(int *u, int *V);

int main(void) {
  int x = 5, y = 10;

  printf("Originally x = d and y = %d. \n", x, y);
  interchange(&x, &y); // send addresses of x and y to function
  printf("Now x = d and y = %d. \n", x, y);

  return 0;
}
void interchange(int *u, int *v) {
  int temp;
  temp = *u;
  *U = V;
  *V = temp;
}
```
