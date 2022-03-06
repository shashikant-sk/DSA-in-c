// WARP (Write a Recursive Program) to search an element in a dynamic array of n integers using linear search.
#include <stdio.h>
#include <stdlib.h>

int linearSearch(int *arr, int size, int x)
{
    int rec;
    size--;
    if (size >= 0)
        if (arr[size] == x)
            return size;
        else
            rec = linearSearch(arr, size, x);
    else
        return -1;
    return rec;
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
    int bin = linearSearch(a, n, searchEl);
    if (bin == -1)
        printf("%d not found in array.\n", searchEl);
    else
        printf("%d found at position %d.\n", searchEl, bin + 1);
    return 0;
}