
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "graph.h"

/*
 * File containing dijkstra's algorithm to find the shortest distance from one node to the other
 * CS305 HW 5
 * Author: Comingupwithnames
 * version 1: Nov 30 2021
 */


/* 
 * dijkstra
 * main function to find all costs from the source node to other nodes
 */
void dijkstra(Graph * g, char * source)
{
    if(g == NULL)
    {
        return;
    }
    int index = -1;
    for(int i = 0; i<g->V; i++)
    {
        if(strcmp(source, g->array[i].label)==0) //Checks to see if source is equal to the label of array[i]
        {
            index = i;
        }
    }
    if(index != -1)
    {
        g->array[index].dValue = 0; //Sets dValue of source node to zero
    }
    else
    {
        return; //If index has not changed, returns
    }

    while(!isEmpty(g) && getMin(g) != -1)//Checks to see if the graph is not empty as well as all nodes are not black
    {
        int U = getMin(g);
            AdjListNode* curr = g->array[U].head;
            while(curr != NULL)
            {
                if(g->array[curr->dest].dValue > g->array[U].dValue + curr->cost)
                {
                    g->array[curr->dest].dValue = g->array[U].dValue + curr->cost;
                    g->array[curr->dest].pred = U;
                }
                curr = curr->next;
            }
            g->array[U].color = BLACK;  
    }  
} 

/* 
 * isEmpty
 * Helper function that checks to see if at least one node is still white
 */
int isEmpty(Graph * g)
{
    if(g == NULL)
    {
        return 1;
    }
    
    for (int i = 0; i < g->V; i++) 
    {
        if(g->array[i].color == WHITE)
        {
            return 0;
        }

    }  
    return 1; 
}

/* 
 * getMin
 * Helper function that returns the min index of a white node
 * by comparing the dValues
 */
int getMin(Graph * g)
{
    if(g == NULL)
    {
        return -1;
    }
    int min = INT_MAX;//Sets the min to infinity for convinience
    int index = -1; //Index is out of bounds so no specific index is favored
    for(int i = 0; i< g->V; i++)
    {
        if(g->array[i].color == WHITE)
        {
            if(min > g->array[i].dValue)
            {
                min = g->array[i].dValue;
                index = i;
            }
        }
    }
    return index;
}
