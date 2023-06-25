#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cart.h"
#include "retail_item.h"
#include "tree.h"

/*
 * File containing the functions to interact with a tree structure 
 * CS305 HW 4
 * Author: Comingupwithnames
 * version: 1: Nov 16 2021
 */

/*****************************************************
 * newTreeNode
 * parameter: retail_item * item
 *
 * creates a new tree node and sets the appropriate fields
 *****************************************************/
tnode* newTreeNode(retail_item* item)
{
    tnode * toReturn = (tnode*)malloc(sizeof(tnode));
    toReturn->data = item;
    toReturn->left = NULL;
    toReturn->right = NULL;
    return toReturn;
}

/*****************************************************
 * insertByNumberR
 * parameter: tnode ** tptr
 * parameter: retail_item * item
 *
 * recursively searches for an appripriate space to place an item 
 * and compares the integer values of nodes to see where new node needs to be placed
 * if the tree is null, a new tree will be created
 *****************************************************/
void insertByNumberR(retail_item* item, tnode ** tptr)
{
    if(*tptr == NULL) //Checks if current tree pointer is null and creates a new node if so
    {
       *tptr = newTreeNode(item);
    } 
    else if(item->number < (*tptr)->data->number) //Checks to see if the item number is less than current node's number
    {
        insertByNumberR(item, &(*tptr)->left); //Moves left
    } 
    else if(item->number > (*tptr)->data->number) //Checks to see if the item number is greater than current node's number
    {
        insertByNumberR(item, &(*tptr)->right); //Moves right
    }
    else //Number is already in tree or something else happened
    {
      printf("Error, item name already in tree or other error.\n");
      return;
    }
}

/*****************************************************
 * insertByNameR
 * parameter: retail_item * item
 * parameter: tnode ** tptr
 *
 * recursively searches for an appripriate space to place an item 
 * and compares the strings of nodes to see where new node needs to be placed
 * if the tree is null, a new tree will be created
 *****************************************************/
void insertByNameR(retail_item* item, tnode ** tptr)
{
    if(*tptr == NULL) //Checks if current tree pointer is null and creates a new node if so
    {
       *tptr = newTreeNode(item);
    } 
    else if(strcmp(item->name, (*tptr)->data->name) <= -1) //Checks if the string of the current item is less than the one of the current node
    {
        insertByNameR(item, &(*tptr)->left); //Moves left
    } 
    else if(strcmp(item->name, (*tptr)->data->name) >= 1) //Checks if the string of the current item is greater than the one of the current node
    {
        insertByNameR(item, &(*tptr)->right); //Moves right
    }
    else //Name is already in tree or something else happened
    {
      printf("Error, item name already in tree or other error.\n");
      return;
    }
}

/*****************************************************
 * tree_search_number
 * parameter: tnode ** tptr
 * parameter: int target
 *
 * recurisively searches the tree for a specified number
 * unless it is already in the tree then it exits
 *****************************************************/
int tree_search_number(tnode** tptr, int target)
{
  static int count = 0; //Sets static int as a counter
    if(*tptr == NULL) //If curent node is null, number is not found
    {
        printf("Number not found.\n");
        return -1;
    }
    else if((*tptr)->data->number==target) //Checks to see if current node's number is equal to the target int
    {
        count++; //Increments counter
        printf("Number: %d has been found in the tree with %d comparisons, Printing item: ", target, count);
        print((*tptr)->data); //Prints item after it has been found
        return count;
    }
    else if(target < (*tptr)->data->number)
    {
      count ++; //Increments counter
      return tree_search_number(&(*tptr)->left, target);
    }
    else if(target > (*tptr)->data->number)
    {
      count ++; //Increments counter
      return tree_search_number(&(*tptr)->right, target);
    }
}

/*****************************************************
 * tree_search_name
 * parameter: tnode ** tptr
 * parameter: char * target
 *
 * recurisively searches the tree for a specified name
 * unless it is already in the list then it exits
 *****************************************************/
