// WAP using a function that sort an array of integers using stacks and also uses bubble sort

//!!GALAT HE VRO!!


#include<stdio.h>
#include<stdlib.h>

struct stack{
    int Stack[100];
    int top;
};

int isEmpty(struct stack s){
    return s.top==-1;
}

int top(struct stack s){
    if(s.top>=0)
        return s.Stack[s.top];
}

void push(struct stack *s,int n){
    s->Stack[++(s->top)] = n;
}

void pop(struct stack *s){
    if(!isEmpty(*s))
        s->top--;
}

void bubbleSortStack(int *a, int n){

    struct stack s1,s2;
    s1.top=s2.top=-1;
    for(int i = 0; i < n; i++)
        push(&s1,a[i]);

    for(int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            while (!isEmpty(s1))
            {
                int t = top(s1);
                pop(&s1);
                if (isEmpty(s2))
                    push(&s2,t);
                else
                {
                    if (top(s2) > t)
                    {
                        int temp = top(s2);
                        pop(&s2);
                        push(&s2,t);
                        push(&s2,temp);
                    }
                    else
                        push(&s2,t);
                }
            }
            a[n - 1 - i] = top(s2);
            pop(&s2);
        }
 
        else
        {
            while (isEmpty(s2))
            {
                int t = top(s2);
                pop(&s2);
                if (isEmpty(s1))
                    push(&s1,t);
                else
                {
                    if (top(s1) > t)
                    {
                        int temp = top(s1);
                        pop(&s1);
                        push(&s1,t);
                        push(&s1,temp);
                    }
                    else
                        push(&s1,t);
                }
            }
            a[n - 1 - i] = top(s1);
            pop(&s1);
        }
    }
     
    printf("[ ");
    for(int i = 0; i < n; i++)
        printf("%d ",a[i]);
    printf("]");
}

int main(){
    int size,i=0;
    printf("Enter size of array: ");
    scanf("%d",&size);
    int *a = (int *)malloc(sizeof(int)*size);
    printf("Enter the array elements: ");
    for(int i=0;i<size;i++)
        scanf("%d",&a[i]);
    printf("Intial array: \n");
    for(int i=0;i<size;i++)
        printf("%d ",a[i]);
    printf("\n");
    bubbleSortStack(a,size);
    // printf("The sorted array: \n");
    // for(int i=0;i<size;i++)
    //     printf("%d ",a[i]);
    printf("\n");
    return 0;
}
