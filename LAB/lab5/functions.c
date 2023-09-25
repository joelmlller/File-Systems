/**************************
*Joel Miller                               *
*CPSC 2310 Spring 23                       *
*UserName: jmill53                         *
*Instructor:  Dr. Yvon Feaster             *
*************************/

#include "functions.h"


//helper function to see if the given year is a leap year
bool isLeapYear(int year)
{
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}



bool checkInvalidDate(node_t *node)
{
    int day = node->birthday.day;
    int year = node->birthday.year;

    // check if month is valid
    if (   strcmp(node->birthday.month, "January") != 0 
        && strcmp(node->birthday.month, "February") != 0 
        && strcmp(node->birthday.month, "March") != 0 
        && strcmp(node->birthday.month, "April") != 0 
        && strcmp(node->birthday.month, "May") != 0 
        && strcmp(node->birthday.month, "June") != 0 
        && strcmp(node->birthday.month, "July") != 0 
        && strcmp(node->birthday.month, "August") != 0 
        && strcmp(node->birthday.month, "September") != 0 
        && strcmp(node->birthday.month, "October") != 0 
        && strcmp(node->birthday.month, "November") != 0 
        && strcmp(node->birthday.month, "December") != 0) {
        return true;
    }

    // check if day is valid for the given month
    if (strcmp(node->birthday.month, "January") == 0 ||
        strcmp(node->birthday.month, "March") == 0 ||
        strcmp(node->birthday.month, "May") == 0 ||
        strcmp(node->birthday.month, "July") == 0 ||
        strcmp(node->birthday.month, "August") == 0 ||
        strcmp(node->birthday.month, "October") == 0 ||
        strcmp(node->birthday.month, "December") == 0) {
        if (day < 1 || day > 31) {
            return true;
        }
    } else if (strcmp(node->birthday.month, "April") == 0 ||
               strcmp(node->birthday.month, "June") == 0 ||
               strcmp(node->birthday.month, "September") == 0 ||
               strcmp(node->birthday.month, "November") == 0) {
        if (day < 1 || day > 30) {
            return true;
        }
    } else {
        if (isLeapYear(year)) {
            if (day < 1 || day > 29) {
                return true;
            }
        } else {
            if (day < 1 || day > 28) {
                return true;
            }
        }
    }

    return false;
}

//bubble sort
void sortList(node_t **head, int (*compareNodes)(node_t *, node_t *)) {
    node_t *tl = *head, 
           *ts = NULL;
    int srted = 1;

    if (*head == NULL)
        return;
// loop until the list is sorted
    while (srted) {
        srted = 0;
        tl = *head;
        // loop through the list from head to tail
        while (tl->next != ts) {
            // if tl is greater than tl->next swap them
            if (compareNodes(tl, tl->next) > 0) {
                //swap pointers
                node_t *temp = tl->next;
                tl->next = temp->next;
                temp->next = tl;
                if (tl == *head) {
                    *head = temp;
                } else {
                    node_t *prev = *head;
                    while (prev->next != tl) {
                        prev = prev->next;
                    }
                    prev->next = temp;
                }
                tl = temp;

                srted = 1;
            }
            tl = tl->next;
        }
        ts = tl;
    }
}


//compares two nodes based on their first names
int compare_by_firstname(node_t *a, node_t *b) {
    return strcmp(a->firstName, b->firstName);
}
//compares two nodes based on their last names
int compare_by_lastname(node_t *a, node_t *b) {
    return strcmp(a->lastName, b->lastName);
}



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
            // Check if date is valid before printing person's information
            if (!checkInvalidDate(temp)) {
                //Prints the name to the file
                fprintf(output, "Name:\t%s %s\n", temp->firstName, temp->lastName);
                
                //Prints the DOB to the file
                fprintf(output, "Date of Birth:\t%s %d, %d\n", 
                 temp->birthday.month, temp->birthday.day, temp->birthday.year);
                
                //Prints the major to the file
                fprintf(output, "Major:\t%s\n", temp->major);
                
                //Prints the Class Standing to the file
                fprintf(output, "Year:\t%s\n\n", temp->standing);
            }
            
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

