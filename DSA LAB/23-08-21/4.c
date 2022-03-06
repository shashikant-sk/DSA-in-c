// Q4) Wap to convert a general Sparse matrix to a diagonal matrix.
#include<stdio.h>
#include<stdlib.h>

int main(){
    int r=0,c=0,size=0;
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
            scanf("%d",&a[i][j]),a[i][j]!=0?size++:size;
    printf("\n");

    int *b = (int *)malloc(size*sizeof(int)),k=0;
    for(int i=0;i < r;i++)
        for(int j=0;j < c;j++)
            if(a[i][j]!=0)b[k]=a[i][j],k++;

    for(int i=0;i < size;i++){
        for(int j=0;j < size;j++){
            if((i==j)&& k>=1)printf(" %d ",b[k-1]),k--;
            else printf(" 0 ");
        }
        printf("\n");
    } 
    printf("\n");
    return 0;
}