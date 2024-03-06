#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_PROCESSES 100 // Adjust as needed

// FIFO queue structure
typedef struct
{
  pid_t pids[MAX_PROCESSES];
  int front, rear;
} FIFOQueue;

void enqueue(FIFOQueue *queue, pid_t pid)
{
  if ((queue->rear + 1) % MAX_PROCESSES == queue->front)
  {
    printf("Queue overflow\n");
    return;
  }
  queue->pids[queue->rear] = pid;
  queue->rear = (queue->rear + 1) % MAX_PROCESSES;
}

pid_t dequeue(FIFOQueue *queue)
{
  if (queue->front == queue->rear)
  {
    printf("Queue underflow\n");
    return -1;
  }
  pid_t pid = queue->pids[queue->front];
  queue->front = (queue->front + 1) % MAX_PROCESSES;
  return pid;
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

  FIFOQueue queue;
  queue.front = queue.rear = 0;

  // Create child processes and add them to the queue
  for (int i = 0; i < n; i++)
  {
    pid_t pid = fork();
    if (pid == -1)
    {
      fprintf(stderr, "Fork Failed");
      exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
      // Child process
      printf("Child process PID: %d, burst time: %d\n", getpid(), burst_times[i]);
      sleep(burst_times[i]);
      exit(EXIT_SUCCESS);
    }
    else
    {
      enqueue(&queue, pid);
    }
  }

  // Wait for all processes in the queue to finish
  while (queue.front != queue.rear)
  {
    pid_t pid = dequeue(&queue);
    waitpid(pid, NULL, 0);
    printf("Child process PID: %d finished\n", pid);
  }

  printf("All child processes have finished\n");
  exit(EXIT_SUCCESS);

  return 0;
}
