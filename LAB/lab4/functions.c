
/*
 *Joel Miller                   
 *CPSC 2310 Spring 23           
 *UserName: jmill53             
 *Instructor: Dr. Yvon Feaster 
 */




#include "functions.h"

int** readFile(FILE* fp, int *size)
{
    fscanf(fp, "%d", size);
    int num = *size;
    int index = 0;

    int** mat = (int**)malloc(num * sizeof(int*));
    for(index = 0; index < num; index++)
        mat[index] = (int*)malloc(num * sizeof(int)); 

    int row = 0; 
    int col = 0;
    for(;row < num; row++)
    {
        for(col = 0; col < num; col++)
        {
            fscanf(fp, "%d", &mat[row][col]);
        }
        col = 0;
    }
    return mat;
}

void printMatrix (int** mat, int num)
{
    int row = 0; 
    int col = 0;
    for(row = 0; row < num; row++)
    {
        for(col = 0; col < num; col++)
        {
            printf("%.2d\t", mat[row][col]);
        }
        printf("\n");
    }
}
// check if position is in right diagonal
bool isRightDiagonal(int size, int row, int col)
{
    return (row == col || row == size - col - 1) ? false : true;
}

// check if position is in left diagonal
bool isLeftDiagonal(int row, int col)
{
    return (row == col) ? false : true;
}

// sum values in squares not on diagonals
int calculateVal(int** mat, int size)
{
    int calc = 0;

    for(int r = 0; r < size; r++)
    {
        for(int c = 0; c < size; c++)
        {

            if(isLeftDiagonal(r, c) && isRightDiagonal(size, r, c))
            {
                calc += mat[r][c];

            }
        }
    }
    return calc; 
}
