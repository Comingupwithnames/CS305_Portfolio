#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "airport.h"

typedef struct nodeTag LList;
struct nodeTag
{
LList* next;
Airport* airportPtr;
};

/* Function Prototypes */
	LList* makeList(LList*, Airport*);
	LList* insert(LList*, Airport*);
	LList* delete_airport(LList*, char*);
	Airport* find_airport(LList*, char*);
	int save(LList*, char*);
	void print_list(LList*);
	void delete_list(LList*);

#endif