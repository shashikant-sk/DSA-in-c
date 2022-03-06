// Q1) Wap to find out if a Matrix is Sparse or not. ( Ask the user for a valid and invalid category of elements and calculate accordingly.)
#include<stdio.h>
#include<stdlib.h>

int main(){
    int r=0,c=0,count=0;
    printf("Enter number of rows of matrix: ");
    scanf("%d",&r);
    printf("Enter number of coloumns of matrix: ");
    scanf("%d",&c);
    int **a = (int **)malloc(r * sizeof(int *));
    for (int i=0; i < r; i++)
        a[i] = (int *)malloc(c * sizeof(int));
    printf("Enter the elements of matrix: \n");
    for(int i=0;i < r;i++)
        for(int j=0;j < c;j++)
            scanf("%d",&a[i][j]);
    printf("\n");

    int num;
    printf("Enter invalid category: \n");
    printf("(1)Even\n");
    printf("(2)Odd\n");
    printf("(3)Zero\n");
    scanf("%d",&num);
    switch (num)
    {
        case 1:
            for(int i=0;i < r;i++)
                for(int j=0;j < c;j++)
                    if(a[i][j]%2==0)count++;
            break;
        case 2:
            for(int i=0;i < r;i++)
                for(int j=0;j < c;j++)
                    if(a[i][j]%2)count++;
            break;
        case 3:
            for(int i=0;i < r;i++)
                for(int j=0;j < c;j++)
                    if(a[i][j]==0)count++;
            break;
        default:
            break;
    }
    

    if(count > ((r*c)/2))printf("Matrix is sparse!\n");
    else printf("Matrix is not sparse!\n");
    printf("\n");
    return 0;
}