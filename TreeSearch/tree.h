#ifndef TREE_H
#define TREE_H

#include "cart.h" 
#include "retail_item.h"

/* tnode struct define as a binary tree with left and right nodes
   each node has retail_item data and a pointer to the next cart item
*/
typedef struct tnode_tag tnode;
struct tnode_tag {
  retail_item* data;   // item stored in the tree node
  tnode* left; //Left node of the tree
  tnode* right; //Right node of the tree      
};

/* function prototypes (seperated into categorical functions for ease of reading)*/
tnode* newTreeNode(retail_item*);

void insertByNumberR(retail_item*, tnode **);
void insertByNameR(retail_item*, tnode **);

int tree_search_number(tnode**, int);
int tree_search_name(tnode**,char*);

void free_tree(tnode**);

retail_item* t_delete_number(tnode**, int);
retail_item* t_delete_name(tnode**, char*);
void Delete(int, llnode*, tnode**, tnode**);

void printNumberWithTab(int, int);
void printNumberR(int, tnode*);
void printNumberTree(tnode*);

void printNameWithTab(int, char*);
void printNameR(int, tnode*);
void printNameTree(tnode*);

#endif
