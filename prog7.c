#include <stdio.h>
#include <stdlib.h>
int arr[20];
typedef struct Node 
{
    int data;
    struct Node *next;
} Node;

void insert_beg_of_list(Node *cur, int data);
void display(Node *current);
void insert_beg_of_list(Node *cur, int data) 
{
    //keep track of first node
    Node *head = cur;
    while(cur->next != head) {
        cur = cur->next;
    }
    cur->next = (Node*)malloc(sizeof(Node));
    cur = cur->next;
    cur->data = data;
    cur->next = head;


}
void display(Node *current) 
{
    Node *head = current;
    current = current->next;
    while(current != head){
        printf(" %d ", current->data);
        current= current->next;
    }
}
int main()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = head;  
    int data = 0 ;
    int n= 0;
    int i,m;
    printf("ENTER NUMBER OF ELEMENTS OF ARRAY:");
     scanf("%d", &n);
    for (i=0; i<n; i++)
    {
     scanf("%d", &data);
    insert_beg_of_list(head, data);
   }
  printf("The list is ");
    display(head);
    return 0;
}