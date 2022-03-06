// You are given an array of 0s and 1s in random order. Segregate 0s on left side and 1s on right side of the array. 
// Traverse array only once.
#include<stdio.h>
#include<stdlib.h>

int main(){
    int size=0;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    int *a = (int*)malloc(size*sizeof(int));
    printf("Enter the elements of array(only 0 and 1): ");
    for(int i=0;i < size;i++)scanf("%d",&a[i]);

    int l = 0, r = size-1;
    while (l < r)
    {
        while (a[l] == 0 && l < r)l++;
        while (a[r] == 1 && l < r)r--;
        if (l < r)
        {
            a[l] = 0;
            a[r] = 1;
            l++;
            r--;
        }
    }

    for(int i=0;i < size;i++)printf("%d ",a[i]);
    printf("\n");
    return 0;
}