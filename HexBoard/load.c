#include <stdio.h>
#include <stdlib.h>

#include "load.h"
#include "hexboard.h"
#include "hexcell.h"

/*
 * File containing the function that loads a file given a specific input string
 * CS305 HW 2
 * Author: Comingupwithnames
 * version: 1: Oct 2 2021
 */

/*
 * file_load 
 * args: Input to the file name to be loaded
 * return: Board object
 * Allocates memory to a board object and reads inputs from a file provided
 * Then, creates a two dimensional array of pointers to hexcell objects and sets the board color to WHITE
 */
board* file_load(char*input)
{
    board* myBoard = (board*)malloc(sizeof(board));//Allocating memory for a board object
    if(myBoard == NULL) //Checks to see if the newly allocated board is null and then returns
    {
        return NULL;
    }

    FILE *in_file = fopen(input, "r"); //Reads the unread filename and sets it to be a readable file
    if(in_file == NULL) //Checks to see if no file was read and frees the board and returns null
    {
      printf("Error! No file opened.\n");
      free(myBoard);
      return NULL;
    } 
    //Checks to see if the number of integer inputs is equal to 6 and frees the board as well as returning null
    if((fscanf(in_file, "%d %d %d %d %d %d ", &myBoard->max_row, &myBoard->max_col, 
    &myBoard->start_row, &myBoard->start_col, &myBoard->end_row, &myBoard->end_col) != 6))
    {
      printf("Error! Input mismatch\n");
      free(myBoard);
      return NULL;
    }
    //Checks to see if the dimensions are zero or if the starting coords are out of bounds
    if((myBoard->max_row == 0 || myBoard->max_col == 0) || 
    (myBoard->start_row > myBoard->max_row || myBoard->start_col > myBoard->max_col))
    {
      printf("Error! Board size is zero or starting coords are out of bounds!\n");
      return NULL;
    }
    int height = myBoard->max_row;
    int width = myBoard->max_col;
    hexcell** myHexBoard = (hexcell**)malloc(sizeof(hexcell*)*height);//Allocates memory for the rows of hexcell pointers for a two dimensional array of hexcells
    if(myHexBoard == NULL)//If null, will print the error message and exit
    {
        printf("Error, could not allocate memory\n");
        return NULL;
    }

    for(int i=0; i<height;i++)
    {
        myHexBoard[i] = (hexcell*)malloc(sizeof(hexcell)*width);//Allocates memory for the columns of hexcell structs
        for(int j=0; j<width; j++)
        {
          if(fscanf(in_file, "%d ",&myHexBoard[i][j].obstacle) !=1)//If nothing is scanned, return NULL
          {
            free(myHexBoard);
            return NULL;
          }
          if(myHexBoard[i][j].obstacle == NO || myHexBoard[i][j].obstacle == YES)//If the values assigned to obstacle match YES or NO, assign its color to white and continue
          {
            myHexBoard[i][j].color = WHITE; 
          }   
          else
          {
            return NULL;
          }
        }
    }
    myBoard->hexcells = myHexBoard;
fclose(in_file);
return myBoard;
}
