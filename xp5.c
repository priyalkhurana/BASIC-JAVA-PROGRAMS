
//stack implementation(menu driven+arrays) #13 april 2021#
#include<stdio.h>
int top=-1;
int max=10;
int stack[10];
void push(int ele)
{
    if(top==max-1)
    {
        printf("\noverflow!!\n");
    }
    else
    {    ++top;
        stack[top]=ele;
    }
}
void pop()
{
    int ele;
    if(top==-1)
    {
        printf("\nunderflow!!Can't delete more elements\n");
    }
    else
    {    ele=stack[top];
        --top;
        printf("\npopped element=%d",ele);
    }
}
void display()
{
    int i;
    for (i=top;i>=0;i--)  
    {  
        printf("-->%d\n",stack[i]);  
    }  
    if(top == -1)   
    {  
        printf("\nStack is empty"); 
    }
}   
void main()
{
    int exit=1,ele,ch;
    while(exit!=0)
    {
         printf("1.push\n2.pop\n3.display\n4.exit \nenter choice:: ");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("\nEnter element:");
            scanf("%d",&ele);
            push(ele);
        }
        if(ch==2)
        {
            pop();
        }
        if(ch==3)
        {
            display();
        }
        else if(ch==4)
        {
            exit==1;
        }
    }
}
