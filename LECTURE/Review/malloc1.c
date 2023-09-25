#include <stdio.h>
#include <stdlib.h>


/* 1  2  3  4
   5  6  7  8
   9  10 11 12 */

   //#define r 3
   //#define c 4


int main()
{
int x = 7;



  /*The row and column for the above 2D array*/
	long int r = 3, c = 4;
  int *arr;
  /*This dynamically allocates memory for r * c ints*/

	arr = (int *)malloc( r * c * sizeof(int));

	int i, j, count = 0;
  /*Nested for loop to loop through all */
	for (i = 0; i < r *c; i++)
  {
	   
       /*These basically do the same. If I want to address a 2 dimensional
        *array using 1D notation, I can use the following formula.
        *The row I want multiplied by the total number of columns plus the
        *row I want.*/
       arr[i] = i +1;

       /*The following statement basically says add i times c plus j to where
        *arr is pointing.  Remember arr is pointing to the first element of arr
        *This will get you to the correct element of the array.
        *Then Increment the value of i and assign it to count. */

         //*(arr + i*c + j) = ++count;
     
  }

	for (i = 0; i < r; i++)
  {
	   for (j = 0; j < c; j++)
     {
		   printf("%3d ", arr[i *c + j]);
     }
     printf("\n");
  }
  printf("\n");

  /*  free the dynamically allocated memory */
     free(arr);

return 0;
}

