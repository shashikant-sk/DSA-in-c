// WAP Write a menu driven program to perform the following operations of a stack using linked list by 
// using suitable user defined functions for each case.
#include <stdio.h>
#include <stdlib.h>

int size=0;

struct Node{
	int data;
	struct Node* link;
};

struct Node* top;

void push(int data){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->link = top;
	top = temp;
    printf("\n%d pushed succesfully!\n",data);
    size++;
}

int isEmpty(){
	return top == NULL;
}

void pop(){
	struct Node* temp;
	if (top == NULL){
		printf("\nStack Underflow\n");
        return;
	}
    int a = top->data;
    temp = top;
    top = top->link;
    temp->link = NULL;
    free(temp);
    printf("\n%d popped succesfully!\n",a);
    size--;
}

void display()
{
	struct Node* temp;
	if (top == NULL){
		printf("\nStack Underflow\n");
		return;
	}
    temp = top;
    printf("\n");
    while (temp != NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main()
{
    while(1){
        int choice;
        printf( "\n--------MENU--------\n"
                "1)Push a number to stack.\n"
                "2)Pop a number from stack.\n"
                "3)To display the stack.\n"
                "4)To check if stack is empty.\n"
                "5)Stack count.\n"
                "6)Exit.\n"
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
                    push(n);
                } 
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                if(isEmpty())printf("\nStack is Empty!\n");
                else printf("\nStack is not Empty!\n");
                break;
            case 5:
                printf("\nStack count = %d\n",size);
                break;
            case 6:
                return 0;
                break;
            default:
                printf("Enter a valid choice!\n");
                break;
        }
    }
	return 0;
}