// WAP Write a menu driven program to perform the following operations of a stack using array by 
// using suitable user defined functions for each case.
// a) Check if the stack is empty b) Display the contents of stack c) Push d) Pop
#include<stdio.h>
#include<stdlib.h>

int top=-1,maxSize=0;

int isEmpty(){
    return top==-1;
}

void display(int *stack){
    if(isEmpty()){
        printf("\nStack is Empty!\n");
        return;
    }
    printf("\nStack -> ");
    for(int i=0;i<=top;i++){
        printf(" %d",stack[i]);
    }
    printf("\n");
}

void push(int *stack,int n){
    if(top>=maxSize-1){
        printf("\nStack full!\n");
        return;
    }
    top++;
    stack[top] = n;
}

void pop(int *stack){
    if(isEmpty()){
        printf("\nStack is Empty!\n");
        return;
    }
    printf("\nElement popped = %d\n",stack[top]);
    top--;
}

int main(){
    printf("Enter max size of stack: ");
    scanf("%d",&maxSize);
    int *stack = (int *)malloc(sizeof(int)*maxSize);
    while(top<maxSize){
        int choice;
        printf( "\n--------MENU--------\n"
                "1)Push a number to stack.\n"
                "2)Pop a number from stack.\n"
                "3)To display the stack.\n"
                "4)To check if stack is empty.\n"
                "5)Exit.\n"
        );
        printf("Enter a choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                {
                    int n;
                    printf("\nEnter a number to push: ");
                    scanf("%d",&n);
                    push(stack,n);
                } 
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                display(stack);
                break;
            case 4:
                if(isEmpty())printf("\nStack is Empty!\n");
                else printf("\nStack is not Empty!\n");
                break;
            case 5:
                return 0;
                break;
            default:
                printf("Enter a valid choice!\n");
                break;
        }
    }
    return 0;
}