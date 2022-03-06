// WAP to find out the sum of the numbers stored in an array of integers.

#include<stdio.h>

int main()
{ 
   int a[50],size=0,sum=0;
   printf("Enter size of array: ");
   scanf("%d",&size);
   printf("Enter the array elements: ");
   for(int i=0;i<size;i++)scanf("%d",&a[i]);
   for(int i=0;i<size;i++)sum+=a[i];
   printf("The sum of array elements = %d\n",sum);
   return 0;
}
