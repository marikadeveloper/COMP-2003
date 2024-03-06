/*
a spinlock is a lock which causes a thread trying to acquire it to simply
wait in a loop ("spin") while repeatedly checking if the lock is available.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> // for the sleep function

// define the spinlock type
typedef int spinlock_t;

void spinlock_init(spinlock_t *lock)
{
  *lock = 0;
}

// acquire the lock
void spinlock_acquire(spinlock_t *lock)
{
  // keep spinning until the lock is available
  while (__sync_lock_test_and_set(lock, 1))
  {
    // do nothing, just keep spinning
  }
}

// release the lock
void spinlock_release(spinlock_t *lock)
{
  // release the lock
  __sync_lock_release(lock);
}

// example usage of the spinlock
// every thread will grab the lock, sleep for a while, then release the lock
void *thread_function(void *lock)
{
  // acquire the lock, spin until it's available
  spinlock_acquire((spinlock_t *)lock);
  // critical section
  printf("Thread %ld in critical section...\n", pthread_self());
  // fake work
  sleep(3);
  // release the lock
  spinlock_release((spinlock_t *)lock);
  return NULL;
}

int main(void)
{
  pthread_t thread1, thread2;
  spinlock_t lock;

  // initialize lock to 0
  spinlock_init(&lock);

  // create two threads
  pthread_create(&thread1, NULL, (void *)thread_function, &lock);
  pthread_create(&thread2, NULL, (void *)thread_function, &lock);

  // wait for both threads to finish
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  return 0;
}
