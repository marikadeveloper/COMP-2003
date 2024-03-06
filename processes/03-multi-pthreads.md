You can add multiple thread using an iterative structure:

```c
#define NUM_THREADS 10

// an array of threads to be joined upon
pthread_t threads[NUM_THREADS];

for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(&threads[i], NULL);
}
```
