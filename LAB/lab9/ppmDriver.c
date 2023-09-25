/********Lab9******************
*Your name Joel Miller        *
*CPSC 2310 Spring 23          *
*UserName: jmill53            *
jmill53@clemson.edu           *
*Instructor:  Dr. Yvon Feaster*
*******************************/



#include "ppmUtil.h"

int main(int argc, char **argv) {
   
    FILE *fileIn = fopen(argv[1], "rb");
    FILE *fileOut = fopen(argv[2], "wb");

    header_t hValue;

    pixel_t *pValue = read(fileIn, &hValue);

    write(fileOut, hValue, pValue);

    freeMemory(pValue);
    
    fclose(fileIn);

    fclose(fileOut);

    return 0;
}
