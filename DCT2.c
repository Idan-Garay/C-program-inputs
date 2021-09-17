#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef char *String;
typedef float Number;

int getDecimalLength(Number n1)
{
  char c[20], *decimal;
  sprintf(c, "%g", n1); // tokenize n1
  strtok(c, ".");
  decimal = strtok(NULL, ".");

  return strlen(decimal);
}

int findGCF(int a, int b)
{
  int r;

  do
  {
    r = a % b;
    a = b;
    b = r;
  } while (r > 0);

  return a;
}

float getTrailValues(Number n1, int decimalLength, int trail)
{
  unsigned int place = pow(10, decimalLength);
  int trace = pow(10, trail);
  int x = n1 * place;
  printf("length: %d, place: %u trail: %u x: %d %f sad\n", decimalLength, place, trace, x, (x % trace) / (float)(place));
  return (x % trace) / (place);
}

void simplifyFraction(int fraction[])
{
  int GCF = findGCF(fraction[0], fraction[1]);

  fraction[0] /= GCF;
  fraction[1] /= GCF;
}

void convertToFraction(Number n1, int negative, int trail)
{
  int decimalLength = getDecimalLength(n1);
  printf("%f %d heree\n", n1, decimalLength);
  int fraction[2];
  unsigned int place = pow(10, decimalLength);

  if (trail == 0)
  {

    fraction[0] = n1 * place;
    fraction[1] = 1 * place;
  }
  else
  {
    unsigned int x = pow(10, trail);
    float numerator = ((x * n1) - n1) + getTrailValues(n1, decimalLength, trail);
    unsigned int z = pow(10, decimalLength - trail);
    numerator = roundf(numerator * z) / z;
    fraction[1] = x - 1;
    if (floorf(numerator) != numerator)
    {
      place = pow(10, getDecimalLength(numerator));

      fraction[0] = numerator * place;
      fraction[1] *= place;
      printf("%d/%d \n", fraction[0], fraction[1]);
    }
    else
    {
      fraction[1] = numerator;
    }
  }

  simplifyFraction(fraction);

  if (negative)
  {
    printf("-%.*f -> -%d/%d", decimalLength, n1, fraction[0], fraction[1]);
  }
  else
  {
    printf("%.*f -> %d/%d", decimalLength, n1, fraction[0], fraction[1]);
  }
}

int main()
{
  Number num;
  int negative = 0;
  int trail = 0;
  int proceed = 0;

  while (!proceed)
  {
    printf("Input a number: ");
    scanf("%f", &num);
    if (floorf(num) == num)
    {
      if (num == 0)
      {
        printf("\nundefined");
        return 205; // error signal
      }
      printf("\nNon-decimal Number alert! Program Exited.");
      return 205; // error signal
    }
    proceed = 1;
  }

  printf("Enter a trailing number: (0 for non-repeating) \n");
  scanf("%d", &trail);

  if (num < 0)
  {
    num *= -1;
    negative = 1;
  }

  convertToFraction(num, negative, trail);

  return 0;
}