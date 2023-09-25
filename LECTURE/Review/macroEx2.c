#include <stdio.h>
//#define NUM 10
/*This is a function like macro. It is important when creating a function macro
 *to put () without a space after the name of the function macro.*/
/*If we try to call SWAP1 we will get an error. As long as we don't try to call 
 *SWAP1 we will not get an error. Swap1 (a,b) will act like a variable  */
#define SWAP1 (a,b) ({a ^= b; b ^= a; a ^= b;})
//This is Good
#define SWAP2(a,b) ({a ^= b; b ^= a; a ^= b;})
//This is Good
#define Square(x) ((x)*(x))
//Has a flaw
#define Square2(x) (x * x)


int main()
{
    char a = 'a', b = 'b';
    int a2 = 5, b2 = 10;
    printf("Swap 2: %d\n",SWAP2(a, b));
   // SWAP1(a2, b2);
    
    printf("a = %c b = %c\n", a, b);
    printf("a2 = %d b2 = %d\n", a2, b2);

    int y = 3;
    printf("Square(y): %d\n",Square(y));

    int x = 4; 
    printf("square2(y+x): %d\n", Square2(x+y)); // x+y   3+4*3+4 =4*3 = 12 + 3 + 4 = 19
                                                // x-y   4-3 *4-3 = -3*4 = -12 + 4 -3 = -11
    return 0;
}
