
// WAP to store max. 100 numbers into an array. Print all the elements that are three digit even
// integers.

#include<stdio.h>

int main()
{ 
   int a[100],size=0;
   printf("Enter size of array: ");
   scanf("%d",&size);
   printf("Enter the array elements: ");
   for(int i=0;i<size;i++)scanf("%d",&a[i]);
   printf("The array elements are....\n");
   for(int i=0;i<size;i++)
    if(a[i]%2==0 && (a[i]>=100&&a[i]<=999))
        printf("%d ",a[i]);
   return 0;
}
