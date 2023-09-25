/*
*Joel Miller                               
*CPSC 2310 Spring 23                       
*UserName: jmill53                         
*Instructor:  Dr. Yvon Feaster
*/

#include "functions.h"

const int months = 12;

const char* monthNames[] = 
      {
        "January", 
        "February", 
        "March",
        "April",
        "May", 
        "June", 
        "July",
        "August",
        "September",
        "October", 
        "November", 
        "December"
        };

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


list_stats_t getListStats(node_t *head) {

    list_stats_t stats = {0};

     node_t *oldN = NULL;
     node_t *youngN = NULL;
     node_t *currN = head;
    
    while (currN != NULL) {
        // Check for invalid date
        if (checkInvalidDate(currN)) {
            currN = currN->next;
            continue;
        }
        
        // oldest person
        if (oldN == NULL || compareBirthdays(&currN->birthday, 
                                             &oldN->birthday) < 0) {
            oldN = currN;
        }
        
        //  youngest person
        if (youngN == NULL || compareBirthdays(&currN->birthday,
                                               &youngN->birthday) > 0) {
            youngN = currN;
        }
        
        //for loop to count number of birthday months
        for (int i = 0; i < months; i++) {
            if (strcmp(currN->birthday.month, monthNames[i]) == 0) {
                stats.birthdayCounts[i]++;
                break;
            }
        }
        //sets the current node to the next
        currN = currN->next;
    }
    
    // oldest persons information into stats struct
    if (oldN != NULL) {
        stats.old = oldN;
    }
    
    //youngest persons information into stats struct
    if (youngN != NULL) {
        stats.young = youngN;
    }
    //returns stats to printlist
    return stats;
}


//function to compare two birthdays and determine which one is older
int compareBirthdays(birthday_t *first, birthday_t *second) {
   
    int month1 = 0;
    int month2 = 0;

    //if years are different
    if (first->year != second->year) 
    {
        return ((first->year) - (second->year));
    }   
    // if months are different
   else if (strcmp(first->month, second->month) != 0) {

//loop through all month names to find which month matches each birthday
    for (int i = 0; i < months; i++) 
    {
        if (strcmp(first->month, monthNames[i]) == 0) 
        {
            month1 = i;
        }
        else if (strcmp(second->month, monthNames[i]) == 0)
        {
            month2 = i;
        }

    }   
    return month1 - month2;

    // if years and months are the same then compare days
   }else 
   {   
        return ((first->day) - (second->day));
   }

    }



void printStats(FILE *outputFile, list_stats_t *stats) {
//check to see if list is empty, if it is print None
if (stats->old == NULL || stats->young == NULL) {
        fprintf(outputFile, "None\n\n");
        return;
    }
    //prints the opening border
   printBorder(outputFile);

    fprintf(outputFile, "List Statistics:\n");

        // Print oldest person
        fprintf(outputFile, "----------Oldest Person----------\n");

        fprintf(outputFile, "Name:\t%s %s\n", stats->old->firstName,
                                              stats->old->lastName);

        fprintf(outputFile, "Date of Birth:\t%s %d, %d\n", 
                                              stats->old->birthday.month, 
                                              stats->old->birthday.day, 
                                              stats->old->birthday.year);

        fprintf(outputFile, "Major:\t%s\n", stats->old->major);

        fprintf(outputFile, "Year:\t%s\n\n", stats->old->standing);
        

        // Print youngest person
        fprintf(outputFile, "----------Youngest Person----------\n");

        fprintf(outputFile, "Name:\t%s %s\n", stats->young->firstName, 
                                              stats->young->lastName);

        fprintf(outputFile, "Date of Birth:\t%s %d, %d\n", 
                                              stats->young->birthday.month, 
                                              stats->young->birthday.day,
                                              stats->young->birthday.year);

        fprintf(outputFile, "Major:\t%s\n", stats->young->major);

        fprintf(outputFile, "Year:\t%s\n\n", stats->young->standing);
       

        // Print birthday counts
        fprintf(outputFile, "----------Birthday Counts----------\n");
        fprintf(outputFile, "January: %d\n", stats->birthdayCounts[0]);
        fprintf(outputFile, "February: %d\n", stats->birthdayCounts[1]);
        fprintf(outputFile, "March: %d\n", stats->birthdayCounts[2]);
        fprintf(outputFile, "April: %d\n", stats->birthdayCounts[3]);
        fprintf(outputFile, "May: %d\n", stats->birthdayCounts[4]);
        fprintf(outputFile, "June: %d\n", stats->birthdayCounts[5]);
        fprintf(outputFile, "July: %d\n", stats->birthdayCounts[6]);
        fprintf(outputFile, "August: %d\n", stats->birthdayCounts[7]);
        fprintf(outputFile, "September: %d\n", stats->birthdayCounts[8]);
        fprintf(outputFile, "October: %d\n", stats->birthdayCounts[9]);
        fprintf(outputFile, "November: %d\n", stats->birthdayCounts[10]);
        fprintf(outputFile, "December: %d\n", stats->birthdayCounts[11]);

//prints the closing border
      printBorder(outputFile);
    }




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
