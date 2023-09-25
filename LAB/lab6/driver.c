/*
*Joel Miller                               
*CPSC 2310 Spring 23                       
*UserName: jmill53                         
*Instructor:  Dr. Yvon Feaster
*/

#include "functions.h"

int main(int argc, char* argv[])
{
 //creates two null file pointers
    FILE* fileIn = NULL;
    FILE* fileOut = NULL;


//creates the linkedlist head and current node pointers
    node_t* head = NULL;
    node_t* current = NULL;

assert(argc == 3);

//opens the input file with 1st command arg
fileIn = fopen(argv[1], "r");

//check if input opened
assert(fileIn != NULL);


current = createList(fileIn, &head);

//get the list stats
list_stats_t stats = getListStats(head);

//opens the output file with 2nd command arg
fileOut = fopen(argv[2], "w");

//check if output opened
assert(fileOut != NULL);

//print the list stats to the output file
printStats(fileOut, &stats);

//deletes the list
deleteList(&head);

//closes both files
fclose(fileIn);
fclose(fileOut);

return 0;
}