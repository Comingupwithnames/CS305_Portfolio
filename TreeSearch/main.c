/****************************************************
 * HW 4: starter code for search tree assignments.
 * Fall 2021
 * 
 * Used code from tree lab to implement deleting tree nodes
 *
 * compile with cart.c and retail_item.c
 * see makefile
 * compile: make
 * cli usage: ./run <input file with items>
 * the input file has <int: number> <string: name> <int:price>
 ****************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include "cart.h"
#include "retail_item.h"
#include "fastLookup.h"
#include "tree.h"

/* prototypes */
int run_test(char* );

/****************************************************************
 * main 
 * using void paramater since we are not using command line 
 * arguments for this program
 ****************************************************************
 */
int main(int argc, char* argv[]) {
  if (argc != 2){
    perror("Usage: ./run <input file with items>. Exiting");
    exit(EXIT_FAILURE);
  }
  run_test(argv[1]);
}

/*************************************************************** 
 * run_test
 * runs a test, creating carts and adding/deleting items
 ***************************************************************
 */
int run_test(char* fn) {
  /* create two carts */
  /* note: using pointers for carts so the cart data can be 
     modified */
  FILE* fp = fopen(fn, "r");
  if(fp==NULL){
    perror("Cannot open input file");
    exit(EXIT_FAILURE);
  }
  llnode* fred = create_cart();

  /* create retail items */
  /* note: not using pointers to retail_items since once they are created
   * they are not later modified -- only used as data */
  int rc, number, price;
  char* name;
  while(fscanf(fp, " %d %ms %d \n",&number, &name ,&price) != EOF){
    printf("Adding: %d %s %d\n", number, name, price);
    add_item(&fred, create_retail_item(number, name, price));
  }
  fclose(fp);

  /* print the cart */
  print_cart(fred);

  /* delete item */
  printf("Trying to delete item 1234\n"); 
  fred = delete_item(fred, 1234);
  print_cart(fred);

  /* delete item */
  printf("Trying to delete item 10000\n");
  fred = delete_item(fred, 10000);
  print_cart(fred);

  /* 
  printf("Trying to delete item 3222\n");
  fred = delete_item(fred, 3222);
  printf("Trying to delete item 3033\n");
  fred = delete_item(fred, 3033);
  printf("Trying to delete item 2121\n");
  fred = delete_item(fred, 2121);
  printf("Trying to delete item 1234\n");
  fred = delete_item(fred, 1234);
  printf("Trying to delete item 1001\n");
  fred = delete_item(fred, 1001);
  print_cart(fred);
  */
   /* searches the list for two arbituary numbers and one name */
  //llist_search_number(fred, 8000);
  //llist_search_name(fred, "RedGrapes");
  //llist_search_number(fred, 100000);


  tnode * t_number = NULL; //Creates a tree to represent a tree of numbers
  tnode * t_name = NULL; //Creates a tree to represent a tree of names
  llnode * tmp = fred; //Tempoarary tree so that original tree does not get lost and memory is leaked

  while(tmp !=NULL)
  {
    insertByNumberR(tmp->item, &t_number); //Inserts tmp numbers into t_number
    insertByNameR(tmp->item, &t_name); //Inserts tmp names into t_name
    tmp = tmp->next; //Goes to the next node in the list
  }

/* commented out runtime function */
/*
llnode * tmp3 = fred;
while(tmp3 != NULL)
{  
  tree_search_number(&t_number, tmp3->item->number);
  tmp3 = tmp3->next;
}
*/
  /* searches the tree for three arbituary numbers */
  //tree_search_number(&t_number, 8000);
  //tree_search_number(&t_number, 10);
  //tree_search_number(&t_number, -1);

  /* searches the tree for three arbituary namess */
  //tree_search_name(&t_name, "RedGrapes");
  //tree_search_name(&t_name, "Snickers");
  //tree_search_name(&t_name, "ChipsAhoy");

  /* deleting items from all three structures */
  //Delete(8000, fred, &t_number, &t_name);

  /* print the trees themselves */
  //printNumberTree(t_number);
  //printNameTree(t_name);

  /* free memory for trees */
  free_tree(&t_number);
  free_tree(&t_name);
  
  /* free memory for cart */
  free_cart(fred);

  return EXIT_SUCCESS;
} /* end run_test */
