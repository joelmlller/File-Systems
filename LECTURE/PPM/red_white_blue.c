/*This program prints an image that has red white and blue stripes.  This is a 
 *a P6 image.*/
#include <stdio.h>

int main()
{
    fprintf(stdout, "P6\n600 400 255\n");
    int row, col;

    for(row = 0; row < 400; row++ )
    {
        for(col = 0; col < 600; col++)
        {
            if(col < 200)
            {
                fprintf(stdout, "%c%c%c", 255, 0, 0);
            }
            else
            if(col >= 200 && col< 400)
            {
                fprintf(stdout, "%c%c%c", 255, 255, 255);
            }
            else
            {
                fprintf(stdout, "%c%c%c", 0, 0, 255);
            }
        }
    }
    return 0;
}
