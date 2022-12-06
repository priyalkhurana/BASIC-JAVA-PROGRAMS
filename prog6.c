#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
    int num;
    struct node * prevptr;
    struct node * nextptr;
}*newnode, *nextnode;
 

void createlist(int n);
int max(struct node *stnode);
void display();
int main()
{
    int n;
    newnode = NULL;
    nextnode = NULL;
	printf("\n\n// Find maximum  value from a doubly linked list :\n");
	printf(" Input the number of nodes : ");
    scanf("%d", &n);
    createlist(n); 
    display();
    printf("\n The Maximum Value in the Linked List : %d", max(newnode));
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
                    funcnode->nextptr = NULL;
 
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

int max(struct node *newnode)
{
    if(newnode == NULL){
        printf(" User message : Invalid Input !!!!\n");
        return INT_MIN;
    }
    int max = newnode->num;
    while(newnode != NULL){
        if(newnode->num > max){
            max = newnode->num;
        }
        newnode = newnode->nextptr;
    }
    return max;
}

void display()
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
        printf("\n\n Data entered in the list are :\n");
        while(temp != NULL)
        {
            printf("-->%d", temp->num);
            n++;
            temp = temp->nextptr; 
        }
    }
}