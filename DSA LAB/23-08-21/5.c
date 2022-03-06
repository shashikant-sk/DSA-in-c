// Q5) Wap to implement a Sparse matrix triplet representation using an array.
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int r=0,c=0;
    printf("Enter number of rows of matrix: ");
    scanf("%d",&r);
    printf("Enter number of coloumns of matrix: ");
    scanf("%d",&c);
    int **a = (int **)malloc(r * sizeof(int *));
    for (int i=0; i < r; i++)
        a[i] = (int *)malloc(c * sizeof(int));
    printf("Enter the elements of sparse matrix: \n");
    for(int i=0;i < r;i++)
        for(int j=0;j < c;j++)
            scanf("%d",&a[i][j]);
    printf("\n");
 
    int size = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (a[i][j] != 0)
                size++;

    int **arr = (int **)malloc(size * sizeof(int *));
    for (int i=0; i < size; i++)
        arr[i] = (int *)malloc(3 * sizeof(int));
 
    int k = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (a[i][j] != 0)
            {
                arr[k][0] = i;
                arr[k][1] = j;
                arr[k][2] = a[i][j];
                k++;
            }
    printf("The matrix representation is: \n");
    printf("row col val\n");
    printf(" %d   %d   %d\n",r,c,size);
    for(int i=0;i<size;i++){
        for(int j=0;j<3;j++)
            printf(" %d  ", arr[i][j]);
        printf("\n");
    }
    free(a);
    free(arr);
    return 0;
}