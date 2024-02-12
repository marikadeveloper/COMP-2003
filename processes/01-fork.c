#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  pid_t pid;

  // fork a child process, that means create a new child process with pid = 0
  pid = fork();

  if (pid < 0) { // error occurred
    fprintf(stderr, "Fork Failed");
    return 1;
  } else if (pid == 0) { // child process
    execlp("/bin/ls", "ls", NULL); // execute ls command (directory listing) on the child process
  } else { // parent process
    // parent will wait for the child to complete
    wait(NULL);
    printf("Child Complete\n");
  }

  return 0;
}