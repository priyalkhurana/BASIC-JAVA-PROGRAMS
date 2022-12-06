#include <stdio.h>
#include <stdlib.h>
struct node {
    int num;
    struct node * prevptr;
    struct node * nextptr;
}*newnode, *nextnode;
void createlist(int n);
void display();
void main()
{
    int n;
    newnode = NULL;
    nextnode = NULL;
	printf("\n// Create and display a doubly linked list in reverse order :\n");
    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    createlist(n); 
    display();
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
                    printf(" Input element for node %d : ", i);
                    scanf("%d", &num);
                    funcnode->num = num;
                    funcnode->prevptr = nextnode; 
                    funcnode->nextptr = NULL;
                    newnode->nextptr = funcnode; 
                    nextnode = funcnode;   
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

void display()
{
    struct node * temp;
    int i= 0;
 
    if(nextnode == NULL)
    {
        printf(" No data found in the List yet.");
    }
    else
    {
        temp = nextnode;
        printf("\n Data in reverse order are :\n");
        while(temp != NULL)
        {
            printf("--> %d",  temp->num);
            i++;
            temp = temp->prevptr; 
         }
    }
} 