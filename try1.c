#include <stdio.h>
#include <conio.h>
#define MAX 10

int que[MAX];
int frnt_que = -1, rear_que = -1;
void add_elem(void);
int dlt_elem(void);
int peek(void);
void show(void);
int main(){
    int random, value;
    do{
        printf("\n 1. Insert the element ");
        printf("\n 2. Delete the element ");
        printf("\n 3. Peek");
        printf("\n 4. See the Queue");
        printf("\n 5. exit");
        printf("\n Enter your option : ");
        scanf("%d", &random);
        switch(random){
            case  1:
                    add_elem();
                    break;        
            case 2:
                    value = dlt_elem();
                    if(value!= -1)
                    printf("The Number that you deleted is:\t%d",value);
                    break;
            case 3:
                    value = peek();
                    if(value!= -1)
                    printf("The Number that you peeked is:\t%d",value);
                    break;
            case 4:
                    show();
                    break;
        }            
    }while(random != 5);
    getch();
    return 0;
}
void add_elem(){
    int n;
    printf("Enter the Numbe rthat you want to insert into the Queue:\t");
    scanf("%d", &n);
    if(rear_que == MAX - 1)
    printf("\nOVERFLOW CONDITION REACHED");
    else if(frnt_que==-1 && rear_que==-1)
    frnt_que = rear_que = 0;
    else
    rear_que++;
    que[rear_que] = n;
}
int dlt_elem(){
    int value;
    if(frnt_que == -1 || frnt_que > rear_que){
    printf("UNDERFLOW CONDITION REACHED");
    return -1;
    }
    else{
        value = que[frnt_que];
        frnt_que++;
        if(frnt_que > rear_que)
        frnt_que = rear_que = -1;
        return value;
    }
}
int peek(){
    if(frnt_que == -1 || frnt_que > rear_que){
    printf("EMPTY QUEUE");
    return -1;
    }
    else{
        return que[frnt_que];
    }
}
void show(){
    printf("\n");
     if(frnt_que == -1 || frnt_que > rear_que)
     printf("EMPTY QUEUE");
     else{
     for(int i = frnt_que;i <= rear_que;i++)
     printf("\t%d",que[i]);
     }
}