/*#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node * prevptr;
    struct node * nextptr;
}*newnode, *nextnode;
 

void createlist(int n);
void deletefunc(int pos);
void display(int m);
int main()
{
    int n,num,a,pos;
    newnode = NULL;
    nextnode = NULL;
	printf("\n\n//Delete node from middle of a doubly linked list :\n");   	
    printf(" Input the number of nodes: ");
    scanf("%d", &n);
    createlist(n); 
    a=1;
    display(a);
    printf(" Input the position to delete a node (!=1): ");
    scanf("%d", &pos);

    if((pos<=1) || (pos>=n))
    {
     printf("\n Invalid position. Try again.\n ");
    }
	 if((pos>1) && (pos<n))
      {
 
        deletefunc(pos);  
        a=2;
         display(a);
    }      
    return 0;
    
}
 
void createlist(int n)
{
    int i, num;
    struct node *funcnode;
    if(n >= 1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
 
        if(newnode != NULL)
        {
            printf(" Input element for node 1 : "); 
            scanf("%d", &num);
            newnode->num = num;
            newnode->prevptr = NULL;
            newnode->nextptr = NULL;
            nextnode = newnode;
            for(i=2; i<=n; i++)
            {
                funcnode = (struct node *)malloc(sizeof(struct node));
                if(funcnode != NULL)
                {
                    printf(" Input data for node %d : ", i);
                    scanf("%d", &num);
                    funcnode->num = num;
                    funcnode->prevptr = nextnode; 
                    funcnode->nextptr = NULL; 
                    nextnode->nextptr = funcnode;   
                   newnode = funcnode;    
                }
                else
                {
                    printf(" Memory can not be allocated.");
                    break;
                }
            }
        }
        else
        {
            printf(" Memory can not be allocated.");
        }
    }
}

void deletefunc(int pos)
{
    struct node *curNode;
    int i;
 
    curNode = newnode;
    for(i=1; i<pos && curNode!=NULL; i++)
    {
        curNode = curNode->nextptr;
    }
    if(curNode != NULL)
    {
        curNode->prevptr->nextptr = curNode->nextptr;
        curNode->nextptr->prevptr = curNode->prevptr;
 
        free(curNode); 
    }
    else
    {
        printf(" The given position is invalid!\n");
    }
} 
void display(int m)
{
    struct node * temp;
    if(newnode == NULL)
    {
        printf(" No data found in the List yet.");
    }
    else
    {
        temp = newnode;
        if (m==1)
        {
        printf("\n Data entered in the list are :\n");
        }
        else
        {
         printf("\n After deletion the new list are :\n");   
        }
        while(temp != NULL)
        {
            printf("--> %d", temp->num);
            temp = temp->nextptr; 
        }
    }
}*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node * prevptr;
    struct node * nextptr;
}*newnode, *nextnode;
 

void createlist(int n);
void deletefunc(int pos);
void display(int a);

int main()
{
    int n,num1,a,pos;
    newnode = NULL;
    nextnode = NULL;
	printf("\n// Delete node from middle of a doubly linked list :\n");	   	
    printf(" Input the number of nodes (3 or more ): ");
    scanf("%d", &n);
    createlist(n); 
    a=1;
    display(a);
    printf(" Input the position ( 2 to %d ) to delete a node : ",n-1);
    scanf("%d", &pos);

if(pos<=1 || pos>=n)
    {
     printf("\n Invalid position. Try again.\n ");
    }
	      if(pos>1 && pos<n)
      {
 
    deletefunc(pos);  
        a=2;
    display(a);
      }      
    return 0;
}
 
void createlist(int n)
{
    int i, num;
    struct node *funcnode;
 
    if(n >= 1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
 
        if(newnode != NULL)
        {
            printf(" Input data for node 1 : "); // assigning data in the first node
            scanf("%d", &num);
 
            newnode->num = num;
            newnode->prevptr = NULL;
            newnode->nextptr = NULL;
            nextnode = newnode;
            for(i=2; i<=n; i++)
            {
                funcnode = (struct node *)malloc(sizeof(struct node));
                if(funcnode != NULL)
                {
                    printf(" Input data for node %d : ", i);
                    scanf("%d", &num);
                    funcnode->num = num;
                    funcnode->prevptr = nextnode;    // new node is linking with the previous node
                    funcnode->nextptr = NULL;     // set next address of fnnode is NULL
                    nextnode->nextptr = funcnode;   // previous node is linking with the new node
                    nextnode = funcnode;            // assign new node as last node
                }
                else
                {
                    printf(" Memory can not be allocated.");
                    break;
                }
            }
        }
        else
        {
            printf(" Memory can not be allocated.");
        }
    }
}

void deletefunc(int pos)
{
    struct node *curNode;
    int i;
 
    curNode = newnode;
    for(i=1; i<pos && curNode!=NULL; i++)
    {
        curNode = curNode->nextptr;
    }
    if(curNode != NULL)
    {
        curNode->prevptr->nextptr = curNode->nextptr;
        curNode->nextptr->prevptr = curNode->prevptr;
 
        free(curNode); //Delete the n node
    }
    else
    {
        printf(" The given position is invalid!\n");
    }
} 

void display(int m)
{
    struct node * temp;
    int n = 1;
    if(newnode == NULL)
    {
        printf(" No data found in the List yet.");
    }
    else
    {
        temp = newnode;
        if (m==1)
        {
        printf("\n Data entered in the list are :\n");
        }
        else
        {
         printf("\n After deletion the new list are :\n");   
        }
        while(temp != NULL)
        {
            printf("--> %d", temp->num);
            n++;
            temp = temp->nextptr; // current pointer moves to the next node
        }
    }
}