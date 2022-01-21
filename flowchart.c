#include <stdio.h>

int main()
{
  int count = 0;

  do
  {
    printf("[%d] Hello World\n", count);
    count++;
  } while (count < 10);

  return 0;
}