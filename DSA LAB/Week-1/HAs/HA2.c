//WAP to find out the second smallest and second largest element stored in a dynamic array.
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
            if(a[j]>a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
            
    printf("2nd greatest element = %d\n",a[n-2]);
    printf("2nd smallest element = %d\n",a[1]);
    free(a);
    return 0;
}