//•	WAP to sort a dynamic array of n numbers.
#include<stdio.h>
#include<stdlib.h>

int main(){
    int size=0;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    int *a = (int*)malloc(size*sizeof(int));
    printf("Enter the elements of array: ");
    for(int i=0;i<size;i++)scanf("%d",&a[i]);
    for(int i=0;i<size;i++){
        for(int j=0;j<size-1;j++){
            if(a[j]>a[j+1]){
                int t = a[j+1];
                a[j+1] = a[j];
                a[j] = t;
            }
        }
    }
    printf("The sorted array is: ");
    for(int i=0;i<size;i++)printf("%d ",a[i]);
    return 0;
}