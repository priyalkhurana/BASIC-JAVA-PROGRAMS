#include<stdio.h>
struct Node 
{ 
  int data; 
  struct Node *next; 
}*head, *Node; 
void create_empty(struct Node* head)
{
    head== NULL;
}
void insert(struct Node* head_ref, int info) 
{ 
    Node *new_node;
    new_node = (( Node*)malloc(sizeof(Node))); 
    new_node->data  = info;
    if( head_ref== NULL)
    {
        new_node->next=NULL;
    }
    else
    {
        new_node->next= (head_ref);
    } 
    (head_ref)    = new_node; 
} 
/*void insert_end(struct Node** head_ref,int info)
{
    
}*/
void display(struct Node *node) 
{ 
  while (node != NULL) 
  { 
     printf(" %d ", node->data); 
     node = node->next; 
  } 
} 
void main()
{
    head=NULL;
    create_empty(head);
    insert(head,10);
    display(head);
}

