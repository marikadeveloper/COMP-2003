/**
 * a semaphore is a variable or abstract data type that is used for controlling
 * access, by multiple processes, to a common resource in a parallel programming
 * or a multi user environment.
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> // for the sleep function
#include <semaphore.h>

// create semaphore type
sem_t sem;

void *thread_function(void *arg)
{
  // decrement the semaphore and wait if it's less than 0
  sem_wait(&sem);
  // critical section
  printf("Thread %ld in critical section...\n", pthread_self());
  // fake work
  sleep(3);
  printf("Thread %ld done with critical section...\n", pthread_self());
  // increment the semaphore, allowing another thread to access
  sem_post(&sem);
  return NULL;
}

int main()
{
  pthread_t thread1, thread2, thread3;

  // init semaphore
  int threadsAllowed = 2; // 2 means that the first two processes will all be able to access the critical section
  sem_init(&sem, 0, threadsAllowed);

  pthread_create(&thread1, NULL, (void *)thread_function, NULL);
  pthread_create(&thread2, NULL, (void *)thread_function, NULL);
  pthread_create(&thread3, NULL, (void *)thread_function, NULL);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  pthread_join(thread3, NULL);

  return 0;
}