// Given an unsorted dynamic array of size n, WAP to find and display the number of 
// elements between two elements a and b (both inclusive). 
// E.g. Input : arr = [1, 2, 2, 7, 5, 4], a=2 and b=5, 
// Output : 4 and the numbers are: 2, 2, 5, 4.
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int size=0,a=0,b=0,count=0;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    int *arr = (int*)malloc(size*sizeof(int));
    printf("Enter the elements of array: ");
    for(int i=0;i<size;i++)scanf("%d",&arr[i]);
    printf("Enter a and b(range): ");
    scanf("%d %d",&a,&b);
    for(int i=0;i<size;i++){
        if(arr[i]==a){a=i;break;}
    }
    for(int i=0;i<size;i++){
        if(arr[i]==b){b=i;break;}
    }
    printf("Number of elements in given range = %d\n",abs(b-a)+1);
    return 0;
}