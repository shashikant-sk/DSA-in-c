// Given a linked list, write a function to reverse every k nodes. (where k is an input to the function). 
// If a linked list is given as 12->23->45->89->15->67->28->98->NULL and k = 3 
// then output will be 45->23->12->67->15->89->98->28->NULL.
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
 
struct node* reverseK(struct node *head,int k){
    if (!head)return NULL;

    struct node* current = head,*next = NULL,*prev = NULL;
    int count = 0;
   
    while (current != NULL && count < k)
    {
        next  = current->link;
        current->link = prev;
        prev = current;
        current = next;
        count++;
    }
     
    if (next !=  NULL)
       head->link = reverseK(next, k);
    
    return prev;    
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
    start = reverseK(start,k);
    printf("The linked list after reversing every k slots => ");
    traverse();
    freeList();
	return 0;
}