int tree_search_name(tnode** tptr, char* target)
{
  static int count = 0; //Sets static int as a counter
  if(*tptr == NULL) //Checks to see if the current node is null
    {
        printf("Item not found.\n");
        return -1;
    }
    else if(strcmp((*tptr)->data->name, target) == 0) //Checks to see if current node's name is equal to the target string
    {
      count++; //Increments counter
        printf("Name: %s has been found in the tree with %d comparisons, Printing item: ", target, count);
        print((*tptr)->data); //Prints item after it has been found
        return count;
    }
    else if(strcmp((*tptr)->data->name, target) < 0) //Checks to see if current node's string is less than the target one
    {
      count ++; //Increments counter
      return tree_search_name(&(*tptr)->right, target); //Moves right
    }
    else if(strcmp((*tptr)->data->name, target) > 0) //Checks to see if current node's string is greater than the target one
    {
      count ++; //Increments counter
      return tree_search_name(&(*tptr)->left, target); //Moves left
    }
}

/*****************************************************
 * free_tree
 * parameter: tnode ** tptr
 *
 * recurisively traverses the tree and frees each
 * retail item and then the node
 *****************************************************/
void free_tree(tnode** tptr)
{
  if(*tptr == NULL) //Checks to see if current node is null
  {
    return;
  }
  free_tree(&(*tptr)->left); //Traverses left
  free_tree(&(*tptr)->right); //Traverses right
  free(&(*tptr)->data); //Frees the retail item as the free_cart function already frees its name
  *tptr = NULL; //Sets the current node to null
  free(*tptr);
}

/*****************************************************
 * t_delete_number
 * parameter: tnode** tptr
 * parameter: int target
 *
 * Helper function for delete to delete a node
 * from t_number
 *****************************************************/
retail_item* t_delete_number(tnode** tptr, int target)
{
  tnode * curr = *tptr;
  tnode * found = NULL;
  tnode * parent = NULL;
  retail_item* toReturn = NULL;
  if(curr == NULL) // no data in tree
  { 
    return NULL;
  }
  while(curr != NULL) 
  {
    if(target == curr->data->number) 
    {
      found = curr;
      toReturn = found->data;
      break;
    } 
    else if(target < curr->data->number) 
    {
      parent = curr;
      curr = curr->left;
    } 
    else 
    {
      parent = curr;
      curr = curr->right;
    }
  }
  if(found == NULL) 
  {
    return NULL;   // not found in tree
  }

  // case 1: found is a leaf (just delete the node)
  if(found->left == NULL && found->right == NULL) 
  {
    // update parent's correct child
    if(parent == NULL) 
    {
      // found was the only node in the tree
      free(found);
      *tptr = NULL;
      return toReturn;  
    } 
    // parent is not null, so need to update its child to be null
    if(parent->left == found) 
    {
      parent->left = NULL;
    } 
    else if(parent->right == found) 
    {
      parent->right = NULL;
    } 
    else 
    {
      printf("something went wrong: parent has invalid children\n");
      return NULL;
    }
    free(found);
    return toReturn;
  }

  // case 2: found is an interior node with just one child on right side
  if(found->left == NULL) 
  {
    // determine if found is left or right child of parent
    if(parent->left == found) 
    {
      parent->left = found->right;
    } 
    else if(parent->right == found) 
    {
      parent->right = found->right;
    } 
    else 
    {
      printf("something went wrong: parent has invalid children\n");
      return NULL;
    }
    free(found);
    return toReturn;
  }

  // case 3: found is an interior node with just one child on the left side
  if(found->right == NULL) 
  {
    // determine if found is left or right child of parent
    if(parent->left == found) 
    {
      parent->left = found->left;
    } 
    else if(parent->right == found) 
    {
      parent->right = found->left;
    } 
    else 
    {
      printf("something went wrong: parent has invalid children\n");
      return NULL;
    }
    free(found);
    return toReturn;
  }
  // case 4: found is an interior node with two children
  // find next larger element in tree (go right, then go left as far as
  // possible)
  tnode * traverse = found->right;
  tnode * traverseParent = found;
  // now go left until reach a node with no left child
  while(traverse->left != NULL) 
  {
    traverseParent = traverse;
    traverse = traverse->left;
  }
  // at this point traverse should be the next largest node in the tree
  found->data = traverse->data;  // put data in found
  // check if traverse is a leaf node
  if(traverse->left == NULL && traverse->right == NULL) 
  {
    // leaf node -- just delete it
    if(traverseParent->left == traverse) 
    {
      traverseParent->left = NULL;
      free(traverse);
    } 
    else if(traverseParent->right == traverse) 
    {
      traverseParent->right = NULL;
      free(traverse);
    } 
    else 
    {
      printf("something went wrong: parent of traversed node has invalid children");
      return NULL;
    }
    return toReturn;
  }
  // traverse has a right subtree
  if(traverse->left == NULL && traverse->right != NULL) 
  {
    if(traverseParent->left == traverse) 
    {
      traverseParent->left = traverse->right;
      free(traverse);
    } 
    else if(traverseParent->right == traverse) 
    {
      traverseParent->right = traverse->right;
      free(traverse);
    }
  }
  return toReturn;
  // that is all the cases
}

