#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/*
  This is a simple example of using the fork() system call to create a new process.
*/

int main()
{
  pid_t pid;

  // create new process
  pid = fork();

  if (pid < 0)
  {
    perror("Fork failed");
    exit(1);
  }
  else if (pid == 0)
  {
    // child process
    printf("This is the child process. PID: %d\n", getpid());
  }
  else
  {
    // parent process
    printf("This is the parent process. PID: %d, child PID: %d\n", getpid(), pid);
  }

  // Both processes continue execution here

  return 0;
}
