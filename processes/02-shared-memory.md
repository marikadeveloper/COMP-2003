Producer code

```c
item next_produced;

while(true) {
  // produce an item in next_produced
  while (((in + 1) % BUFFER_SIZE) == out) {
    // do nothing -- the buffer is full
  }

  buffer[in] = next_produced;
  in = (in + 1) % BUFFER_SIZE;
}
```

Consumer code

```c
item next_consumed;

while(true) {
  while (in == out) {
    // do nothing -- the buffer is empty
  }

  next_consumed = buffer[out];
  out = (out + 1) % BUFFER_SIZE;
  // consume the item in next_consumed
}
```
