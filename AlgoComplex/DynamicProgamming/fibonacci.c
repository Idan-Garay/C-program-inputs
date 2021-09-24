#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibonacci(int k, int memory[])
{
  int result = 1;

  if (memory[k] != 0)
  {
    return memory[k];
  }
  else if (k > 2)
  {
    result = fibonacci(k - 1, memory) + fibonacci(k - 2, memory);
  }
  memory[k] = result;
  return result;
}


int main()
{
  int memory[1000];
  int k, x = 0;

  memset(memory, 0, 1000);
  while (x++ < 5)
  {
    printf("Enter a number: ");
    scanf("%d", &k);
    printf("%d\n", fibonacci(k, memory));
  }

  return 0;
}
