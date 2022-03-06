// WAP to reverse a stack with using extra stack.
#include<stdio.h>
#include<stdlib.h>

int maxSize=0;

struct stack{
    int *Stack;
    int top;
};

int isEmpty(int top){
    return top==-1;
}

void display(int *stack,int top){
    if(isEmpty(top)){
        printf("\nStack is Empty!\n");
        return;
    }
    printf("Stack -> ");
    for(int i=0;i<=top;i++){
        printf(" %d",stack[i]);
    }
    printf("\n");
}

void push(int *stack,int *top,int n){
    if(*top>=maxSize-1){
        printf("\nStack full!\n");
        return;
    }
    stack[++(*top)] = n;
}

int pop(int *stack,int *top){
    if(isEmpty(*top))
        printf("\nStack is Empty!\n");
    else return stack[(*top)--];
}

void reverseStack(struct stack *s,struct stack *revs){
    int t=s->top;
    for(int i=0;i<=t;i++)
        push(revs->Stack,&revs->top,pop(s->Stack,&s->top));
    s->top=t;
}

int main(){
    struct stack s,revs;
    s.top=-1;
    revs.top=-1;
    printf("Enter max size of stack: ");
    scanf("%d",&maxSize);
    s.Stack = (int *)malloc(sizeof(int)*maxSize);
    revs.Stack = (int *)malloc(sizeof(int)*maxSize);
    do{
        int el;
        printf("Enter element to enter: ");
        scanf("%d",&el);
        push(s.Stack,&s.top,el);
        printf("Press 1 to continue or 0 to exit: ");
        scanf("%d",&el);
        if(el==0)break;
    }while(s.top<maxSize);
    printf("Intial stack: \n");
    display(s.Stack,s.top);
    reverseStack(&s,&revs);
    printf("The reversed stack: \n");
    display(revs.Stack,revs.top);
    return 0;
}
