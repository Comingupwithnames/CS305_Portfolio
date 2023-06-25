#ifndef PROCESS_H
#define PROCESS_H

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* Function prototypes */
LList* process_file(char*);
void process_input(LList*);
void print_usage();

#endif