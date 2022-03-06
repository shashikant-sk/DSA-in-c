// WAP to create a linked list that represents a polynomial expression with double variables (e.g.: 4x2y3-3xy+x-5y+7) and 
// display the polynomial by using user defined functions for creation and display.
#include<stdio.h>
#include<stdlib.h>

struct node {
	int coeff;
    int powX;
    int powY;
	struct node* link;
};

void traverse(struct node* head){
	struct node* temp;
	if (head == NULL)
		printf("\nList is empty\n");

	else {
		temp = head;
		while (temp != NULL) {
            printf("(%d)x^(%d)y^(%d) + ",temp->coeff,temp->powX,temp->powY);
			temp = temp->link;
		}
	}
    printf("0\n");
}

void insert(struct node** head,int coeff,int powX,int powY){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->coeff = coeff;
    temp->powX = powX;
    temp->powY = powY;
	temp->link = *head;
	*head = temp;
}

void freeList(struct node* head)
{
    struct node *temp = head;
    head = head->link;
    while (head != NULL)
    {
        free(temp);
        temp = head;
        head = head->link;
    }
}

int main()
{
    struct node* start = NULL;
    int i=1;
	while(1){
        int num;
        printf("\nEnter (1)For inputting term %d \n      (0)To stop\n",i);
        printf("Enter an option: ");
        scanf("%d",&num);
        if(num==0)break;
        else if(num==1){
            int coeff,powX,powY;
            i++;
            printf("Enter the coefficient: ");
            scanf("%d",&coeff);
            printf("Enter the power of x: ");
            scanf("%d",&powX);
            printf("Enter the power of y: ");
            scanf("%d",&powY);
            insert(&start,coeff,powX,powY);
        }
        else printf("Enter a valid option!\n");
    }
    printf("\n");
	printf("Polynomial: ");
	traverse(start);
	freeList(start);
	return 0;
}
