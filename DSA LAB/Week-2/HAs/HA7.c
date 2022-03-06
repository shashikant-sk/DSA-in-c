// WAP to modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list.
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
  
int evenOdd()
{
    struct node* h;
    int count = countNodes();
  
    for (int i = 0; i < count; i++)
    {   
        struct node *temp=start;
        while(temp->link!=NULL){
            struct node *t1 = temp;
            struct node *t2 = temp->link;
            if(t1->info%2 && t2->info%2==0)
                swap(&t1->info,&t2->info);
            temp=temp->link;
        }
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
    struct node *temp = start;
    evenOdd();
    printf("The linked list after arranging even odd => ");
    traverse();
    freeList();
	return 0;
}
