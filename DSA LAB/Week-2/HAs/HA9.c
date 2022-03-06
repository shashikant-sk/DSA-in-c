// A linked list is said to contain a cycle if any node is visited more than once while traversing the list. 
// WAP to detect a cycle in a linked list.
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

int hasLoop()
{
    //Used Floyd's Cycle-Finding Algorithm!
    struct node *t1 = start, *t2 = start;
    while (t1 && t2 && t2->link) {
        t1 = t1->link;
        t2 = t2->link->link;
        if (t1 == t2)return 1;
    }
    return 0;
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
    //start->link->link->link->link = start;//Creating a loop for testing
    if(hasLoop())printf("The linked list has a cycle!\n");
    else printf("The linked list does not have a cycle!\n");
    freeList();
	return 0;
}
