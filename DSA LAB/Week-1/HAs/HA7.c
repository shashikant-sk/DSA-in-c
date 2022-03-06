// WAP to find out the kth smallest and kth largest element stored in a dynamic array of n integers, where k<n.
#include<stdio.h>
#include<stdlib.h>

int main(){
    int size=0,k=0;
    printf("Enter the size of array and k: ");
    scanf("%d %d",&size,&k);
    int *a = (int*)malloc(size*sizeof(int));
    printf("Enter the elements of array: ");
    for(int i=0;i < size;i++)scanf("%d",&a[i]);

    for(int i=0;i < size;i++){
        for(int j=0;j < size-1;j++){
            if(a[j] > a[j+1]){
                int t = a[j+1];
                a[j+1] = a[j];
                a[j] = t;
            }
        }
    }

    printf("Kth smallest element = %d\n",a[k-1]);
    printf("Kth largest element = %d\n",a[size-k]);
    return 0;
}