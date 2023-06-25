#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hexcell.h"
#include "load.h"
#include "hexboard.h"

/*
 * File containing all the functions to search for a goal tile, free the board, and print the board
 * CS305 HW 2
 * Author: Comingupwithnames
 * version: 1: Oct 2 2021
 */

/* 
 * print_board 
 * args: pointer to the current board struct
 * return: void
 * prints the hexboard board: 
 * if hexcell color is path, print 'P'
 * if hexcell has an obstacle, print 'X'
 * otherwise print '0' 
 */
void print_board(board* board){
    printf("Board: %drx%dc, start: %drx%dc destination: %drx%dc\n", board->max_row, 
        board->max_col, board->start_row, board->start_col, board->end_row, 
        board->end_col);
    for (int j=0; j<board->max_col;j++)         //print the header row of board
        printf("/ \\ ");
    printf("\n");
    for (int i = 0; i<board->max_row;i++){      //print each cell
        for (int j=0; j<board->max_col;j++){
            if(i%2&&j==0) 
                printf("  ");
            printf("|%c| ",(board->hexcells[i][j].color==BLACK?'P':(board->hexcells[i][j].obstacle==YES?'X':'0')));
        }   
        printf("\n");
 
        for (int j=0; j<board->max_col;j++){    //print matching footer or new header of each cell
            if(j==0&& i%2)
                printf("/ \\ / ");              //next header
            else
                printf("\\ / ");                //matching footer
            }
            printf("\n");
        }
    printf("\n");
return;

}

/*
 * find_path
 * Function that calls the methods below to see if a path to a destination cell on a board exists
 * args: f_name - name of an input file
 * return: return 1 if path is found, 0 otherwise
 */
int find_path(char* f_name)
{
board* myBoard = file_load(f_name); //Loads the board itself
if(myBoard==NULL)//If nothing loaded, return false
{
    printf("No board loaded/found.\n");
    return 0;
} 
print_board(myBoard);//Calls orint_board to print the contents of the board
int ret = start_search(myBoard);//Assigns the results of start_rearch to ret
print_board(myBoard);//Prints the board again after the search has been done
free_board(myBoard);//Frees the board and every row
return ret;
}

/* 
 * search 
 *  a recursive implemention of the path search on a hex board
 *  args: board - current board state of row and col
 *  return: return 1 if a valid path found and 0 otherwise
 *  Recursively calls itself on the cells of a given board until either a path is found or if no path at all is found
 */
int search(board* board, int row, int col)
{   
    //Bounds checks the 2D array and checks to see if the cells have already been visited or if they are an obstacle
    if(row < 0 || col < 0 ||
     row > board->max_row-1 || col > board->max_col-1 || 
     board->hexcells[row][col].obstacle == YES || 
     board->hexcells[row][col].color == GRAY || board->hexcells[row][col].color==BLACK)
    {
       return 0;
    }
    else if(row == board->end_row && col == board->end_col) //If the current row and column are equal, return true
    {
        board->hexcells[row][col].color=BLACK;//Sets destination cell as part of the path
        return 1;
    }
    board->hexcells[row][col].color=BLACK;//Sets the current cell as a pathway cell by setting the color to black
    if(row % 2 == 0)
    {
        //This checks the top left cell and continues recursively checking clockwise for even rows
        if(search(board, row-1,col-1) | search(board, row-1, col) | search(board, row, col+1) | 
        search(board, row+1, col) | search(board, row+1, col-1) | search(board, row, col-1))
        {
            return 1;
        }
        else
        {
            board->hexcells[row][col].color=GRAY;//Sets cell state as already visited
            return 0;
        }
        
    }
    else
    {
        //Offsets the search so it searches the top right cell first and continues clockwise for odd rows
        if(search(board, row-1,col+1) | search(board, row, col+1) | search(board, row+1, col+1) | 
        search(board, row+1, col) | search(board, row, col-1) | search(board, row-1, col))
        {
            return 1;
        }
        else
        {
            board->hexcells[row][col].color=GRAY;//Sets cell state as already visited
            return 0;    
        }
    }        
}

/* 
 * start_search
 * args: current board state
 * return: returns 1 if search found path and 0 otherwise
 * Calls the recursive search function if checks below are passed
 */
int start_search(board* board)
{
    //Checks to see if the ending coords are out of bounds
    if((board->end_row > board->max_row || board->end_col > board->max_col) || 
    (board->end_row < 0 || board->end_col < 0))
    {
        return 0;
    }
    //Checks to see if starting cells are obstacles
    if(board->hexcells[board->start_row][board->start_col].obstacle==YES || board->hexcells[board->end_row][board->end_col].obstacle==YES) 
    {
        return 0; 
    }
    else
    {
        return search(board, board->start_row, board->start_col);
    }
}

/* 
 * free_board
 * arg: current board struct 
 * return: void
 * deallocates all heap memory -- hexboard object and all of its board's rows, columns, hexcells
 */
void free_board(board* board)
{
for(int i=0; i<board->max_row;i++)
{
    free(board->hexcells[i]);//Frees each row
}
free(board->hexcells);//Frees the array itself
free(board);//Frees the board itself
}

