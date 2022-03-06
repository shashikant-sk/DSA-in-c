//•	WAP to find out the smallest and largest element stored in an array of n integers.
#include<stdio.h>
#include<stdlib.h>

int main(){
    int size=0,large=0,small=0;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    int *a = (int*)malloc(size*sizeof(int));
    printf("Enter the elements of array: ");
    for(int i=0;i<size;i++)scanf("%d",&a[i]);
    large=small=a[0];
    for(int i=1;i<size;i++){
        if(a[i]>large)large=a[i];
        if(a[i]<small)small=a[i];
    }
    printf("Largest element = %d\n",large);
    printf("Smallest element = %d\n",small);
    return 0;
}