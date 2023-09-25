/*P3 image. Notice this image does not use %c when writing the pixel values
 *it uses %d with a space after each.*/
#include <stdio.h>

int main()
{
  int i = 0;

  /*Each PPM image must have a header that has the majic number of either P6 or
   *P3 with some white space after it.  The white space can be either a newline
   *or a space.  The next number represents the number of columns then the 
   *rows.  The last number is usually referred to as the maxVal. This represents 
   *the maximal value the red, green, or blue values can be. MaxVal should 
   *always be 255.*/
  fprintf(stdout, "P3\n200 200 255\n");

  for(i = 0; i < 200 * 200; i++)
  {
    /*Here we are prining the red green and blue vaules for each pixel. Notice
     *we use %d with a space after each %d.  This is very important for a P3 
     *image*/
    fprintf(stdout,"%d %d %d ",  255, 0, 0);
  }
  /*You should play around with this program changing the size and colors*/

  return 0;
}
