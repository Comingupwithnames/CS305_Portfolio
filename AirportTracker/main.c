#include <stdio.h>
#include <stdlib.h>

#include "process.h"
#include "airport.h"
#include "list.h"

/*
 * File containing the main driving function for the rest of the program
 * CS305 HW 3
 * Author: Comingupwithnames
 * version: 1: Oct 29 2021
 */

/* 
 * main
 * args: number of arguments and a possible file name
 * return: integer
 * calls process_file if a file name is passed in, otherwise it will call process_input for terminal inputs
 */

int main(int argv, char* argc[])
{
    LList* list = NULL;
    if(argv == 2)//Checks to see if the number of arguments equals 2
    {
      list = process_file(argc[1]);//passes the input file into process_file
      process_input(list);//Afterwards, proceeds to accept inputs from terminal window until quit 
      return EXIT_SUCCESS; 
    }
    else//If no file is passed through, process_input will be the only one called
    {
        process_input(list);
        return EXIT_SUCCESS;
    }
}