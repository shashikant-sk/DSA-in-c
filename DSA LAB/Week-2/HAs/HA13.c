// Given a singly linked list, rotate the linked list counter-clockwise by k nodes. Where k is a given positive integer. 
// For example, if the given linked list is 10->20->30->40->50->60 and k is 4, the list should be modified to 50->60->10->20->30->40. 
// Assume that k is smaller than the count of nodes in linked list.
#include<stdio.h>
#include<stdlib.h>

struct node {
	int info;
	struct node* link;
};
struct node *start = NULL;

void traverse(){
	struct node* temp;

	if (start == NULL)
		printf("\nList is empty\n");

	else {
		temp = start;
		while (temp != NULL) {
			printf("%d -> ",temp->info);
			temp = temp->link;
		}
		printf("NULL\n");
	}
}

void insert(int data){
    struct node *temp, *head;
	temp = malloc(sizeof(struct node));
    if(start==NULL){
        temp->info = data;
        temp->link = NULL;
        start = temp;
    }
    else{
        temp->link = NULL;
        temp->info = data;
        head = start;
        while (head->link != NULL) {
            head = head->link;
        }
        head->link = temp;
    }
}

int countNodes(){
    struct node* temp;
    int count=0;

	if (start != NULL){
		temp = start;
		while (temp != NULL) {
			count++;
			temp = temp->link;
		}
	}

    return count;
}

void swap(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void rotateK(int k){
    while(k--){
        struct node *temp = start;
        int t = temp->info;
        while(temp->link){
            temp->info = temp->link->info;
            temp = temp->link;
        }
        temp->info = t;
    }
}

void freeList()
{
    struct node *temp = start;
    start = start->link;
    while (start != NULL)
    {
        free(temp);
        temp = start;
        start = start->link;
    }
}

int main()
{
    int k=0;
    while(1){
        int num;
        printf("Enter (1)For entering a number \n      (0)For stop entering number\n");
        printf("Enter an option: ");
        scanf("%d",&num);
        if(num==0)break;
        else if(num==1){
            printf("Enter a number: ");
            scanf("%d",&num);
            insert(num);
        }
        else printf("Enter a valid option!\n");
    }
    printf("Enter k: ");
    scanf("%d",&k);
    printf("The inital linked list => ");
    traverse();
    rotateK(k);
    printf("The linked list after rotating counter-clockwise by k elements => ");
    traverse();
    freeList();
	return 0;
}