#include <stdio.h>
#include <stdlib.h>

#include "load.h"
#include "hexcell.h"
#include "hexboard.h"
/*
 * Hex board path finder logic
 * CS305 HW2 solution
 * Author: Martin Cenek
 * version: 1: 20210901
 * version: 2: 20210909
 */

int main(int argv, char* argc[]){

	if(argv != 2){
		fprintf(stderr, "ERROR: Board file name missing. Usage: find_path <board>");
		return EXIT_FAILURE;
	}
	int ret = find_path(argc[1]);
	if (ret == 0){
        printf("Could not find a path. Board could not be solved\n");
    }else
        printf("Success: Found the path!\n");
    printf("Thank you for playing\n");

	return EXIT_SUCCESS;
}

