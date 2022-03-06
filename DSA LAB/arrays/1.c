// WAP to create an array that can store max. 50 integers and display the contents of the array

#include<stdio.h>

int main()
{ 
   int a[50],size=0;
   printf("Enter size of array: ");
   scanf("%d",&size);
   printf("Enter the array elements: ");
   for(int i=0;i<size;i++)scanf("%d",&a[i]);
   printf("The array elements are....\n");
   for(int i=0;i<size;i++)printf("%d ",a[i]);
   return 0;
}
