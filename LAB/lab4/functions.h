
/*
 *Joel Miller                   
 *CPSC 2310 Spring 23           
 *UserName: jmill53             
 *Instructor: Dr. Yvon Feaster 
 */



#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>


int** readFile(FILE* fp, int *size);
void printMatrix (int** mat, int num);
bool isRightDiagonal(int size, int row, int col);
bool isLeftDiagonal(int row, int col);
int calculateVal(int** mat, int size);
