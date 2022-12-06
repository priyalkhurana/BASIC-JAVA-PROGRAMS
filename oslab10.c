#include<stdio.h>
int main()
{
    int n=5, m=3, i, j, k,l=0, flag=0;
    int completed[5], seq[5],need[5][3];
    int alloc[5][3]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{2,0,2}};
    int max[5][3]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
    int avail[3]={3,3,2};
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        completed[i]=0;
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            if(completed[i]==0)
            {
                flag=0;
                for(j=0;j<m;j++)
                {
                    if(need[i][j]>avail[j])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    seq[l++]=i;
                    for(int y=0;y<m;y++)
                    {
                        avail[y]=avail[y]+alloc[i][y];
                    }
                    completed[i]=1;
                }
            }
        }
    }
    if(l!=n)
    {
        printf("The system is under unsaafe state\n");
    }
    else
    {
        printf("The safe sequence is: \n");
        for(i=0;i<n;i++)
        {
            printf("\n P: %d",seq[i]);
        }
    }
    return 0;
}