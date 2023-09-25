/*************************
*Your name Joel Miller
*CPSC 2310 002, Sp23
*Your email jmill53@clemson.edu
*************************/


#include "ppm_utils.h"

void openInputFiles(char* argv, FILE* inPut[]) {

  // Determine the number of files
  int fileNum = strcmp(argv, "average") == 0 ? TEN : NINE;

  for (int i = 0; i < fileNum; i++) 
  {
    // Generate the name of the input file
    char nameOfFile[20];

    sprintf(nameOfFile, "%s_%03d.ppm", argv, i + 1);

// Attempt to open the input file

    inPut[i] = fopen(nameOfFile, "r");

//print an error message and exit the program
    if (inPut[i] == NULL) {
      perror("FILE DID NOT OPEN!");
      exit(EXIT_FAILURE);
    }
  }
}

// Remove noise using the average of pixels
image_t* removeNoiseAverage(image_t* img[]) {
  // Initialize variables for the average color channels
      unsigned int R = 0;
      unsigned int  G = 0;
      unsigned int  B = 0;

        // Get the header of the first image in the array
  header_t bold = img[0]->header;

 // Allocate memory for the new image 
  image_t* line = allocateMemory(&bold);

  // Iterate over each pixel in the image
  for (int i = 0; i < bold.HEIGHT; i++) 
  {
    for (int j = 0; j < bold.WIDTH; j++)
     {
     

      for (int k = 0; k < TEN; k++) 
      {
        //accumulate the color channels for the current pixel
        R += img[k]->pixels[i][j].R;
        G += img[k]->pixels[i][j].G;
        B += img[k]->pixels[i][j].B;
      }
 // Compute the average color channels
      line->pixels[i][j].R = R / TEN;
      line->pixels[i][j].G = G / TEN;
      line->pixels[i][j].B = B / TEN;
    }
  }

  return line;
}

// Remove noise using the median of pixels
image_t* removeNoiseMedian(image_t* img[]) {
  // Get the header of the first image in the array

  header_t bold = img[0]->header;
  // Allocate memory 
  image_t* line = allocateMemory(&bold);
  // Initialize arrays 
  unsigned int R[NINE];
  unsigned int G[NINE];
  unsigned int B[NINE];

  // Iterate over each pixel in the image

  for (int i = 0; i < bold.HEIGHT; i++) 
  {
    for (int j = 0; j < bold.WIDTH; j++) 
    {
      for (int k = 0; k < NINE; k++) {
        R[k] = img[k]->pixels[i][j].R;
        G[k] = img[k]->pixels[i][j].G;
        B[k] = img[k]->pixels[i][j].B;
      }

      sort(R, NINE);
      sort(G, NINE);
      sort(B, NINE);

      line->pixels[i][j].R = R[NINE / 2];
      line->pixels[i][j].G = G[NINE / 2];
      line->pixels[i][j].B = B[NINE / 2];
    }
  }

  return line;
}

