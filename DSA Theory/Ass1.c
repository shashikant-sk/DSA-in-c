//Write a menu driven program to take two polynomials as input and perform operations:
//1)Display the polynomials
//2)Add the polynomials
//3)Subtract the polynomials
//4)Multiply the polynomials
#include<stdio.h>
#include<stdlib.h>

void add(int *p1,int *p2,int n){
    printf("\nAddition resultant polynomial: ");
    for(int i=n;i >= 0;i--){
        if(i!=0)
            printf("%dx^(%d) + ",p1[i]+p2[i],i);
        else
            printf("%d\n",p1[i]+p2[i]);
    }
}

void subtract(int *p1,int *p2,int n){
    printf("\nSubtraction resultant polynomial: ");
    for(int i=n;i >= 0;i--){
        if(i!=0)
            printf("%dx^(%d) + ",p1[i]-p2[i],i);
        else
            printf("%d\n",p1[i]-p2[i]);
    }
}

void multiply(int *p1,int *p2,int n){
    int *p3 = (int*)malloc(sizeof(int)*(2*n));
    for(int i=0;i <= n;i++)p3[i]=0;
    for(int i=0;i <= n;i++)
        for(int j=0;j <= n;j++)
            p3[i+j] += p1[i]*p2[j];
    printf("\nMultiplication resultant polynomial: ");
    for(int i=2*n;i >= 0;i--){
        if(i!=0)
            printf("%dx^(%d) + ",p3[i],i);
        else
            printf("%d\n",p3[i]);
    }
}

void display(int *p1,int *p2,int n){
    printf("\nFirst polynomial: ");
    for(int i=n;i >= 0;i--){
        if(i!=0)
            printf("%dx^(%d) + ",p1[i],i);
        else
            printf("%d\n",p1[i]);
    }
    printf("Second polynomial: ");
    for(int i=n;i >= 0;i--){
        if(i!=0)
            printf("%dx^(%d) + ",p2[i],i);
        else
            printf("%d\n",p2[i]);
    }
}

int main(){
    int n;
    printf("Enter highest degree of polynomial: ");
    scanf("%d",&n);
    int *p1 = (int*)malloc(sizeof(int)*(n+1));
    int *p2 = (int*)malloc(sizeof(int)*(n+1));
    printf("Enter the coefficients of first polynomial: \n");
    for(int i=0;i <= n;i++){
        printf("Enter the coefficient of x^(%d): ",i);
        scanf("%d",&p1[i]);
    }
    printf("\n");
    printf("Enter the coefficients of second polynomial: \n");
    for(int i=0;i <= n;i++){
        printf("Enter the coefficient of x^(%d): ",i);
        scanf("%d",&p2[i]);
    }
    printf("\n");
    while(1){
        int num=0;
        printf("\n------------Menu-------------\n");
        printf("1)Display the polynomials.\n");
        printf("2)Add the polynomials.\n");
        printf("3)Subtract the polynomials.\n");
        printf("4)Multiply the polynomials.\n");
        printf("5)Exit.\n");
        printf("-----------------------------\n");
        printf("Enter a choice: ");
        scanf("%d",&num);
        switch (num)
        {
            case 1:
                display(p1,p2,n);
                break;
            case 2:
                add(p1,p2,n);
                break;
            case 3:
                subtract(p1,p2,n);
                break;
            case 4:
                multiply(p1,p2,n);
                break;
            case 5:
                free(p1);
                free(p2);
                return 0;
            default:
                printf("Enter a valid choice.\n");
        }
    }
    return 0;
}