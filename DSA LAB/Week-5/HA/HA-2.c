// WAP to sort the elements inside a stack using only push and pop operation. Any number of additional stacks may be used.
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

struct stack sortStack(struct stack *s){
    struct stack tmpStack;
    tmpStack.top=-1;
    tmpStack.Stack=(int *)malloc(sizeof(int)*maxSize);
    while (!isEmpty(s->top))
    {
        int tmp = s->Stack[s->top];
        pop(s->Stack,&s->top);
        while (!isEmpty(tmpStack.top) && tmpStack.Stack[tmpStack.top] > tmp)
        {
            push(s->Stack,&s->top,tmpStack.Stack[tmpStack.top]);
            pop(tmpStack.Stack,&tmpStack.top);
        }
        push(tmpStack.Stack,&tmpStack.top,tmp);
    }
    return tmpStack;
}

int main(){
    struct stack s;
    s.top=-1;
    printf("Enter max size of stack: ");
    scanf("%d",&maxSize);
    s.Stack = (int *)malloc(sizeof(int)*maxSize);
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
    struct stack sorted = sortStack(&s);
    printf("The sorted stack: \n");
    display(sorted.Stack,sorted.top);
    return 0;
}
