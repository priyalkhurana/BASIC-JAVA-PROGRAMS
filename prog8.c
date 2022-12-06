#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coef,expo;
    struct node* next;
};
struct node* insert(struct node* poly,int a,int b);
struct node* append(struct node* poly,int a,int b);
struct node* polyaddition(struct node* p1poly,struct node* p2poly);
void display(struct node* poly);

void main()
{
    int a,b,n,i;
    struct node* p1head,* p2head,* p3head;
    p1head=p2head=NULL;
     printf("Enter the no of terms of polynomial 1..");
    scanf("%d",&n);
    printf("\nEnter the polynomial..");
    for(i=0;i<n;i++){
        printf("\nEnter the coefficient and exponent of the term..");
        scanf("%d%d",&a,&b);
        p1head=insert(p1head,a,b);
    }
    printf("\nEnter the no of terms of polynomial 2..");
    scanf("%d",&n);
    printf("\nEnter the polynomial..");
    for(i=0;i<n;i++){
        printf("\nEnter the coefficient and exponent of the term..");
        scanf("%d%d",&a,&b);
        p2head=insert(p2head,a,b);
    }
    p3head=polyaddition(p1head,p2head);
    printf("\npolynomial 1::");
    display(p1head);
    printf("\npolynomial 2::");
    display(p2head);
    printf("\nThe sum of the two polynomials is..");
    display(p3head);
}
struct node* append(struct node* poly,int a,int b)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coef=a;
    newnode->expo=b;
    if(poly==NULL)
    {
    newnode->next=NULL;
    return newnode;
    }
    struct node* trav=poly;
    while(trav->next!=NULL) 
    trav=trav->next;
    trav->next=newnode;
    newnode->next=NULL;
    return poly;
}

struct node* insert(struct node* poly,int a,int b)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coef=a;
    newnode->expo=b;
    if(poly==NULL)
    {           
        newnode->next=NULL;
        return newnode;
    }
    struct node* prev,* cur;
    prev=cur=poly;
    while(cur!=NULL && cur->expo>b)
    {
        prev=cur;
        cur=cur->next;
    }
    if(cur==poly)
    {            
        newnode->next=cur;
        return newnode;
    }
    else if(cur==NULL)
    {
         prev->next=newnode;
        newnode->next=NULL;
    }
    else{
        newnode->next=cur;
        prev->next=newnode;
    }
    return poly;
}
struct node* polyaddition(struct node* p1thead,struct node* p2thead)
{
    struct node* ans=NULL;
    struct node* t1,* t2;
    t1=p1thead;
    t2=p2thead;
    while(t1!=NULL && t2!=NULL){
        if(t1->expo > t2->expo){
            ans=append(ans,t1->coef,t1->expo);
            t1=t1->next;
        }
        else if(t1->expo < t2->expo){
            ans=append(ans,t2->coef,t2->expo);
            t2=t2->next;
        }
        else{
            ans=append(ans,(t1->coef)*(t2->coef),t1->expo);
            t1=t1->next;
            t2=t2->next;
        }
    }
    while(t1!=NULL){            
        ans=append(ans,t1->coef,t1->expo);
        t1=t1->next;
    }
    while(t2!=NULL){            
        ans=append(ans,t2->coef,t2->expo);
        t2=t2->next;
    }
    return ans;
}
void display(struct node* poly)
{
    struct node* temp=poly;
    if(temp==NULL){
        printf("\nEmpty..");
    }
    else{
        while(temp->next!=NULL){
            printf(" %dx^%d +",temp->coef,temp->expo);
            temp=temp->next;
        }
       printf(" %dx^%d ",temp->coef,temp->expo);
    }
}