/*****************************************************
 * t_delete_name
 * parameter: tnode** tptr
 * parameter: char* target
 *
 * Helper function for delete to delete a node
 * from t_name
 *****************************************************/
retail_item* t_delete_name(tnode** tptr, char* target)
{
  tnode * curr = *tptr;
  tnode * found = NULL;
  tnode * parent = NULL;
  retail_item* toReturn = NULL;
  if(curr == NULL) // no data in tree
  { 
    return NULL;
  }
  while(curr != NULL) 
  {
    if(strcmp(target, curr->data->name) == 0) 
    {
      found = curr;
      toReturn = found->data;
      break;
    } 
    else if(strcmp(target, curr->data->name) == -1) 
    {
      parent = curr;
      curr = curr->left;
    } 
    else 
    {
      parent = curr;
      curr = curr->right;
    }
  }
  if(found == NULL) 
  {
    return NULL;   // not found in tree
  }

  // case 1: found is a leaf (just delete the node)
  if(found->left == NULL && found->right == NULL) 
  {
    // update parent's correct child
    if(parent == NULL) 
    {
      // found was the only node in the tree
      free(found);
      *tptr = NULL;
      return toReturn;  
    } 
    // parent is not null, so need to update its child to be null
    if(parent->left == found) 
    {
      parent->left = NULL;
    } 
    else if(parent->right == found) 
    {
      parent->right = NULL;
    } 
    else 
    {
      printf("something went wrong: parent has invalid children\n");
      return NULL;
    }
    free(found);
    return toReturn;
  }

  // case 2: found is an interior node with just one child on right side
  if(found->left == NULL) 
  {
    // determine if found is left or right child of parent
    if(parent->left == found) 
    {
      parent->left = found->right;
    } 
    else if(parent->right == found) 
    {
      parent->right = found->right;
    } 
    else 
    {
      printf("something went wrong: parent has invalid children\n");
      return NULL;
    }
    free(found);
    return toReturn;
  }

  // case 3: found is an interior node with just one child on the left side
  if(found->right == NULL) 
  {
    // determine if found is left or right child of parent
    if(parent->left == found) 
    {
      parent->left = found->left;
    } 
    else if(parent->right == found) 
    {
      parent->right = found->left;
    } 
    else 
    {
      printf("something went wrong: parent has invalid children\n");
      return NULL;
    }
    free(found);
    return toReturn;
  }
  // case 4: found is an interior node with two children
  // find next larger element in tree (go right, then go left as far as
  // possible)
  tnode * traverse = found->right;
  tnode * traverseParent = found;
  // now go left until reach a node with no left child
  while(traverse->left != NULL) 
  {
    traverseParent = traverse;
    traverse = traverse->left;
  }
  // at this point traverse should be the next largest node in the tree
  found->data = traverse->data;  // put data in found
  // check if traverse is a leaf node
  if(traverse->left == NULL && traverse->right == NULL) 
  {
    // leaf node -- just delete it
    if(traverseParent->left == traverse) 
    {
      traverseParent->left = NULL;
      free(traverse);
    } 
    else if(traverseParent->right == traverse) 
    {
      traverseParent->right = NULL;
      free(traverse);
    } 
    else 
    {
      printf("something went wrong: parent of traversed node has invalid children");
      return NULL;
    }
    return toReturn;
  }
  // traverse has a right subtree
  if(traverse->left == NULL && traverse->right != NULL) 
  {
    if(traverseParent->left == traverse) 
    {
      traverseParent->left = traverse->right;
      free(traverse);
    } 
    else if(traverseParent->right == traverse) 
    {
      traverseParent->right = traverse->right;
      free(traverse);
    }
  }
  return toReturn;
  // that is all the cases
}

