// WAP by modifying the LA1 program to add two polynomials with single variable. Use the same function in LA1 written for creation & display operations 
// and write a new function for addition operations.
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

struct node* add(struct node *first,struct node *second,int k){
    struct node *ans = NULL;
    while(first->link && second->link){
        //insert(&ans,first->info + second->info);
        printf("(%d)x^%d + ",first->info + second->info,k--);
        first = first->link;
        second = second->link;
    }
    while(first->link){
        printf("(%d)x^%d + ",first->info + second->info,k--);
        //insert(&ans,first->info);
        first = first->link;
    }
    while(second->link){
        printf("(%d)x^%d + ",first->info + second->info,k--);
        //insert(&ans,second->info);
        second = second->link;
    }
    return ans;
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
    struct node *first = NULL, *second = NULL;
    int i=0,j=0;
    printf("\nEnter first polynomial: \n");
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
            insert(&first,num);
        }
        else printf("Enter a valid option!\n");
    }
    printf("\nEnter second polynomial: \n");
    while(1){
        int num;
        printf("\nEnter (1)For inputting coeffient of x^%d \n      (0)To stop\n",j);
        printf("Enter an option: ");
        scanf("%d",&num);
        if(num==0)break;
        else if(num==1){
            j++;
            printf("Enter the coefficient: ");
            scanf("%d",&num);
            insert(&second,num);
        }
        else printf("Enter a valid option!\n");
    }
    printf("\n");
	printf("First polynomial: ");
	traverse(first,i-1);
    printf("Second polynomial: ");
	traverse(second,j-1);
    int k = (i>j)?i:j;
    add(first,second,k);
	freeList(first);
    freeList(second);
	return 0;
}
