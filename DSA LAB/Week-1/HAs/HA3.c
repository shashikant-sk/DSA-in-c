// WAP to arrange the elements of a dynamic array such that all even numbers are followed by all odd numbers.
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int *a = (int*)malloc(n*sizeof(int));
    printf("Enter the array elements: ");
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n-1;j++)
            if(a[j]%2==0 && a[j+1]%2!=0){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }

    printf("The updated array elements are....\n");
    for(int i=0;i<n;i++)printf("%d ",a[i]);
    printf("\n");
    free(a);
    return 0;
}