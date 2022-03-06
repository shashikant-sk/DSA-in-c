// Given an unsorted dynamic array arr and two numbers x and y, find the minimum distance between x and y in arr. 
// The array might also contain duplicates. You may assume that both x and y are different and present in arr.
// Input: arr[] = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3}, x = 3, y = 6
// Output: Minimum distance between 3 and 6 is 4.
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int n,x,y,i,j,min_dist=1000000;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int *a = (int*)malloc(n*sizeof(int));
    printf("Enter the array elements: ");
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    printf("Enter x and y: ");
    scanf("%d %d",&x,&y);

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if ((x == a[i] && y == a[j]
                 || y == a[i] && x == a[j])
                && min_dist > abs(i - j)) {
                min_dist = abs(i - j);
            }
        }
    }

    printf("Minimum distance between %d and %d = %d\n",x,y,min_dist);
    free(a);
    return 0;
}