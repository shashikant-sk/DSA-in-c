
// WAP to input 10 integers into an array of size 10. Print all elements.

#include<stdio.h>

int main()
{ 
   int a[10];
   printf("Enter 10 array elements: ");
   for(int i=0;i<10;i++)scanf("%d",&a[i]);
   printf("The array elements are....\n");
   for(int i=0;i<10;i++)printf("%d ",a[i]);
   return 0;
}
