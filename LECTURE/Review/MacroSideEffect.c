#include <stdio.h>

#define MAX(a,b) ((a) > (b) ?(a) : (b))

int main()
{
    int x = 5;
    int y = 7;

    int z = MAX(x++, y++);
    printf("x = %d, y = %d, z = %d\n", x, y, z);
    //Think of the above as 
    //z = ((x++) > (y++) ? (x++) : (y++));
    //This should make it clear what the problem here is. 
    //The smaller value is incremented once and the larger value is incremented
    //twice


    int x2 = 9;
    int y2 = 4;
    int z2 = MAX(x2++, y2++);
    //z2 = ((x2++) > (y2++) ? (x2++) : (y2++));
    printf("x2 = %d, y2 = %d, z2 = %d\n", x2, y2, z2);

    int x3 = 5;
    int y3 = 7;
    //printf("%d\n", ++y3); 

    int z3 = MAX(++x3, ++y3);
    
    //z3 = ((++x3) > (++y3) ? (++x3) : (++y3));
    printf("x3 = %d, y3 = %d, z3 = %d\n", x3, y3, z3);

    return 0;
}