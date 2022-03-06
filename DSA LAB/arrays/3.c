// WAP to find largest element stored in an array.

#include<stdio.h>

int main()
{ 
   int a[50],size=0,largest=0;
   printf("Enter size of array: ");
   scanf("%d",&size);
   printf("Enter the array elements: ");
   for(int i=0;i<size;i++)scanf("%d",&a[i]);
   largest=a[0];
   for(int i=1;i<size;i++)
        if(a[i]>largest)largest=a[i];
   printf("The largest array element = %d\n",largest);
   return 0;
}
