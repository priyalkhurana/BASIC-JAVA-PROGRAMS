#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int num;                
    struct node *nextptr;   
}*newnode;
void createlist(int n); 
void displayList();         
void main()
{
    int n;
	printf("\n\n//To create and display Singly Linked List :\n");
    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    createlist(n);
    printf("\n Data entered in the list : \n");
    displayList();
}
void createlist(int n)
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
        newnode->num = num;      
        newnode->nextptr = NULL; 
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
                printf(" Input element for node %d : ", i);
                scanf(" %d", &num);
 
                funcnode->num = num;      
                funcnode->nextptr = NULL; 
 
                temp->nextptr = funcnode; 
                temp = temp->nextptr; 
            }
        }
    }
}
void displayList()
{
    struct node *temp;
    if(newnode == NULL)
    {
        printf(" List is empty.");
    }
    else
    {
        temp = newnode;
        while(temp != NULL)
        {
            printf(" ---> %d", temp->num);      
            temp = temp->nextptr;   
        }
    }
} 