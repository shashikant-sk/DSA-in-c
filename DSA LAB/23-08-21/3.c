// Q3) Write a menu driven program to
// (i)  Add 2 Matrices
// (ii) Check condition and multiply 2 Matrices
// (iii)Rotate a matrix 90 degree
// (iv) Rotate a matrix 180 degree
#include<stdio.h>
#include<stdlib.h>

int main(){
    
    int r1=0,c1=0,r2=0,c2=0;
    printf("Enter number of rows of matrix1: ");
    scanf("%d",&r1);
    printf("Enter number of coloumns of matrix1: ");
    scanf("%d",&c1);
    int **a = (int **)malloc(r1 * sizeof(int *));
    for (int i=0; i < r1; i++)
        a[i] = (int *)malloc(c1 * sizeof(int));
    printf("Enter the elements of matrix1: \n");
    for(int i=0;i < r1;i++)
        for(int j=0;j < c1;j++)
            scanf("%d",&a[i][j]);
    printf("\n");

    printf("Enter number of rows of matrix2: ");
    scanf("%d",&r2);
    printf("Enter number of coloumns of matrix2: ");
    scanf("%d",&c2);
    int **b = (int **)malloc(r2 * sizeof(int *));
    for (int i=0; i < r2; i++)
        b[i] = (int *)malloc(c2 * sizeof(int));
    printf("Enter the elements of matrix2: \n");
    for(int i=0;i < r2;i++)
        for(int j=0;j < c2;j++)
            scanf("%d",&b[i][j]);
    printf("\n");

    while(1){
        int num;
        printf("------------------MENU------------------\n");
        printf("(1)For adding the 2 matrices.\n");
        printf("(2)For multiplying the 2 matrices.\n");
        printf("(3)For rotating the first matrix by 90 degree\n");
        printf("(4)For rotating the first matrix by 180 degree\n");
        printf("(5)Exit.\n");
        printf("----------------------------------------\n");
        scanf("%d",&num);
        printf("\n");
        switch (num)
        {
            case 1:
                {
                    if(r1==r2 && c1==c2){
                        for(int i = 0; i < r1; i++){
                            for(int j = 0; j < c1; j++)
                                printf("%d ",a[i][j]+b[i][j]);
                            printf("\n");
                        }
                    }
                    else
                        printf("Invalid addition.\n");
                    
                }
                break;
            case 2:
                {
                    if(c1==r2){
                        int **res = (int **)malloc(r1 * sizeof(int *));
                        for (int i=0; i < r1; i++)
                            res[i] = (int *)malloc(c2 * sizeof(int));
                        for (int i = 0; i < r1; i++) {
                            for (int j = 0; j < c2; j++) {
                                res[i][j] = 0;
                                for (int k = 0; k < c1; k++)
                                    res[i][j] += a[i][k] * b[k][j];
                            }
                        }
                        for (int i = 0; i < r1; i++) {
                            for (int j = 0; j < c2; j++)
                                printf("%d ",res[i][j]);
                            printf("\n");
                        }
                    }
                    else
                        printf("Invalid multiplication.\n");
                }
                break;
            case 3:
            {
                if(r1==c1){
                    for (int x = 0; x < r1 / 2; x++) {
                        for (int y = x; y < r1 - x - 1; y++) {
                            int temp = a[x][y];
                            a[x][y] = a[y][r1 - 1 - x];
                            a[y][r1 - 1 - x] = a[r1 - 1 - x][r1 - 1 - y];
                            a[r1 - 1 - x][r1 - 1 - y] = a[r1 - 1 - y][x];
                            a[r1 - 1 - y][x] = temp;
                        }
                    }
                    printf("The 90 degree rotated matrix is: \n");
                    for (int i = 0; i < r1; i++) {
                        for (int j = 0; j < c2; j++)
                            printf("%d ",a[i][j]);
                        printf("\n");
                    }
                }
                else
                    printf("Not a square matrix!\n");
            }
            break;
            case 4:
            {
                if(r1==c1){
                    for (int x = 0; x < r1 / 2; x++) {
                        for (int y = x; y < r1 - x - 1; y++) {
                            int temp = a[x][y];
                            a[x][y] = a[y][r1 - 1 - x];
                            a[y][r1 - 1 - x] = a[r1 - 1 - x][r1 - 1 - y];
                            a[r1 - 1 - x][r1 - 1 - y] = a[r1 - 1 - y][x];
                            a[r1 - 1 - y][x] = temp;
                        }
                    }
                    for (int x = 0; x < r1 / 2; x++) {
                        for (int y = x; y < r1 - x - 1; y++) {
                            int temp = a[x][y];
                            a[x][y] = a[y][r1 - 1 - x];
                            a[y][r1 - 1 - x] = a[r1 - 1 - x][r1 - 1 - y];
                            a[r1 - 1 - x][r1 - 1 - y] = a[r1 - 1 - y][x];
                            a[r1 - 1 - y][x] = temp;
                        }
                    }
                    printf("The 180 degree rotated matrix is: \n");
                    for (int i = 0; i < r1; i++) {
                        for (int j = 0; j < c2; j++)
                            printf("%d ",a[i][j]);
                        printf("\n");
                    }
                }
                else
                    printf("Not a square matrix!\n");
            }
            break;
            case 5:
                return 0;
            default:
                printf("Wrong choice!\n");
                break;
        }
    }
    printf("\n");
    return 0;
}