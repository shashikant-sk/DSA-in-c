// WAP to arrange the elements of a dynamic array such that all even numbers are followed by all odd numbers using a single loop.
#include<stdio.h>
#include<stdlib.h>

int main(){
    int size=0;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    int *a = (int*)malloc(size*sizeof(int));
    printf("Enter the elements of array: ");
    for(int i=0;i < size;i++)scanf("%d",&a[i]);

    for(int i=0;i < size-1;i++)
        for(int j=i+1;j < size;j++)
            if(a[i]%2 == 0 && a[j]%2){
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }

    printf("Array after ordering: \n");
    for(int i=0;i < size;i++)printf("%d ",a[i]);
    printf("\n");
    return 0;
}