/*****************************************************
 * Delete
 * parameters: int number, llnode* list
 * parameters: tnode** tptr1, tnode** tptr2
 *
 * Driver function to delete a retail item from
 * all three data structures
 *****************************************************/

void Delete(int number, llnode* list, tnode** tptr1, tnode** tptr2)
{
  if(list == NULL || tptr1 == NULL || tptr2 == NULL)
  {
    return;
  }
  retail_item* toDelete = t_delete_number(tptr1, number);
  if(toDelete != NULL)
  {
  toDelete = t_delete_name(tptr2, toDelete->name);
  list = delete_item(list, number);
  }
  else
  {
    return;
  }

}


/*****************************************************
 * printNumberWithTab
 * parameter: int n
 * parameter: int data
 *
 * Helper function for printNumberTree to try to
 * replicate the structure of a tree
 *****************************************************/
void printNumberWithTab(int n, int data) 
{
  int i = 0;
  for(i = 0; i < n; i++) 
  {
    printf("   ");
  }
  printf("%d\n", data);
}

/*****************************************************
 * printNumberR
 * parameter: int n
 * parameter: tnode * t
 *
 * recurisively calls itself and printNumberWithTab
 * to print an entire tree
 *****************************************************/
void printNumberR(int n, tnode * t) 
{
  if(t == NULL) //Checks to see if current node is null
  {
    printNumberWithTab(n, 0);  // note: value 0 is used to indicate null
    return;
  }
  printNumberWithTab(n, t->data->number); //Prints current number
  printNumberR(n+1, t->right); //Traverses right and increments n
  printNumberR(n+1, t->left); //Traverses left and increments n
}

/*****************************************************
 * printNumberTree
 * parameter: tnode * t
 *
 * driver dunction for printing a tree of item numbers
 *****************************************************/
void printNumberTree(tnode * t) 
{
  printf("\nTREE:\n");
  printNumberR(0, t);
}

/*****************************************************
 * printNameWithTab
 * parameter: int n
 * parameter: char * data
 *
 * Helper function for printNameTree to try to
 * replicate the structure of a tree
 *****************************************************/
void printNameWithTab(int n, char* data) 
{
  int i = 0;
  for(i = 0; i < n; i++) 
  {
    printf("   ");
  }
  printf("%s\n", data);
}

/*****************************************************
 * printNameR
 * parameter: int n
 * parameter: tnode * t
 *
 * recurisively calls itself and printNameWithTab
 * to print an entire tree
 *****************************************************/
void printNameR(int n, tnode * t) 
{
  if(t == NULL) //Checks to see if current node is null
  {
    printNameWithTab(n, "");  // note: "" is used to indicate null
    return;
  }
  printNameWithTab(n, t->data->name); //Prints current name
  printNameR(n+1, t->right); //Traverses right and increments n
  printNameR(n+1, t->left); //Traverses left and increments n
}

/*****************************************************
 * printNameTree
 * parameter: tnode * t
 *
 * driver function for printing a tree of item names
 *****************************************************/
void printNameTree(tnode * t) 
{
  printf("\nTREE:\n");
  printNameR(0, t);
}