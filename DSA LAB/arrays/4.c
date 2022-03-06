
// WAP to display the array elements in ascending order.

#include<stdio.h>

int main()
{ 
   int a[50],size=0,largest=0;
   printf("Enter size of array: ");
   scanf("%d",&size);
   printf("Enter the array elements: ");
   for(int i=0;i<size;i++)scanf("%d",&a[i]);
   for(int i=0;i<size;i++)
    for(int j=0;j<size-1;j++)
        if(a[j]>a[j+1]){
            int t = a[j];
            a[j]=a[j+1];
            a[j+1]=t;
        }
   printf("The array elemets in ascending order: \n");
   for(int i=0;i<size;i++)printf("%d ",a[i]);
   return 0;
}