void sort(unsigned int* arr, int n) {

  for (int i = 0; i < n - 1; i++) 
  {
    for (int j = 0; j < n - 1 - i; j++) 
    {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}

void swap(unsigned int* a, unsigned int* b) {
  unsigned int pixtemp = *a;
  *a = *b;
  *b = pixtemp;
}


// Reads a PPM file from the given file pointer
// Returns a pointer to an image_t struct containing 
//the data read from the file
image_t* read_ppm(FILE* image_file) {
  // reads the header from the file
  header_t bold = read_header(image_file);
  // allocates memory for the image based on the header
  image_t* pic = allocateMemory(&bold);

  for (int i = 0; i < bold.HEIGHT; i++) {
for (int j = 0; j < bold.WIDTH; j++) {
  // reads each pixel and stores it in the allocated image_t struct
pic->pixels[i][j] = readPixel(image_file, pic);
}
}
// returns the pointer to the allocated image_t struct
return pic;
}

// Reads PPM file header from the given file pointer
// Returns a header_t struct containing the information read
header_t read_header(FILE* image_file) {
  header_t bold;
  // reads the magic number
  fscanf(image_file, "%s", bold.MAGIC_NUMBER);
  // reads the width
  fscanf(image_file, "%d", &bold.WIDTH);
  // reads the height
  fscanf(image_file, "%d", &bold.HEIGHT);
  // reads the max color value
  fscanf(image_file, "%d", &bold.MAX_VAL);
  // reads the newline character
  fgetc(image_file); 
// returns the header
  return bold;
}

// Reads a single pixel from the given file pointer and
// returns it as a pixel_t struct
pixel_t readPixel(FILE* in, image_t* img) {
  pixel_t pix;
  //reads the red channel
  fread(&pix.R, 1, 1, in);
  // reads the green channel
  fread(&pix.G, 1, 1, in);
  // reads the blue channel
  fread(&pix.B, 1, 1, in);
// returns the pixel
  return pix;
}

// Writes a PPM file in P6 format to the given file pointer
void write_p6(FILE* out_file, image_t* image) {
  // writes the header to the file
  write_header(out_file, image->header);

  for (int i = 0; i < image->header.HEIGHT; i++) 
  {
    for (int j = 0; j < image->header.WIDTH; j++) 
    {
      // writes the channel of the pixel to the file
      fwrite(&image->pixels[i][j].R, 1, 1, out_file);
      fwrite(&image->pixels[i][j].G, 1, 1, out_file);
      fwrite(&image->pixels[i][j].B, 1, 1, out_file);
    }
  }
}

void write_header(FILE* out_file, header_t header) 
{
  // write the magic number, height or max value to the output file
  fprintf(out_file, "%s\n", header.MAGIC_NUMBER);
  fprintf(out_file, "%d %d\n", header.WIDTH, header.HEIGHT);
  fprintf(out_file, "%d\n", header.MAX_VAL);
}

// Allocates memory for an image_t struct based on the given header_t struct
// Returns a pointer to the allocated image_t struct
image_t* allocateMemory(header_t* header) 
{
  // allocates memory for the image_t struct
  image_t* pic = (image_t*)malloc(sizeof(image_t));
  pic->header = *header;
  // allocates memory for the pixel data
  pic->pixels = (pixel_t**)malloc((header->HEIGHT * sizeof(pixel_t*)));

for (int i = 0; i < header->HEIGHT; i++) 
{
pic->pixels[i] = (pixel_t*)malloc(header->WIDTH * sizeof(pixel_t));
}
// returns the pointer to the allocated image_t struct
return pic;
}

 void freeMemory(image_t** images, int numPics) {
  // iterate over each image structure in the array
  for (int i = 0; i < numPics; i++) {
    // free the memory allocated for the first row of pixels in the image
    free(images[i]->pixels[0]);
    free(images[i]->pixels);
    free(images[i]);
  }
}

void closeInputFiles(FILE* inPut[], int numFile) {
  for (int i = 0; i < numFile; i++) {
    // if the input file pointer is not NULL, close the file 
    if (inPut[i] != NULL) {
      fclose(inPut[i]);
      inPut[i] = NULL;
    }
  }
}


void start(char* medoravg, char* img) {
    // Determine number of files based on type
    int files = strcmp(medoravg, "average") == 0 ? TEN : NINE;

    // Open input files and read images
    FILE* fileIn[files];
    openInputFiles(medoravg, fileIn);
    image_t* pics[files];
    for (int i = 0; i < files; i++) {
        pics[i] = read_ppm(fileIn[i]);
        fclose(fileIn[i]);
    }

    // Remove noise from images
    image_t* output = NULL;
    if (strcmp(medoravg, "average") == 0) {
        output = removeNoiseAverage(pics);
    } else if (strcmp(medoravg, "median") == 0) {
        output = removeNoiseMedian(pics);
    } else {
        // Error if type is invalid
        assert(strcmp(medoravg, "average") == 0 
        || strcmp(medoravg, "median") == 0);
    }

    // Open output file and write image
    FILE* fileOut = fopen(img, "w");
    assert(fileOut != NULL);
    write_p6(fileOut, output);
    fclose(fileOut);

    // Free memory and close input files
    freeMemory(pics, files);
    closeInputFiles(fileIn, files);
}
