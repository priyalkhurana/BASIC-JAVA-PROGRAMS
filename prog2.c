#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int num;                    
    struct node *nextptr;   
}*newnode;
void createNodeList(int n);
void reverseDispList();    
void displayList();        

void main()
{
    int n;
	printf("\n //Create a singly linked list and print it in reverse order :\n");	
    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    createNodeList(n);	
    displayList();
    reverseDispList();
    printf("\n The list in reverse are :  \n");
    displayList();
}
void createNodeList(int n)
{
    struct node *funcnode, *temp;
    int num, i;
    newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode == NULL) 
   {
        printf(" Memory can not be allocated.");
    }
    else
    {
        printf(" Input data for node 1 : ");
        scanf("%d", &num);
        newnode-> num = num;      
        newnode-> nextptr = NULL;
        temp = newnode;
        for(i=2; i<=n; i++)
        {
            funcnode = (struct node *)malloc(sizeof(struct node));
            if(funcnode == NULL) 
             {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);
                scanf(" %d", &num);
                funcnode->num = num;     
                funcnode->nextptr = NULL;
                temp->nextptr = funcnode;
                temp = temp->nextptr;
            }
        }
    }
}

void reverseDispList()
{
    struct node *prevNode, *curNode;
 
    if(newnode != NULL)
    {
        prevNode = newnode;
        curNode = newnode->nextptr;
        newnode = newnode->nextptr;
        prevNode->nextptr = NULL; 
        while(newnode != NULL)
        {
            newnode = newnode->nextptr;
            curNode->nextptr = prevNode;
 
            prevNode = curNode;
            curNode = newnode;
        }
        newnode = prevNode; 
    }
}

void displayList()
{
    struct node *temp;
    if(newnode == NULL)
    {
        printf(" No data found in the list.");
    }
    else
    {
        temp = newnode;
        while(temp != NULL)
        {
            printf("---> %d", temp->num);   
            temp = temp->nextptr;                 
        }
    }
}