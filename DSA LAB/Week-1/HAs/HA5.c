// WAP to replace every dynamic array element by multiplication of previous and next of an n element.
#include<stdio.h>
#include<stdlib.h>

int main(){
    int size=0,mul=1;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    int *a = (int*)malloc(size*sizeof(int));
    printf("Enter the elements of array: ");
    for(int i=0;i<size;i++)scanf("%d",&a[i]);

    for(int i=0;i<size;i++)mul*=a[i];
    for(int i=0;i<size;i++)a[i]=mul/a[i];

    printf("The replaced array is: ");
    for(int i=0;i<size;i++)printf("%d ",a[i]);
    printf("\n");
    free(a);
    return 0;
}