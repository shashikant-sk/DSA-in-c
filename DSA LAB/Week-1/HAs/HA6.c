// WAP to sort rows of a dynamic matrix having m rows and n columns in ascending and columns in descending order.
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
        for(int j=0;j<c;j++)
            scanf("%d",&a[i][j]);

    printf("Before arranging rows in ascending:\n");
    for(int i=0;i < r;i++){
        for(int j=0;j < c;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }


    for(int i=0;i < r;i++)
        for(int j=0;j < c;j++)
            for(int k=j+1;k < c;k++)
                if(a[i][j] > a[i][k])
                {
                    int temp=a[i][j];
                    a[i][j]=a[i][k];
                    a[i][k]=temp;
                }

    printf("After sorting rows in ascending: \n");
    for(int i=0;i < r;i++){
        for(int j=0;j < c;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }

    for(int i=0;i < r;i++)
        for(int j=0;j < c;j++)
            if(j >= i){
                int t=a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = t;
            }
    for(int i=0;i < r;i++)
        for(int j=0;j < c;j++)
            for(int k=j+1;k < c;k++)
                if(a[i][j] < a[i][k])
                {
                    int temp=a[i][j];
                    a[i][j]=a[i][k];
                    a[i][k]=temp;
                }
    for(int i=0;i < r;i++)
        for(int j=0;j < c;j++)
            if(j >= i){
                int t=a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = t;
            }

    printf("After arranging rows in ascending and coloumns in descending:\n");
    for(int i=0;i < r;i++){
        for(int j=0;j < c;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    printf("\n");
    return 0;
}