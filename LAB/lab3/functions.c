/*
 *Joel Miller                   
 *CPSC 2310 Spring 23           
 *UserName: jmill53             
 *Instructor: Dr. Yvon Feaster 
 */


#include "functions.h"



// add a new node to the linked list
void add(node_t** node, node_t** head)
{
    node_t* thisNode = *node;
    node_t* current = *head;
    node_t* previous = NULL;


    // loop through the linked list to check if the node is a duplicate
    while (current != NULL) 
    {
        //if the node is a duplicate then return
        if (strcmp(current->firstName, thisNode->firstName) == 0 && 
            strcmp(current->lastName, thisNode->lastName) == 0) 
            {
              return; 
            }

        //traverses list
        previous = current;
        current = current->next;
    }

    //makes new node the head if linkedlist is empty
    if(*head == NULL)
    {
        *head = thisNode;
        thisNode->next = NULL;
    }
    //else insert new node at beginning
    else
    {
        previous->next = thisNode;
        thisNode->next = NULL;
    }
}


node_t* readNodeInfo(FILE* input)
{
   //calls to malloc to allocate memory
   node_t* node = (node_t*)malloc(sizeof(node_t));

   assert(node != NULL);

    char month[50];
    char dayStr[10];
    char yearStr[10];

    //reads the data from the file and stores in the node
    fscanf(input,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
    node->lastName, node->firstName, month,
    dayStr, yearStr, node->major, node->standing);

    // convert day and year strings to integers
    node->birthday.day = atoi(dayStr);
    node->birthday.year = atoi(yearStr);

    // copy month string to node
    strcpy(node->birthday.month, month);

    return node;
}




// create a linked list of nodes from input file
node_t* createList(FILE* input, node_t** head)
{
    node_t* node = NULL;
    char nextChar;

    //loops through the input file character by character
    while((nextChar = fgetc(input)) != EOF)
    {
        //ungetc puts the last character back into the input stream
        ungetc(nextChar, input);

        node = readNodeInfo(input);
        add(&node, head);

        //move to the next character in the input stream
        nextChar = fgetc(input);
    }       
    return *head;
}



void printList(FILE* output, node_t* head)
{
    node_t* temp = head;

    //if list is empty then print a error
    if(head == NULL)
    {
        fprintf(stderr, "LIST IS EMPTY\n");
        exit(1);
    }
    else
    {   //Prints opening border
        printBorder(output);
        fprintf(output,"\n");
        fprintf(output, "List Info:\n");
        while(temp != NULL)
        {
            //Prints the name to the file
        fprintf(output, "Name:\t%s %s\n", temp->firstName, temp->lastName);

           //Prints the DOB to the file
        fprintf(output, "Date of Birth:\t%s %d, %d\n", 
        temp->birthday.month, temp->birthday.day, temp->birthday.year);

           //Prints the major to the file
        fprintf(output, "Major:\t%s\n", temp->major);

           //Prints the Class Standing to the file
        fprintf(output, "Year:\t%s\n\n", temp->standing);
            
            temp = temp->next;

        }
        //prints the closing border
        printBorder(output);
    }
}



//Prints the border 
void printBorder(FILE* out)
{
    int i = 0;
    for(i = 0; i < 80; i++)
        fprintf(out,"*");
    
    fprintf(out, "\n");
}



//frees the memory that was allocated
void deleteList(node_t** head)
{
    //Temporary node
    node_t* current = *head;
    //stores next node in list
    node_t* second = NULL;

    //loops through linkedlist freeing memory in each node
    while(current != NULL)
    {
        second = current->next;

        //frees the current node
        free(current);
        current = second;
    }
}

