// WAP to find number of occurrences of all elements in a linked list.
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

void countOcc(){
    struct node *ptr1, *ptr2, *dup;
    int count=0;
    ptr1 = start;
    while (ptr1 != NULL) {
        ptr2 = ptr1;
        int count=1;
        while (ptr2->link != NULL) {
            if (ptr1->info == ptr2->link->info) {
                dup = ptr2->link;
                ptr2->link = ptr2->link->link;
                free(dup);
                count++;
            }
            else
                ptr2 = ptr2->link;
        }
        printf("%d is present %d times.\n",ptr1->info,count);
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
    countOcc();
    freeList();
	return 0;
}
