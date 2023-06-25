#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "list.h"
#include"airport.h"

/*
 * File containing all the functions to insert, delete, find, and save (a) linked list node(s) into a list or file
 * CS305 HW 3
 * Author: Comingupwithnames
 * version: 1: Oct 29 2021
 */

/* 
 * makeList
 * args: list and airport pointers/objects
 * return: LList*
 * Inserts a given node and inserts nodes in order (alphabetically, numerically, etc)
 */
LList* makeList(LList* list, Airport* airport)
{
    LList* myList = (LList*) malloc(sizeof(LList));//Allocates memory for a LList node
    myList->airportPtr = airport;//Sets the airport pointer to the provided airport
    myList->next = list;//Sets the next field to the passed list, be it null or otherwise
    return myList;
}

/* 
 * insert
 * args: list and airport pointers/objects
 * return: LList*
 * Inserts a given node and inserts nodes in order (alphabetically, numerically, etc)
 */
LList* insert(LList* list, Airport* airport)
{
    LList* myList = list;
    if(airport == NULL)//Checks if airport is null and returns null if true
    {
        printf("Error, airport is null!\n");
        return list;
    }
    if(myList == NULL) //Base case: current list is null
    {
        myList = makeList(NULL, airport);//Makes a list node
        list = myList;//Sets the current list passed through
        printf("Inserting airport: \n");
        print_airport(airport);
        return list;
    }
    else if((strcmp(airport->TAG,myList->airportPtr->TAG)<=0))//Base case 2: the current node's tag comes before the current one passed through
    {
        myList = makeList(list, airport);//Makes a list node and sets its next field to the passed through list
        list = myList;//Sets the current list passed through
        printf("Inserting airport: \n");
        print_airport(airport);
        return list;
    }
    else //Recursive case:
    {
        list->next = insert(list->next, airport);
    }
    return list;
}

/* 
 * delete_airport
 * args: list pointer and tag string
 * return: list after node is freed
 * Runs through the list to find airport with specified tag
 */
LList* delete_airport(LList* list, char* tag)
{
    if(list == NULL)//Base case 1: list is null
    {
        printf("Error, list is null or tag to delete not found!\n");
        return NULL;   
    }
    else if(strcmp(tag,list->airportPtr->TAG)==0)//Base case 2: node found
    {
        LList * tmp = list->next;//Temp node set to next node in the list to be returned
        free_airport(list->airportPtr);
        free(list);
        return tmp;//Returns new list with node deleted
    }
    else//Recursive case
    {
       list->next = delete_airport(list->next, tag);
    }
    return list;
}

/* 
 * find_airport
 * args: list pointer and tag string
 * return: Airport to be found if found
 * Runs through the list to find the specified tag 
 */
Airport* find_airport(LList* list, char* tag)
{
    if(strlen(tag)!= 3)
    {
        printf("Error, tag to find is too long or short!\n");
        return NULL;        
    }
    if(list == NULL)//Base case 1: list is null
    {
        printf("Error, list is null or airport was not found!\n");
        return NULL;   
    }
    else if(strcmp(tag,list->airportPtr->TAG)==0)//Base case 2: node is found
    {
        printf("Airport found!\n");
        return list->airportPtr;//Returns the found airport
    }
    else//Recursive case:
    {
        return find_airport(list->next, tag);
    }
}

/* 
 * save
 * args: list pointer and a filename
 * return: int (true or false)
 * Creates a writable file that the linked list will print airports onto
 */   
int save(LList* list, char* filename)
{
    FILE* fOut = fopen(filename,"w");//Creates writable file with the given name
    if(list == NULL)//Checks to see if the list is null
    {
        printf("Error, list is empty, nothing to save\n");
        fclose(fOut);
        return 0;
    }
    else
    {
        while(list != NULL)
        {
            printf_airport(list->airportPtr, fOut);
            list = list->next;
        }
        printf("Save: List saved to file %s\n",filename);
        fclose(fOut);
        return 1;
    }
}

/* 
 * print_list
 * args: list pointer
 * return: void
 * Prints the current linked list's airport fields
 */
void print_list(LList* list)
{
    printf("Printing LList\n");
    while(list != NULL) 
    {
        print_airport(list->airportPtr);
        list = list->next;
    }
}

/* 
 * delete_list
 * args: list pointer
 * return: void
 * Frees the entire list (only done when quitting)
 */
void delete_list(LList* list)
{
    if(list==NULL)//Checks to see if the list is null (nothing to delete)
    {
        printf("Error! Attempting to free null list\n");
    }
    else
    {
        while(list != NULL) 
        {
            LList* tmp = list;//Temp node to store node to delete
            list = list->next;//Sets the next node equal to its next field
            free_airport(tmp->airportPtr);
            free(tmp);
        }
    }
}
