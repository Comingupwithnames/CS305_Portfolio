#include <stdio.h>
#include <stdlib.h>

typedef struct LLNodeTag LLNode;
struct LLNodeTag {
    int data;
    LLNode* next;
}LLNodeTag;

LLNode* insertHead(int info, LLNode* rt)
{
    LLNode* tmp = (LLNode*)
    malloc(sizeof(LLNodeTag));
    tmp->data = info;
    tmp->next = rt;
    return tmp;
}
/*
LLNode* deleteSecond(LLNode* rt)
{
 if(rt==NULL) 
 {
     return rt;
 } 
 if(rt->next == NULL)
 {
     return rt;
 } 
 LLNode* tmp = rt;
 LLNode* new_rt = rt->next;
 rt = rt->next;
 free(tmp);
 while(rt!=NULL)
 {
     tmp = rt;
     rt=rt->next;
     if(rt==NULL)
     {
         return new_rt;
     }
     else
     {
        tmp->next = rt->next;
     }
     free(rt);
     rt = tmp->next;
 }
 return new_rt;
} 
*/
LLNode* deleteSecondRec(LLNode* rt){

if(rt==NULL) 
{
    return rt;
}
else if(rt->next == NULL) 
{
    return rt;
}
else
{
    LLNode* tmp = rt;
    LLNode* new_rt = rt->next;
    free(rt);
    return deleteSecondRec(new_rt);
}
}


void print(LLNode* rt)
{
    while(rt!=NULL)
    {
        printf("%d ", rt->data);
        rt = rt->next;
    }
}

void main(void)
{
    LLNode* root = NULL;
    root = insertHead(5,root);
    root = insertHead(15,root);
    root = insertHead(25,root);
    root = insertHead(35,root);
    root = insertHead(45,root);
    root = insertHead(55,root);
    root = insertHead(65,root);
    printf("\nOR:\n");
    print(root);
    root = deleteSecondRec(root);
    printf("\nDel:\n");
    print(root);
}