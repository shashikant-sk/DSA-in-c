// WARP using recursion to search an element in a dynamic array of n integers using binary search.
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *arr, int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int searchEl;
    printf("Enter element to search: ");
    scanf("%d", &searchEl);
    int bin = binarySearch(a,0,n-1,searchEl);
    if(bin==-1)printf("%d not found in array.\n",searchEl);
    else printf("%d found at position %d.\n",searchEl,bin+1);
    return 0;
}