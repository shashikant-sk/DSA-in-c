// WAP to create a linked list that represents a polynomial expression with single variable (i.e. 5x7-3x5+x2+9) and display the polynomial 
// by using user defined functions for creation and display.
#include<stdio.h>
#include<stdlib.h>

struct node {
	int info;
	struct node* link;
};

void traverse(struct node* head,int i){
	struct node* temp;
	if (head == NULL)
		printf("\nList is empty\n");

	else {
		temp = head;
		while (temp != NULL) {
            if(temp->info){
                if(temp->link)
			        printf("(%d)x^%d + ",temp->info,i);
                else
                    {printf("(%d)x^%d\n",temp->info,i);return;}
            }
            i--;
			temp = temp->link;
		}
	}
    printf("0\n");
}

void insert(struct node** head,int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
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
    int i=0;
	while(1){
        int num;
        printf("\nEnter (1)For inputting coeffient of x^%d \n      (0)To stop\n",i);
        printf("Enter an option: ");
        scanf("%d",&num);
        if(num==0)break;
        else if(num==1){
            i++;
            printf("Enter the coefficient: ");
            scanf("%d",&num);
            insert(&start,num);
        }
        else printf("Enter a valid option!\n");
    }
    printf("\n");
	printf("Polynomial: ");
	traverse(start,i-1);
	freeList(start);
	return 0;
}
