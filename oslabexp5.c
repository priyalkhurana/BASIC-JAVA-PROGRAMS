
#include<stdio.h>
#include<stdlib.h>
 
int semaphore=1,full=0,empty=3,x=0;
 
int main()
{
	int n;
	void prod();
	void cons();
	int wait(int);
	int signal(int);
	printf("\n1.Producer\n2.Consumer\n3.Exit");
	while(1)
	{
		printf("\nEnter your choice:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:	if((semaphore==1)&&(empty!=0))
						prod();
					else
						printf("Buffer is full!!");
					break;
			case 2:	if((semaphore==1)&&(full!=0))
						cons();
					else
						printf("Buffer is empty!!");
					break;
			case 3:
					exit(0);
					break;
		}
	}
	
	return 0;
}
 
int wait(int k)
{
	return (--k);
}
 
int signal(int k)
{
	return(++k);
}
 
void prod()
{
	semaphore=wait(semaphore);
	full=signal(full);
	empty=wait(empty);
	x++;
	printf("\nProducer produces the item %d",x);
	semaphore=signal(semaphore);
}
 
void cons()
{
	semaphore=wait(semaphore);
	full=wait(full);
	empty=signal(empty);
	printf("\nConsumer consumes item %d",x);
	x--;
	semaphore=signal(semaphore);
}