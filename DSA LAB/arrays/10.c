//  WAP to display the array elements in reverse order.

#include<stdio.h>

int main()
{ 
   int a[50],size=0,largest=0;
   printf("Enter size of array: ");
   scanf("%d",&size);
   printf("Enter the array elements: ");
   for(int i=0;i<size;i++)scanf("%d",&a[i]);
   for(int i=0,j=size-1;i<size/2;i++,j--){
       int t = a[i];
       a[i] = a[j];
       a[j] = t;
   }
   printf("The array elemets in reverse order: \n");
   for(int i=0;i<size;i++)printf("%d ",a[i]);
   return 0;
}
