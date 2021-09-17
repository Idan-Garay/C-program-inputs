#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef char *String;
typedef float Deci;
void getInput(String a);
int getDecimalPlace(int decimalLength)
{
  printf("%d", decimalLength);
  return pow(10, decimalLength);
}

int getDecimalLength(String a)
{
  int x;
  int len = strlen(a);

  printf("\n");

  for (x = len - 1; x >= 0 && a[x] == '0'; x--)
  {
  }

  return x;
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

void convertToFraction(Deci a, int decimalLength)
{
  int fraction[2], GCF;
  unsigned int place = getDecimalPlace(decimalLength);
  fraction[0] = a * place;
  fraction[1] = 1 * place;
  GCF = findGCF(fraction[0], fraction[1]);

  fraction[0] /= GCF;
  fraction[1] /= GCF;

  printf("\n%.*f -> %d/%d", decimalLength, a, fraction[0], fraction[1]);
}

int main()
{
  char num[100] = "1.5186262650";
  String decimal, str;
  int ret;

  ret = strtol(num, &decimal, 10);

  Deci realVal = strtod(num, &str);
  int decimalLength = getDecimalLength(decimal);

  convertToFraction(realVal, decimalLength);

  // scanf("%s", num);
  // getInput(num);

  return 0;
}

void getInput(String a)
{
  String number, decimal;
  int negative = 0;

  number = strtok(a, ".");
  decimal = strtok(NULL, ".");

  if (number[0] == '-')
    negative = 1;

  printf("%s %s", number, decimal);
}