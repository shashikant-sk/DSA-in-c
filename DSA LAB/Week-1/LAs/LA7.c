// Let A be nXn square dynamic matrix. WAP by using appropriate user defined functions for the following:
// a) Find the number of nonzero elements in A
// b) Find the sum of the elements above the leading diagonal.
// c) Display the elements below the minor diagonal.
// d) Find the product of the diagonal elements.
#include<stdio.h>
#include<stdlib.h>

int number_of_non_zero(int **a,int n){
    int non_zero=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(a[i][j])non_zero++;
    return non_zero;
}

int sum_of_lead(int **a,int n){
    int sum=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(j>i)sum+=a[i][j];
    return sum;
}

void display_below_minor(int **a,int n){
    printf("The elements below the minor diagonal are....");
    for(int i=0;i<n;i++){
        for(int k=0;k<n-i-1;k++)printf(" ");
        for(int j=0;j<n;j++){
            for(int k=n;k<=2*(n-1);k++)
                if(i+j==k)printf("%d",a[i][j]);
        }
        printf("\n");
    }
}

int prod_of_diag(int **a,int n){
    int prod=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i==j || i+j==n-1)prod*=a[i][j];
    return prod;
}

int main(){
    int n=0;
    printf("Enter n of square matrix: ");
    scanf("%d",&n);
    int **a = (int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
        a[i]= (int*)malloc(n*sizeof(int));
    printf("Enter the elements of matrix: \n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    printf("Number of non-zero elements = %d\n",number_of_non_zero(a,n));
    printf("Sum of the elements above the leading diagonal = %d\n",sum_of_lead(a,n));
    display_below_minor(a,n);
    printf("Product of the diagonal elements = %d\n",prod_of_diag(a,n));
    printf("\n");
    return 0;
}