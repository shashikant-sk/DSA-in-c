//•	WAP to reverse the contents of a dynamic array of n elements.
#include<stdio.h>
#include<stdlib.h>

int main(){
    int size=0;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    int *a = (int*)malloc(size*sizeof(int));
    printf("Enter the elements of array: ");
    for(int i=0;i<size;i++)scanf("%d",&a[i]);
    for(int i=0,j=size-1;i<size/2;i++,j--){
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    printf("The reversed array is: ");
    for(int i=0;i<size;i++)printf("%d ",a[i]);
    return 0;
}