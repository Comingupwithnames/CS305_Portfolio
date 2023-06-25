#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include "list.h"
#include "airport.h"
/*
 * File containing all the functions to process inputs from a file or from the keyboard into an LList
 * CS305 HW 3
 * Author: Comingupwithnames
 * version: 1: Oct 29 2021
 */

/* 
 * process_file
 * args: string for the name of the file
 * return: Linked list after inserting all valid airports
 * Opens a readable file with the given name and reads operations based on inputs
 */
LList* process_file(char* fileName)
{
    FILE* fileIn = fopen(fileName, "r");
    LList * list = NULL;
    int count = 0;
    while(!feof(fileIn))
    {
        char tag[4];
        char *name, *city, *country;
        char operation;
        fscanf(fileIn, " %c", &operation);
        if(operation == 'q')
        {
            printf("Quitting\n");
            printf("Count: %d\n",count);
            fclose(fileIn);
            return list;
        }
        else if(operation == 'a')
        {
            if(fscanf(fileIn, "%s %ms %ms %ms", tag, &name, &city, &country)!=4)
            {
                printf("Error, one of the fields are empty or null!\n");
            }
            else
            {
                Airport* myAirport = make_airport(tag, name, city, country);
                list = insert(list, myAirport);
                count++;
            }
        }
        else if(operation == 'd')
        {
            fscanf(fileIn, "%s", tag);
            list = delete_airport(list, tag);
            if(list != NULL)
            {
                count--;  
            }
        }
        else if(operation == 'f')
        {
            fscanf(fileIn, "%s", tag);
            print_airport(find_airport(list, tag));
        }
        else if(operation == 's')
        {
            char saveFile[30];
            fscanf(fileIn, "%s", saveFile);
            FILE* fileOut = fopen(saveFile, "w");
            if(fileOut == NULL)
            {
                printf("Failed to open file\n");
                return NULL;
            }
            save(list, saveFile);
            fclose(fileOut);
        }
        else if(operation == 'p')
        {
            print_list(list);
        }
        else
        {
            printf("Error, not a valid input\n");
        }           
    }
}

/* 
 * process_input
 * args: Linked list pointer
 * return: Void
 * Prints the usage of the program and waits for the user to input valid commands
 */
void process_input(LList* list)
{
    FILE* fileOut;
    while(1)
    {   
        char tag[4];
        char *name, *city, *country;
        char operation;
        print_usage();
        scanf(" %c", &operation);
        if(operation == 'q')
        {
            printf("Quitting\n");
            if(list != NULL)
            {
                delete_list(list);
            }
            return;
        }
        else if(operation == 'a')
        {
            if(scanf("%s %ms %ms %ms", tag, &name, &city, &country)!=4)
            {
                printf("Error, input mismatch!\n");
            }
            else
            {
                Airport* myAirport = make_airport(tag, name, city, country);
                list = insert(list, myAirport);
            }
            if(list != NULL)
            {
                print_list(list);
            }
        }
        else if(operation == 'd')
        {
            scanf("%s", tag);
            list = delete_airport(list, tag);
            if(list != NULL)
            {
                print_list(list);
            }
        }
        else if(operation == 'f')
        {
            scanf("%s", tag);
            print_airport(find_airport(list, tag));
        }
        else if(operation == 's')
        {
            char fileName[30];
            scanf("%s", fileName);
            fileOut = fopen(fileName, "w");
            if(fileOut == NULL)
            {
                printf("Failed to open file\n");
                return;
            }
            save(list,fileName);
            fclose(fileOut);
        }
        else if(operation == 'p')
        {
            print_list(list);
        }
        else
        {
            printf("Error, not a valid input\n");
        }

    }            
}


/* 
 * print_usage
 * args: none
 * return: void
 * Prints the usage of the program through multiple printf statements
 */
void print_usage()
{
    printf("Usage:\n");
    printf("(save) s <file name>: saves list of airports to a file\n");
    printf("(quit) q: quits the application\n");
    printf("(print) p: prints the list of airports\n");
    printf("(delete) d <tag>: deletes the airport with given <tag>\n");
    printf("(find) f <tag>: finds the airport with given <tag>\n");
    printf("(add) a <tag> <name> <city> <state>: adds the airport to the list of airports\n"); 
}
