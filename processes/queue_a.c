typedef struct process
{
  int pid;
  int burst_time;
} process_t;

typedef struct queue
{
  process_t *data;
  int front;
  int rear;
  int size;
} queue_t;

// Function to initialize the queue
void init_queue(queue_t *q, int max_size)
{
  q->data = (process_t *)malloc(max_size * sizeof(process_t));
  q->front = q->rear = -1;
  q->size = max_size;
}

// Function to check if the queue is empty
int is_empty(queue_t *q)
{
  return q->front == -1;
}

// Function to check if the queue is full
int is_full(queue_t *q)
{
  return (q->rear + 1) % q->size == q->front;
}

// Function to enqueue a process
void enqueue(queue_t *q, process_t p)
{
  if (is_full(q))
  {
    // Handle overflow error
  }
  if (q->front == -1)
  {
    q->front = q->rear = 0;
  }
  else
  {
    q->rear = (q->rear + 1) % q->size;
  }
  q->data[q->rear] = p;
}

// Function to dequeue a process
process_t dequeue(queue_t *q)
{
  if (is_empty(q))
  {
    // Handle underflow error
  }
  process_t p = q->data[q->front];
  if (q->front == q->rear)
  {
    q->front = q->rear = -1;
  }
  else
  {
    q->front = (q->front + 1) % q->size;
  }
  return p;
}
