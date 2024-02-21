#include <stdio.h>

int main(int argc, char *argv[])
{
  // check if a file name is provided
  if (argc != 2)
  {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  // attempt to open the file
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL)
  {
    printf("Error opening file\n");
    return 1;
  }

  // read the file line by line
  char buffer[1024];
  while (fgets(buffer, sizeof(buffer), fp) != NULL)
  {
    printf("%s", buffer);
  }

  // close the file
  fclose(fp);

  return 0;
}