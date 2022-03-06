//WAP to print mth node from the last of a linked list of n nodes.
#include<stdio.h>
#include<stdlib.h>

struct node {
	int info;
	struct node* link;
};
struct node* start = NULL;

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

int mFromLast(int m){
    struct node *temp=start;
    int n = countNodes();
    int pos = n-m;
    while(pos--){
        temp = temp->link;
    }
    return temp->info;
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
    printf("Enter m: ");
    scanf("%d",&m);
    printf("The mth node from last = %d\n",mFromLast(m));
    freeList();
	return 0;
}