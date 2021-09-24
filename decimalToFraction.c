#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef char *String;
typedef long double Number;
typedef unsigned long long int HugePositiveInteger;

int getDecimalLength(Number n1)
{
  char c[50], *decimal;
  Number intpart;
  n1 = modfl(n1, &intpart);
  sprintf(c, "%.17Lg", n1); // tokenize n1
  strtok(c, ".");
  decimal = strtok(NULL, ".");

  return strlen(decimal);
}

HugePositiveInteger findGCF(HugePositiveInteger a, HugePositiveInteger b) // euclidian algo. to get the GCF of two integers
{
  HugePositiveInteger r;

  do
  {
    r = a % b;
    a = b;
    b = r;
  } while (r > 0);

  return a;
}

Number getTrailValue(Number n1, int decimalLength, int trail) // before: trailValue return integer
{
  HugePositiveInteger place, trace, x;
  place = pow(10, decimalLength - trail);

  return n1 - ((Number)((int)(n1 * place)) / place);
}

void simplifyFraction(HugePositiveInteger fraction[])
{
  HugePositiveInteger GCF = findGCF(fraction[0], fraction[1]);

  fraction[0] /= GCF;
  fraction[1] /= GCF;
}

void convertToFraction(Number num, int negative, int trail)
{
  int decimalLength = getDecimalLength(num);
  HugePositiveInteger fraction[2];
  HugePositiveInteger place = pow(10, decimalLength);

  if (trail == 0)
  {
    fraction[0] = num * place;
    fraction[1] = 1 * place;
  }
  else // For repeating decimals
  {
    // reference purpose: https://www.calculatorsoup.com/calculators/math/decimal-to-fraction-calculator.php

    HugePositiveInteger leftSide, x, place2;
    Number rightSide, numerator, trailValue;

    x = pow(10, trail);
    leftSide = x;
    trailValue = getTrailValue(num, decimalLength, trail);
    rightSide = (x * num) + trailValue; // soon to be numerator

    leftSide = leftSide - 1;
    rightSide = rightSide - num;

    decimalLength = decimalLength - trail;

    numerator = rightSide;

    if (floorl(numerator) != numerator) // if numerator is still decimal
    {
      place = pow(10, decimalLength);
      printf("%Lf/%llu d\n", (numerator), leftSide);

      fraction[0] = (numerator * place) + 1;
      fraction[1] = leftSide * place;
    }
    else
    {
      fraction[1] = numerator;
    }
  }

  simplifyFraction(fraction);
  decimalLength = getDecimalLength(num); //restore the input's decimal Length;

  printf("\nConverting decimal to Fraction...\n");
  if (negative)
  {
    printf("-%.*Lf -> -%llu/%llu\n", decimalLength, num, fraction[0], fraction[1]);
  }
  else
  {
    printf("%.*Lf -> %llu/%llu\n", decimalLength, num, fraction[0], fraction[1]);
  }
}

int getTrail(int decimalLength)
{
  int trail = 0;

  printf("Enter a trailing number: (0 for non-repeating) \n");
  scanf("%d", &trail);

  if (trail < 0)
  {
    printf("NOT natural number alert!\n");
    exit(205);
  }

  if (trail > decimalLength)
  {
    printf("Trail exceeded the length of decimal");
    exit(205);
  }
  return trail;
}

int isNegative(Number *num)
{
  int negative = 0;

  if (*num < 0)
  {
    *num *= -1;
    negative = 1;
  }
  return negative;
}

Number getInput()
{
  Number num;
  char input[30];
  char *ptr;

  printf("Note: Append '...' after input for imaginary number:\n");
  printf("\nInput a number:\n");
  scanf("%s", input);

  if (strcmp(input + (strlen(input) - 3), "...") == 0)
  {
    printf("%s is an imaginary number.\n", input);
    exit(0); // OK signal
  }

  num = strtold(input, &ptr);

  if (floorl(num) == num) // rounds up decimal to tenths integer to check non-decimals
  {
    printf("\nNon-decimal Number alert! Program Exited.");
    exit(205); // error signal
  }
  return num;
}

int main() // Start of the program
{
  Number num;
  int negative = 0;
  int trail = 0;
  int choice = 0;

  printf("\n ++ Hello, This program accepts repeating decimal through trail feature ++ \n");
  num = getInput();

  trail = getTrail(getDecimalLength(num)); // a feature for repeating decimal where 0 for non repeating
  negative = isNegative(&num);

  convertToFraction(num, negative, trail);

  return 0;
}