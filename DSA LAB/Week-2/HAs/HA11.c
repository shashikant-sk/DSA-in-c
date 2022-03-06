// WAP to swap kth node from beginning with kth node from end in a Linked List
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

void swap(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
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

void swapKth(int k){
    struct node *t1=start,*t2=start;
    int m = countNodes()-k;
    for(int i=0;i<k-1;i++)t1 = t1->link;
    while(m--)t2 = t2->link;
    swap(&t1->info,&t2->info);
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
    swapKth(k);
    printf("The linked list after swaping kth first and last nodes => ");
    traverse();
    freeList();
	return 0;
}