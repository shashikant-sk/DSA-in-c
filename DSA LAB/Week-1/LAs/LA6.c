// Given a dynamic array, WAP to print the next greater element (NGE) for every element.
// The next greater element for an element x is the first greater element on the right
// side of x in array. Elements for which no greater element exist, consider next 
// greater element as -1. E.g. For the input array [2, 5, 3, 9, 7], the next greater 
// elements for each elements are as follows.
// Element	NGE
// 2	     5
// 5	     9
// 3	     9
// 9	     -1
// 7	     -1
#include<stdio.h>
#include<stdlib.h>

int main(){
    int size=0,k=0;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    int *a = (int*)malloc(size*sizeof(int));
    int *nge = (int*)malloc(size*sizeof(int));
    printf("Enter the elements of array: ");
    for(int i=0;i<size;i++)scanf("%d",&a[i]),nge[i]=-1;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(a[j]>a[i]){
                nge[k]=a[j];
                break;
            }
        }
        k++;
    }
    printf("The NGE array is: ");
    for(int i=0;i<size;i++)printf("%d ",nge[i]);
    printf("\n");
    return 0;
}