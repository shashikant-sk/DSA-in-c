// Given a sorted array of length n, WAP to find the number in array that appears more than or equal to n/2 times.
// It can be assumed that such element always exists.
// Input:  2 3 3 4 Output: 3
// Input:  3 4 5 5 5 Output: 5
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, max;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (i == 0)
            max = a[i];
        else if (max < a[i])
            max = a[i];
    }
    int *count = (int *)malloc(sizeof(int) * max);
    for (int i = 0; i < max; i++)
        count[i] = 0;
    for (int i = 0; i < n; i++)
        count[a[i]]++;
    for (int i = 0; i < max; i++)
        if (count[a[i]] >= n / 2)
        {
            printf("Answer: %d\n", a[i]);
            break;
        }
    return 0;
}