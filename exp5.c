#include <stdio.h>
int main()
{
  int c, beg, last, mid, n, search, arr[10];

  printf("Enter number of elements\n");
  scanf("%d", &n);

  printf("Enter %d integers\n", n);

  for (c = 0; c < n; c++)
    scanf("%d", &arr[c]);

  printf("Enter value to find\n");
  scanf("%d", &search);

  beg = 0;
  last = n - 1;
  mid = (beg+last)/2;

  while (beg <= last) {
    if (arr[mid] < search)
      beg = mid + 1;
    else if (arr[mid] == search) {
      printf("%d found at location %d.\n", search, mid+1);
      break;
    }
    else
      last = mid - 1;

    mid = (beg + last)/2;
  }
  if (beg > last)
    printf("Not found! %d isn't present in the list.\n", search);

  return 0;
}