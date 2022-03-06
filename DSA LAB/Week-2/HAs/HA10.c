// WAP to reverse only even position nodes in a singly linked list.
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

void reverseEven(){
    int c = countNodes();
    struct node *odd=start,*even=NULL;
    if(c<=3)return; //If list size is less than 3, no changes

    //Sieveing even position elements(reversed order) and odd position elements(same order)
    while(odd && odd->link){
        struct node *temp = odd->link;
        odd->link = temp->link;
        temp->link = even;
        even = temp;
        odd = odd->link;
    }

    //Resetting odd to beggining of list to insert inverted even position elements
    odd = start;

    //Inserting the even position elements in the odd position element list
    while(even){
        struct node *temp = even->link;
        even->link = odd->link;
        odd->link = even;
        odd = odd->link->link;
        even = temp;
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
    reverseEven();
    printf("The linked list after reversing even position nodes => ");
    traverse();
    freeList();
	return 0;
}