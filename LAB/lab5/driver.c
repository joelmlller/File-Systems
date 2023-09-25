/**************************
*Joel Miller                               *
*CPSC 2310 Spring 23                       *
*UserName: jmill53                         *
*Instructor:  Dr. Yvon Feaster             *
*************************/


#include "functions.h"

int main(int argc, char* argv[])
{
    //creates two null file pointers
    FILE* fileIn = NULL;
    FILE* fileOut = NULL;

    //creates the linkedlist head and current node pointers
    node_t* head = NULL;
    node_t* current = NULL;

    assert(argc == 4);

    //opens the input file with 1st command arg
    fileIn = fopen(argv[1], "r");

    //check if input opened
    assert(fileIn != NULL);

    //opens the output file with 2nd command arg
    fileOut = fopen(argv[2], "w");

    //check if output opened
    assert(fileOut != NULL);

    //Get the sorting option from the command line argument
    int bubSort = atoi(argv[3]);

    //create the linked list
    current = createList(fileIn, &head);

    //sort the list depending on the sorting option
    if (bubSort == 1) {
        sortList(&head, compare_by_firstname);
        
    } 
    else if (bubSort == 2) {
        sortList(&head, compare_by_lastname);
        
    }

    //prints list to output
   printList(fileOut, head);

    //deletes the list
    deleteList(&head);

    //closes both files
    fclose(fileIn);
    fclose(fileOut);

    return 0;
}
