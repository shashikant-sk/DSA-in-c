// Q2) Write a menu driven program to
// (i)  Print the upper triangular Matrix
// (ii) Print the lower triangular Matrix
// (iii)Print the diagonal elements
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

    while(1){
        int num;
        printf("------------------MENU------------------\n");
        printf("(1)For printing upper triangular matrix.\n");
        printf("(2)For printing lower triangular matrix.\n");
        printf("(3)For printing diagonal elements.\n");
        printf("(4)Exit.\n");
        printf("----------------------------------------\n");
        scanf("%d",&num);
        printf("\n");
        switch (num)
        {
            case 1:
                {
                    for(int i = 0; i < r; i++){
                        for(int j = 0; j < c; j++)
                            if (i > j)
                                printf("0 ");
                            else
                                printf("%d ",a[i][j]);
                        printf("\n");
                    }
                }
                break;
            case 2:
                {
                    for(int i = 0; i < r; i++){
                        for(int j = 0; j < c; j++)
                            if (i < j)
                                printf("0 ");
                            else
                                printf("%d ",a[i][j]);
                        printf("\n");
                    }
                }
                break;
            case 3:
            {
                for(int i = 0; i < r; i++){
                    for(int j = 0; j < c; j++)
                        if (i != j)
                            printf("0 ");
                        else
                            printf("%d ",a[i][j]);
                    printf("\n");
                }
            }
            break;
            case 4:
                return 0;
            default:
                printf("Wrong choice!\n");
                break;
        }
    }
    printf("\n");
    return 0;
}