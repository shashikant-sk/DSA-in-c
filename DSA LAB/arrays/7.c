
//  WAP to find out the largest even integer stored in the array of n integers. n is the user input.
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
        if(a[i]>largest && a[i]%2==0)largest=a[i];
   printf("The largest even array element = %d\n",largest);
   return 0;
}
