#include <stdio.h>
void f(int*, int);

int main()
{
  int i = 6, j = 2;
  f(&i, j);
  printf("i = %d j = %d\n", i, j);

  printf("%d\n", i + j);

  return 0;
}

void f(int* p, int m) //void f (int memory address of p, 2)
{
  m = m + 8; // m = 2+8 = 10 //passed by value so it made a copy of j
  *p = *p + m; //p = 6 + 10 = 16
}
