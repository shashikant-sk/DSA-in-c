//WAP to add two distances (in km-meter) by passing structure to a function.
#include<stdio.h>
#include<stdlib.h>
 
struct distance
{
    int km;  
    int meter;
};
 
struct distance add(struct distance *s1, struct distance *s2){
    struct distance s;
    s.meter = (s1->meter+s2->meter)%1000;
    s.km = s1->km + s2->km + ((s1->meter+s2->meter)/1000);
    return s;
}

 
int main()
{
    struct distance s1,s2;
    printf("Enter first distance: \n");
    printf("Enter km: \n");
    scanf("%d",&s1.km);
    printf("Enter meter: \n");
    scanf("%d",&s1.meter);

    printf("Enter second distance: \n");
    printf("Enter km: \n");
    scanf("%d",&s2.km);
    printf("Enter meter: \n");
    scanf("%d",&s2.meter);

    struct distance s = add(&s1,&s2);
    printf("Sum of distance = %d km and %d meters\n",s.km,s.meter);
    return 0;
}