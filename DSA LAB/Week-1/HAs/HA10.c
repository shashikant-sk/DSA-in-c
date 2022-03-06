// WAP to swap all the elements in the 1st column with all the corresponding elements in the last column, 
// and 2nd column with the second last column and 3rd with 3rd last etc. of a 2-D dynamic array.  Display the matrix.
#include<stdio.h>
#include<stdlib.h>

int main(){
    int r=0,c=0;
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

    for(int i=0;i < r;i++)
        for(int j=0;j < c/2;j++){
            int t = a[i][j];
            a[i][j] = a[i][c-j-1];
            a[i][c-j-1] = t;
        }

    printf("The desired array is: \n");
    for(int i=0;i < r;i++){
        for(int j=0;j < c;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    printf("\n");
    return 0;
}