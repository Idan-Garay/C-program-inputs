#include <stdio.h>
#include <math.h>

void encrypt(int e, int n, char arr[])
{
  int x;
  unsigned int m;

  for (x = 0; arr[x] != '\0'; x++)
  {
    arr[x] = ((int)pow(arr[x] - 64, e) % n) + 64;
  }

  printf("\n Encrypted: %s", arr);
}

void decrypt(int d, int n, char arr[])
{
  int x;
  unsigned int m;

  for (x = 0; arr[x] != '\0'; x++)
  {
    arr[x] = ((int)pow(arr[x] - 64, d) % n) + 64;
  }

  printf("\n Decrypted: %s", arr);
}

int main()
{
  int p, q;
  char arr[100] = "ENCRYPTION";
  p = 11;
  q = 13;
  encrypt(7, p * q, arr);
  decrypt(223, p * q, arr);
  return 0;
}