/*
Question: Write a C program that opens a text file for writing
and prompts the user for some text. The text should be appended
to the text already in the file The file name should be provided as a command-line argument.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // Create pointer to a file
  FILE *fp;
  // Char array to store user input
  char buffer[1024];

  // Check if the user provided a filename
  if (argc != 2)
  {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  // Try to open the file, if it doesn't exist, it will be created
  fp = fopen(argv[1], "a");
  // "a" for append (append to the end of the content) | "w" for write (overwrite) | "r" for read

  // Check if the file was opened successfully
  if (fp == NULL)
  {
    printf("Error opening file\n");
    return 1;
  }

  printf("Enter text to append: ");

  // fgets reads a line from the specified stream and stores it into the string pointed to by buffer
  // If NULL, there was an error reading from the users
  if (fgets(buffer, sizeof(buffer), stdin) == NULL)
  {
    printf("Error reading from user\n");
    fclose(fp);
    return 1;
  }

  // Now we write the content of buffer to the file
  fputs(buffer, fp);

  // Close the file
  fclose(fp);
  printf("Content written to %s\n", argv[1]);

  return 0;
}