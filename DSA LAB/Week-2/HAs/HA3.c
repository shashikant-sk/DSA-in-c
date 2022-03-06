// WAP to reverse the first m elements of a linked list of n nodes.
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

void reverseM(int k){

    struct node *temp = start;
    int count = 1;
    while (count < k) {
        temp = temp->link;
        count++;
    }

    struct node* joint = temp->link;
    temp->link = NULL;
 
    struct node *prev = NULL,*current = start,*next;
    while (current) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    start = prev;
    current = start;
    while (current->link != NULL)
        current = current->link;
 
    current->link = joint;
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
    int m;
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
    printf("Enter m: ");
    scanf("%d",&m);
    reverseM(m);
    printf("The linked list reversed till m elements => ");
    traverse();
    freeList();
	return 0;
}
