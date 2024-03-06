#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

// Define a process structure
typedef struct
{
  pid_t pid;
  int burst_time;
} Process;

// Implement a queue using a linked list (replace with your preferred data structure)
typedef struct Node
{
  Process data;
  struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

void enqueue(Process process)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = process;
  newNode->next = NULL;
  if (head == NULL)
  {
    head = tail = newNode;
  }
  else
  {
    tail->next = newNode;
    tail = newNode;
  }
}

Process dequeue()
{
  if (head == NULL)
  {
    printf("Queue is empty\n");
    exit(EXIT_FAILURE);
  }
  Process process = head->data;
  Node *temp = head;
  head = head->next;
  if (head == NULL)
  {
    tail = NULL;
  }
  free(temp);
  return process;
}

int main(int argc, char *argv[])
{
  // Check for valid input
  if (argc < 2)
  {
    printf("Usage: %s <burst_time1> <burst_time2> ...\n", argv[0]);
    return 1;
  }

  int n = argc - 1; // Number of processes
  int i;
  int burst_times[n];
  pid_t pid;

  // Read burst times from arguments
  for (i = 0; i < n; i++)
  {
    burst_times[i] = atoi(argv[i + 1]);
  }

  // Create a queue to store processes
  for (i = 0; i < n; i++)
  {
    Process process = {fork(), burst_times[i]};
    if (process.pid == -1)
    {
      fprintf(stderr, "Fork Failed");
      exit(EXIT_FAILURE);
    }
    enqueue(process);
  }

  // Scheduling loop
  while (head != NULL)
  {
    Process process = dequeue();
    // Check if process creation failed
    if (process.pid == -1)
    {
      fprintf(stderr, "Fork Failed");
      exit(EXIT_FAILURE);
    }

    pid_t pid = waitpid(process.pid, NULL, 0);
    if (pid < 0)
    {
      // Handle wait error
      fprintf(stderr, "Wait Failed");
      exit(EXIT_FAILURE);
    }
    printf("Child process PID: %d finished\n", pid);
  }

  printf("All child processes have finished\n");
  exit(EXIT_SUCCESS);

  return 0;
}
