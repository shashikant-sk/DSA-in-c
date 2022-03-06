// WAP to convert a given singly linked list to a circular list.
#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* link;
};

void traverse(struct node *start){
	struct node* temp;

	if (start == NULL)
		printf("\nList is empty\n");

	else {
		temp = start;
		printf("\nThe linear list is => ");
		while (temp != NULL) {
			printf("%d -> ",temp->data);
			temp = temp->link;
		}
		printf("NULL\n");
	}
}

void traverseCircular(struct node *start){
	struct node* temp;

	if (start == NULL)
		printf("\nList is empty\n");

	else {
		temp = start;
		printf("\nThe Circular list is => ");
		while (temp->link != start) {
			printf("%d -> ",temp->data);
			temp = temp->link;
		}
		printf("First node\n\n");
	}
}

void insert(struct node **start , int data){
    struct node *temp, *head;
	temp = malloc(sizeof(struct node));
    if(*start==NULL){
        temp->data = data;
        temp->link = NULL;
        *start = temp;
    }
    else{
        temp->link = NULL;
        temp->data = data;
        head = *start;
        while (head->link != NULL) {
            head = head->link;
        }
        head->link = temp;
    }
}

void convertCicular(struct node *start){
    struct node *temp = start;
    while (temp->link != NULL)
        temp = temp->link;
    temp->link = start;
}

int main(){
    struct node *start = NULL;
    insert(&start,1);
    insert(&start,2);
    insert(&start,3);
    insert(&start,4);
    insert(&start,5);
    traverse(start);
    convertCicular(start);
    traverseCircular(start);
    return 0;
}
