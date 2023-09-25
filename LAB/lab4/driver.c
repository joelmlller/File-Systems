
/*
 *Joel Miller                   
 *CPSC 2310 Spring 23           
 *UserName: jmill53             
 *Instructor: Dr. Yvon Feaster 
 */



#include "functions.h"

int main(int argc, char** argv)
{

    int final;

    FILE* fp = fopen(argv[1], "r");


    //printf("cheking command line arguments\n");

    if (argc < 2) 
    { 
        printf("not enought argument: ./exe filename\n"); 
        exit(-1);
    }

    
    if(fp==NULL)
    {
        printf("fp did nto open\n"); 
        exit(-1);
    }
    int size = 0;
  
    int **mat = readFile(fp, &size);
    printMatrix(mat, size);


    final = calculateVal(mat, size);
    printf("Total = %d\n", final);

    for(int i = 0; i < size; i++)
    
    free(mat[i]);
    free(mat);

    

    


    return 0;
}