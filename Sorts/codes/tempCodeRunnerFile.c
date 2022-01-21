= 1; x <= max; x++)
  {
    count[x] += count[x - 1];
  }

  int B[size];
  memcpy(B, A, sizeof(int) * size);
  for (x = size - 1; x >= 0; x--)
  {
    A[--count[B[x]]] = B[x];
  }