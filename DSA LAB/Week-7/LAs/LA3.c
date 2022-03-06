// Given an array container and integer hunt. WAP to find whether hunt is present in container or not.
// If present, then triple the value of hunt and search again. Repeat these steps until hunt is not found.
// Finally return the value of hunt.
// Input: container = {1, 2, 3} and hunt = 1 then Output: 9
// Explanation: Start with hunt = 1. Since it is present in array, it becomes 3. Now 3 is present in array and hence hunt becomes 9.
// Since 9 is a not present, program return 9.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter size of container: ");
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    printf("Enter the container elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int searchEl, flag = 0;
    printf("Enter hunt: ");
    scanf("%d", &searchEl);
    while (1)
    {
        int flag = 0;
        for (int i = 0; i < n; i++)
            if (a[i] == searchEl)
            {
                searchEl *= 3;
                flag = 1;
                break;
            }
        if (!flag)
            break;
    }
    printf("Final value of hunt = %d\n", searchEl);
    return 0;
}