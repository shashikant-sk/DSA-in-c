// WAP to read an array of integers and search for an element using binary search.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    printf("Enter the sorted array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int searchEl, flag = 0, l = 0, r = n - 1, mid = n / 2;
    printf("Enter element to search: ");
    scanf("%d", &searchEl);
    while (r >= l)
    {
        mid = l + (r - 1) / 2;
        if (searchEl > a[mid])
            l = mid + 1;
        else if (searchEl < a[mid])
            r = mid - 1;
        else
        {
            printf("%d found at position %d", searchEl, a[mid]);
            return 0;
        }
    }
    printf("%d not found in array!\n", searchEl);
    return 0;
}