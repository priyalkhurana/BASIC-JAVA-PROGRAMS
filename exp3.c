#include <stdio.h>
#include <conio.h>
#define size 10
void insertion_sort(int arr[], int n);
void main()
{
    int arr[size], i, n;
    printf("\n Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("\n Enter the elements of the array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    insertion_sort(arr, n);
    printf("\n The sorted array is: \n");
    for(i=0;i<n;i++)    
    printf(" %d\t", arr[i]);
    int position;
    printf("\n\nEnter the location where you want to delete element from:  ");
    scanf("%d", &position);
    int c;
    if(position >= n+1)
        printf("\n\nDeletion not possible\n\n");
    else 
        for(c = position-1; c < n-1; c++)
        arr[c] = arr[c+1];

    printf("\n\nResultant array is: ");
    for(c = 0; c < n-1; c++) 
        printf("%d  ", arr[c]);
}
void insertion_sort(int arr[], int n)
{
    int i, j, temp;
    for(i=1;i<n;i++)    
    {
        temp = arr[i];
         j = i-1;
    while((temp < arr[j]) && (j>=0))
    {
        arr[j+1] = arr[j];
        j--;
     }
    arr[j+1] = temp;
    }
}