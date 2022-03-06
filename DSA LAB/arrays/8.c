
//  WAP to swap the pair of elements starting from beginning.

#include<stdio.h>

int main()
{ 
   int a[50],size=0;
   printf("Enter size of array: ");
   scanf("%d",&size);
   printf("Enter the array elements: ");
   for(int i=0;i<size;i++)scanf("%d",&a[i]);
   for(int i=0;i<size-1;i+=2){
       int t=a[i];
       a[i] = a[i+1];
       a[i+1] = t;
   }
   printf("The array elements after swap are....\n");
   for(int i=0;i<size;i++)printf("%d ",a[i]);
   return 0;
}
