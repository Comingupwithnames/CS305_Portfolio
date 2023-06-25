#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "airport.h"

/*
 * File containing all the functions to make, print, and free an airport struct
 * CS305 HW 3
 * Author: Comingupwithnames
 * version: 1: Oct 29 2021
 */


/* 
 * make_airport
 * args: four strings of the tag, name, city, and country
 * return: Airport pointer to the airport struct
 * Creates an airport and checks to see if the string length of tag is 3 chars long
 */
Airport* make_airport(char* tag, char* name, char* city, char* country)
{
    Airport* myAirport = (Airport*)malloc(sizeof(struct Airport));//Allocates memory for an airport object
    if(name == NULL || city == NULL || country == NULL)//Check for if any fields are NULL
    {
        printf("Error, one or more of the fields are null or empty");
        return NULL;
    }
    else
    {
        myAirport->airportName = name;//Setting struct fields to the variables now
        myAirport->city = city;
        myAirport->country = country;
    }
    if(strlen(tag) != 3)//Check to see if string length equals 3
    {
        printf("Error, tag too long or too short\n");
        return NULL;
    }
    else
    {
        strcpy(myAirport->TAG, tag);//Sets TAG to the acceptable tag input
    }
    return myAirport;
}

/* 
 * print_airport
 * args: Airport object
 * return: void
 * prints the airport struct fields in string form
 */
void print_airport(Airport* airport)
{
    if(airport == NULL)
    {
        printf("Error, airport is null!\n");
        return;
    }
    char* tag = airport->TAG;
    char* name = airport->airportName;
    char* city = airport->city;
    char* country = airport->country;
    printf("%s %s %s %s\n", tag, name, city, country);
    return;
}

/* 
 * printf_airport
 * args: Airport object and a file to write to
 * return: void
 * Will print the fields of an airport object onto a file.
 */
void printf_airport(Airport* airport, FILE* fileout)
{
    if(airport == NULL)
    {
        printf("Error, airport is null!\n");
        return;
    }
    char* tag = airport->TAG;
    char* name = airport->airportName;
    char* city = airport->city;
    char* country = airport->country;
    fprintf(fileout, "%s %s %s %s\n", tag, name, city, country);
    return;
}

/* free_airport
* args: Airport object
* return: void
* Frees the current airport that is passed through
*/
void free_airport(Airport* airport)
{
    if(airport==NULL)
    {
        printf("Error, no airport to free\n");
        return;
    }
    else
    {
        free(airport->airportName);
        free(airport->city);
        free(airport->country);
        free(airport);
        return;
    }
}