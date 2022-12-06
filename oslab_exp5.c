#include<stdio.h>
void main()
{
    int memorysize, pagesize, nop,p,rempages,logicaladdress;
    int pages[20],pno[20][20],i,j,x,y,offset;
    printf("\nEnter the memory size");
    scanf("%d",&memorysize);
    printf("\nEnter the page size: ");
    scanf("%d",&pagesize);
    nop= memorysize/pagesize;
    printf("\n The number of pages available in the memory are %d",nop);
    printf("\n Enter the number of processes: ");
    scanf("%d",&p);
    rempages=nop;
    for(i=1;i<=p;i++)
    {
        printf("\n Enter the number of pages required for process p[%d]",i);
        scanf("%d",&pages[i]);
        if(pages[i]>rempages)
        {
            printf("\nMemory is full");
            break;
        }
        rempages=rempages-pages[i];
        printf("\nEnter the page slot for process p[%d]",i);
        for(j=0;j<pages[i];j++)
        {
            scanf("%d",&pno[i][j]);
        }
    }
    printf("\nEnter the process number,page number and offset");
    scanf("%d %d %d",&x,&y,&offset);
    logicaladdress=pno[x][y-1]*pagesize+offset;
    printf("Logical address: %d",logicaladdress);
}