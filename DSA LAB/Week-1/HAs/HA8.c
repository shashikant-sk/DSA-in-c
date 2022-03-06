// WAP to find the largest number and counts the occurrence of the largest number in a dynamic array of n integers 
//using a single loop.
#include<stdio.h>
#include<stdlib.h>

int main(){
    int size=0;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    int *a = (int*)malloc(size*sizeof(int));
    printf("Enter the elements of array: ");
    for(int i=0;i < size;i++)scanf("%d",&a[i]);
    int largest=a[0],count=1;
    for(int i=1;i < size;i++){
        if(largest < a[i]){
            count=1;
            largest=a[i];
        }
        else if(a[i]==largest)count++;
    }

    printf("The largest element = %d\n",largest);
    printf("The count of largest element = %d\n",count);
    return 0;
}