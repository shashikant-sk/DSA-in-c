//•	WAP to search an element in a dynamic array of n numbers.
#include<stdio.h>
#include<stdlib.h>

int main(){
    int size=0,el=0;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    int *a = (int*)malloc(size*sizeof(int));
    printf("Enter the elements of array: ");
    for(int i=0;i<size;i++)scanf("%d",&a[i]);
    printf("Enter element to be searched: ");
    scanf("%d",&el);
    for(int i=0;i<size;i++){
        if(a[i]==el){
            printf("%d found at index %d\n",el,i);
            return 0;
        }
    }
    printf("Element not found!");
    return 0;
}