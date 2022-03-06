// WAP to search an element in a simple linked list, if found delete that node and insert that node at beginning. Otherwise display an appropriate message.
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

int delete(int m){
    struct node *temp,*position;
    int pos=0,i = 1;

	if (start != NULL){
		temp = start;
		while (temp != NULL) {
            pos++;
            if(temp->info==m)break;
			temp = temp->link;
		}
	}

    pos = temp==NULL?-1:pos;

	if (start == NULL)
		printf("\nList is empty\n");
    else if(pos==-1)
        printf("Element not found!\n");
	else {
		
		position = malloc(sizeof(struct node));
		temp = start;

		if(pos==1){
            if (start == NULL)
                printf("\nList is empty\n");
            else {
                temp = start;
                start = start->link;
                free(temp);
            }
		}
		else{
			while (i < pos - 1) {
				temp = temp->link;
				i++;
			}
			position = temp->link;
			temp->link = position->link;

			free(position);
		}
	}
    return pos;
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
    printf("The initial linked list => ");
    traverse();
    printf("Enter element to search and delete: ");
    scanf("%d",&m);
    int pos = delete(m);
    if(pos!=-1){
        printf("The linked list after deletion => ");
        traverse();
    }
    freeList();
	return 0;
}
