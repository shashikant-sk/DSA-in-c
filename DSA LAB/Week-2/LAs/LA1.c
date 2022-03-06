// AP to store n employee’s data such as employee name, gender, designation, department, basic pay. 
// Calculate the gross pay of each employees as follows:
// Gross pay = basic pay + HR + DA
// HR=25% of basic and DA=75% of basic.
#include<stdio.h>
#include<stdlib.h>
 
struct Employee
{
    int id;  
    char name[50];  
    int age;
    int basicpay;
};
 
void getDetails(struct Employee *s)
{
    printf("Enter the employee details: \n");
    printf("Enter the name: ");
    scanf("%s",s->name);
    printf("Enter the age: ");
    scanf("%d",&s->age);
    printf("Enter the ID: ");
    scanf("%d",&s->id);
    printf("Enter the basic pay: ");
    scanf("%d",&s->basicpay);
}

void display(struct Employee s)
{
    float grossSal = (float)(s.basicpay)*2;
    printf("\t%d\t    %s\t%d\t   %.2f\n",s.id,s.name,s.age,grossSal);
}
 
int main()
{
    int n;
    printf("Enter the number of employees you want: ");
    scanf("%d",&n);
    struct Employee *a = (struct Employee *)malloc(n*sizeof(struct Employee));
    for(int i=0;i<n;i++)
        getDetails(&a[i]);
    printf("-------------------------------------------------------\n");
    printf("| Employee ID |     Name     |  Age  |  Gross Salary  |\n");
    for(int i=0;i<n;i++)
        display(a[i]);
    printf("-------------------------------------------------------\n");
    return 0;
}