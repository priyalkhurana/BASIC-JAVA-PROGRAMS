//linear search
#include <stdio.h>
int main()
{
  int arr[10], pos, c, n;

  printf("Enter numbers of elements in array\n");
  scanf("%d", &n);

  printf("Enter %d elements\n", n);

  for (c = 0; c < n; c++)
    scanf("%d", &arr[c]);

  printf("Enter a number to search\n");
  scanf("%d", &pos);

  for (c = 0; c < n; c++)
  {
    if (arr[c] == pos)    
    {
      printf("%d is present at position %d.\n", pos, c+1);
      break;
    }
  }
  if (c == n)
    printf("element not found!\n", pos);

  return 0;
}