// WAP to remove duplicates from a linked list of n nodes.
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

void removeDup(){
    struct node *ptr1, *ptr2, *dup;
    ptr1 = start;
    while (ptr1 != NULL && ptr1->link != NULL) {
        ptr2 = ptr1;
        while (ptr2->link != NULL) {
            if (ptr1->info == ptr2->link->info) {
                dup = ptr2->link;
                ptr2->link = ptr2->link->link;
                free(dup);
            }
            else
                ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
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
    printf("The inital linked list => ");
    traverse();
    removeDup();
    printf("The linked list after removing duplicates => ");
    traverse();
    freeList();
	return 0;
}
