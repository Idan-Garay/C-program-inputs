#include <stdio.h>

void DivisionBySubtraction(int Num_1, int Num_2)
{
  if (Num_2 == 0)
  {
    printf("Cannot be divided by 2\n");
  }
  else
  {
    printf("%d divided by %d\n", Num_1, Num_2);
    int Sign = 1;
    if (Num_1 * Num_2 < 0)
      Sign = -1;
    if (Num_1 < 0)
      Num_1 = Num_1 * -1;
    if (Num_2 < 0)
      Num_2 = Num_2 * -1;
    int Quotient = 0;
    while (Num_1 >= Num_2)
    {
      Num_1 = Num_1 - Num_2;
      Quotient = Quotient + 1;
    }

    printf("The Remainder is %d\n", Num_1);
    printf("The Quotient is %d\n\n", Quotient);
  }
}

int main()
{
  DivisionBySubtraction(20, 4);
  DivisionBySubtraction(2, 3);

  return 0;
}