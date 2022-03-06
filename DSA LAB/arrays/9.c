
//  WAP to arrange the numbers stored in the array so that it will display first all odd numbers,
// then even numbers.

#include<stdio.h>

int main()
{ 
    int a[50],size=0;
    printf("Enter size of array: ");
    scanf("%d",&size);
    printf("Enter the array elements: ");
    for(int i=0;i<size;i++)scanf("%d",&a[i]);
    printf("The odd array elements are....\n");
    for(int i=0;i<size;i++)
        if(a[i]%2)
            printf("%d ",a[i]);
    printf("\nThe even array elements are....\n");        
    for(int i=0;i<size;i++)
        if(a[i]%2==0)
            printf("%d ",a[i]);
    return 0;
}
