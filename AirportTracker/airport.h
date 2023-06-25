#ifndef AIRPORT_H
#define AIRPORT_H

typedef struct Airport{
char TAG[4];
char* airportName;
char* city;
char* country;
}Airport;

/* function prototypes */
Airport* make_airport(char*,char*,char*,char*);
void print_airport(Airport*);
void printf_airport(Airport*, FILE*);
void free_airport(Airport*);

#endif