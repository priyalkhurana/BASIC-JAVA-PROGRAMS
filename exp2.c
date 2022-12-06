//bubble sort
/* #include <stdio.h>
#define size 10
void bubble_sort(int a[],int s);
void main()
{
    int arr[size], i, n;
    printf("\n Enter the number of elements in the array : ");
    scanf("%d", &n);
    printf("\n Enter the elements of the array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    bubble_sort(arr,n);
    printf("Array after iteration ");
    //for(int k=0;i<n;k++)
    //printf(" %d\t", arr[k]);

}
void bubble_sort(int arr[],int s)
{
    int temp=0;
    for( int i=0;i<s;i++)
    {
        for( int j=0;j<(s-1);j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    for(int k=0;i<s;k++)
    printf(" %d\t", arr[k]);
       
    }
}*/
#include<stdio.h>

int main(){

   int count, temp, i, j, arr[10];

   printf("Elements to be enteres? ");
   scanf("%d",&count);

   printf("Enter %d numbers: ",count);

   for(i=0;i<count;i++)
   scanf("%d",&arr[i]);
   for(i=count-2;i>=0;i--)
   {
      for(j=0;j<=i;j++)
      {
        if(arr[j]>arr[j+1]){
           temp=arr[j];
           arr[j]=arr[j+1];
           arr[j+1]=temp;
        }
      }
   }

   printf("Sorted array is:: ");
   for(i=0;i<count;i++)
      printf(" %d",arr[i]);

   return 0;
}