#include <stdio.h>
#include <stdlib.h>

// The four arithmetic operations ... one of these functions is selected
// at runtime with a switch or a function pointer
float Plus    (float a, float b) { return a+b; }
float Minus   (float a, float b) { return a-b; }
float Multiply(float a, float b) { return a*b; }
float Divide  (float a, float b) { return a/b; }

// Solution with a switch-statement - <opCode> specifies which operation to execute
void Switch(float a, float b, char opCode)
{
   float result;

   // execute operation
   switch(opCode)
   {
      case '+' : result = Plus     (a, b); break;
      case '-' : result = Minus    (a, b); break;
      case '*' : result = Multiply (a, b); break;
      case '/' : result = Divide   (a, b); break;
   }

   printf("Switch result: %.2lf\n", result);         // display result
}

// Solution with a function pointer - <pt2Func> is a function pointer and points to
// a function which takes two floats and returns a float. The function pointer
// "specifies" which operation shall be executed.
void Switch_With_Function_Pointer(float a,float b, float(*pt2Func)(float,float))
{
   float result = pt2Func(a, b);    // call using function pointer

   printf("Switch replaced by function pointer: result");
   printf(" %.2lf\n", result);
}

int main()
{
  
  float (*fp)(float, float) = &Plus;

  float result = fp(2,5);
  printf("%.2lf\n", result);

  Switch(2,5, '+');

  Switch_With_Function_Pointer(2,5,fp);
  Switch_With_Function_Pointer(2,5, &Minus);

  return 0;


}
