/*
/**************************
*Joel Miller                               *
*CPSC 2310 Spring 23                       *
*UserName: jmill53                         *
*Instructor:  Dr. Yvon Feaster             *
*************************/



#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>



typedef struct birthday
{
    int day;
    int year;
    char month[10];
} birthday_t;



typedef struct node
{
    char firstName[50];
    char lastName[50];
    char major[50];
    char standing[50];

    //instance of the birthday struct
    birthday_t birthday; 

    //pointer that keeps track of next node
    struct node *next;
} node_t;



void add(node_t **node, node_t **head);
node_t* readNodeInfo(FILE* input);
node_t* createList(FILE*, node_t**);
void printList(FILE*, node_t*);
void printBorder(FILE*);
void deleteList(node_t** );
bool checkInvalidDate(node_t *node);
bool isLeapYear(int year);
void sortList(node_t **head, int (*comp)(node_t* , node_t* ));
int compare_by_firstname(node_t* a, node_t* b);
int compare_by_lastname(node_t* a, node_t* b);
#endif