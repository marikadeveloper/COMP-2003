/**
 * a mutex lock is a more sophisticated version of a spinlock
 * where the kernel can put a thread to sleep if the lock is not availables
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> // for the sleep function

// static initializer for the mutex lock
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// thread function
void *thread_function(void *arg)
{
  // acquire the lock
  pthread_mutex_lock(&lock);
  // critical section
  printf("Thread %ld in critical section...\n", pthread_self());
  // fake work
  sleep(3);
  printf("Thread %ld done with critical section...\n", pthread_self());
  // release the lock
  pthread_mutex_unlock(&lock);
  return NULL;
}

int main()
{
  pthread_t thread1, thread2;

  // create two threads
  pthread_create(&thread1, NULL, (void *)thread_function, NULL);
  pthread_create(&thread2, NULL, (void *)thread_function, NULL);

  // wait for both threads to finish
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  // destroy the lock
  pthread_mutex_destroy(&lock);

  return 0;
}