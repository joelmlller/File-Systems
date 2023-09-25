/*************************
*Joel Miller
*If you are working with someone both names must be added
*CPSC 2311 Section 2
*jmill53@clemson.edu
*************************/

#include "functions.h"



void numSentences(FILE* in, FILE* out)
{
    char line[1000];
    int sentence = 0;
    int punc = 0;

    // While loop to open the input file and read in lines of text
    while (fgets(line, sizeof(line), in) != NULL) {
        // Iterate through each character in the line
        for (int i = 0; i < strlen(line); i++) 
        {
            // Check if the character is a period, exclamation point, or question mark
            if (line[i] == '.' || line[i] == '!' || line[i] == '?') 
            {
                punc++;

                // Check if this is the first punctuation mark in a row
                if (punc < 2) 
                {
                    sentence++;
                }
            } 
            else 
            {
                punc = 0;
            }
        }
    }
    
    // Print the total number of sentences to the output file
    fprintf(out, "Total number of sentences:%d\n", sentence);
}


void numWords(FILE* in, FILE* out)
{
    int words = 0;
    char c;

    // Rewind the input file to the beginning
      fseek(in, 0, SEEK_SET);
    // Iterate through each character in the input file
    while ((c = fgetc(in)) != EOF)
    {
        // Check if the character is a space or newline
        if (c == ' ' || c == '\n')
            words++;
    }

    // Print the total number of words to the output file
    fprintf(out, "Total number of words:%d", words);
}
