/********Lab9******************
*Your name Joel Miller        *
*CPSC 2310 Spring 23          *
*UserName: jmill53            *
jmill53@clemson.edu           *
*Instructor:  Dr. Yvon Feaster*
*******************************/

#include "ppmUtil.h"

// Read image data from input file
pixel_t* read(FILE* fileIn, header_t* hData){
// Read the image header
readHeader(fileIn, hData);

// Read the pixel data
return readPixels(fileIn, *hData);
}

// Read the header data from the input file
void readHeader(FILE* fileIn, header_t* hData){
fscanf(fileIn, "%s", hData->type);
ckComment(fileIn);
fscanf(fileIn, "%u", &hData->width);
ckComment(fileIn);
fscanf(fileIn, "%u", &hData->height);
ckComment(fileIn);
fscanf(fileIn, "%u", &hData->maxVal);
ckComment(fileIn);
}

// Read pixel data from input file
pixel_t* readPixels(FILE* fileIn, header_t hData){
// Allocate memory for pixel data
pixel_t* pixelVal = allocatePixMemory(hData);


// Read pixel data from file
fread(pixelVal, sizeof(pixel_t), (hData.height*hData.width), fileIn);

return pixelVal;
}

// Write image data to output file
void write(FILE* fileOut, header_t hData, pixel_t* pData){
// Write the header to the output file
writeHeader(fileOut, hData);


// Write the pixel data to the output file
writePixels(fileOut, pData, hData);
}

// Write header data to output file
void writeHeader(FILE* fileOut, header_t hData){
fprintf(fileOut, "%s\n", hData.type);
fprintf(fileOut, "%u\n", hData.width);
fprintf(fileOut, "%u\n", hData.height);
fprintf(fileOut, "%u\n", hData.maxVal);
}

// Write pixel data to output file
void writePixels(FILE* fileOut, pixel_t* pData, header_t hData){
// Write pixel data to the output file
fwrite(pData, sizeof(pixel_t), (hData.height * hData.width), fileOut);
}

// Allocate memory for pixel data
pixel_t* allocatePixMemory(header_t hData){
return malloc(sizeof(pixel_t) * (hData.height * hData.width));
}

// Free allocated memory
void freeMemory(pixel_t* pData){
free(pData);
}

// Check for comments in PPM file
void ckComment(FILE* fileIn){
char comment;

// Read until a non-comment, non-space, non-newline character is found
do 
{
    fscanf(fileIn, "%c", &comment);

    // Skip comments
    if (comment == '#') 
{
      while (comment != '\n' && comment != EOF) 
        {
          fscanf(fileIn, "%c", &comment);
        }
    }
} while (comment == ' ' || comment == '\n');

// Put back the last read character if it is not a comment
if (comment != '#') 
{
    ungetc(comment, fileIn);
}
}