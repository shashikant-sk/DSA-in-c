// WAP to read an array of integers and search for an element using linear search.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int searchEl, flag = 0;
    printf("Enter element to search: ");
    scanf("%d", &searchEl);
    for (int i = 0; i < n; i++)
        if (a[i] == searchEl)
        {
            printf("%d found at position %d in the array\n", searchEl, i + 1);
            flag = 1;
        }
    if (!flag)
        printf("%d not found in array!\n", searchEl);
    return 0;
}