/*************************
*Joel Miller
*If you are working with someone both names must be added
*CPSC 2311 Section 2
*jmill53@clemson.edu
*************************/


#include "src/functions.h"

int main(int argc, char* argv[])
{
//file pointers to open the files using fopen
FILE *input = fopen(argv[1], "r");
FILE *output = fopen(argv[2], "w");
    
//if the input or output is "NULL" then report an error message
   if (input == NULL || output == NULL)
   {
    printf("Unable to open file!\n");
   }

    //calls the functions
    numSentences(input, output);
    numWords(input, output);

    //closes the input and output files
    fclose(output);
    fclose(input);
      

  
    return 0;
}
