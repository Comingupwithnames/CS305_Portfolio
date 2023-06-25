#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "fastLookup.h"

/*****************************************************
 * llist_search_number
 * parameter: llnode * list
 * parameter: int target
 *
 * recurisively searches for a specified number
 * and prints appropriate error checks 
 ****************************************************
 */
int llist_search_number(llnode * list, int target)
{
    static int count = 0;
    if(list == NULL)
    {
        printf("List is empty or item not found.\n");
        return -1;
    }
    else if(target == list->item->number)
    {
        count++;
        printf("Item is contained in the list. Number of comparisons made: %d\n", count);
        return count;
    }
    else
    {
        count++;
        list = list->next;
        llist_search_number(list, target);
    }
}

/*****************************************************
 * llist_search_name
 * parameter: llnode * list
 * parameter: char * target
 *
 * recurisively searches for a specified name
 * and prints appropriate error checks 
 ****************************************************
 */
int llist_search_name(llnode * list , char* target)
{
    static int count = 0;
    if(list == NULL)
    {
        printf("List is empty or item not found.\n");
        return -1;
    }
    else if(strcmp(target, list->item->name) == 0)
    {
        count++;
        printf("Item is contained in the list. Number of comparisons made: %d\n", count);
        return count;
    }
    else
    {
        count++;
        list = list->next;
        llist_search_name(list, target);
    }
}