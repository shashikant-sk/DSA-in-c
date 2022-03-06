// Write a program to replace every element in the dynamic array with the next greatest element present in the same array.
#include<stdio.h>
#include<stdlib.h>

int main(){
    int size=0;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    int *a = (int*)malloc(size*sizeof(int));
    printf("Enter the elements of array: ");
    for(int i=0;i<size;i++)scanf("%d",&a[i]);

    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(a[j]>a[i]){
                a[i]=a[j];
                break;
            }
            if(j==size-1)a[i]=-1;
        }
    }
    
    a[size-1]=-1;
    printf("The replaced array is: ");
    for(int i=0;i<size;i++)printf("%d ",a[i]);
    printf("\n");
    free(a);
    return 0;
}