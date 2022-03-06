// Write a menu driven program to perform the following operations in a single linked list by using suitable user defined functions for each case.
// a) Traversal of the list.
// b) Check if the list is empty.
// c) Insert a node at the certain position (at beginning/end/any position).
// d) Delete a node at the certain position (at beginning/end/any position).
// e) Delete a node for the given key.
// f) Count the total number of nodes.
// g) Search for an element in the linked list.
// Verify & validate each function from main method.
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
		printf("\nThe list is => ");
		while (temp != NULL) {
			printf("%d -> ",temp->info);
			temp = temp->link;
		}
		printf("NULL\n");
	}
}

int isEmpty(){
    return !start;
}

void insertAtFront(){
	int data;
	struct node* temp;
	temp = malloc(sizeof(struct node));
	printf("\nEnter number to be inserted : ");
	scanf("%d", &data);
	temp->info = data;
	temp->link = start;
	start = temp;
}

void insertAtEnd(){
	int data;
	struct node *temp, *head;
	temp = malloc(sizeof(struct node));

	printf("\nEnter number to be inserted : ");
	scanf("%d", &data);

	temp->link = 0;
	temp->info = data;
	head = start;
	while (head->link != NULL) {
		head = head->link;
	}
	head->link = temp;
}

void insertAtPosition(){
	struct node *temp, *newnode;
	int pos, data, i = 1;
	newnode = malloc(sizeof(struct node));

	printf("\nEnter position and data :");
	scanf("%d %d", &pos, &data);

	temp = start;
	newnode->info = data;
	newnode->link = 0;
	while (i < pos - 1) {
		temp = temp->link;
		i++;
	}
	newnode->link = temp->link;
	temp->link = newnode;
}

void deleteFirst(){
	struct node* temp;
	if (start == NULL)
		printf("\nList is empty\n");
	else {
		temp = start;
		start = start->link;
		free(temp);
	}
}

void deleteEnd(){
	struct node *temp, *prevnode;
	if (start == NULL)
		printf("\nList is Empty\n");
	else {
		temp = start;
		while (temp->link != 0) {
			prevnode = temp;
			temp = temp->link;
		}
		free(temp);
		prevnode->link = 0;
	}
}

void deletePosition(int pos){
	struct node *temp, *position;
	int i = 1;

	if (start == NULL)
		printf("\nList is empty\n");

	else {
		
		position = malloc(sizeof(struct node));
		temp = start;

		if(pos==1){
			deleteFirst();
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
}

int search(int s){
    struct node* temp;
    int pos=0;

	if (start != NULL){
		temp = start;
		while (temp != NULL) {
            pos++;
            if(temp->info==s)break;
			temp = temp->link;
		}
	}

    return temp==NULL?-1:pos;
}

void deleteKey(int key){

	if (start == NULL)
		printf("\nList is empty\n");
	int pos=search(key);
	if(pos==-1)
		printf("\nElement not found!\n");
	else
		deletePosition(pos);
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
	int choice;
	while (1) {
		printf("\n------------------------MENU------------------------\n");
		printf("\t1 To see list\n");
		printf("\t2 For insertion at starting\n");
		printf("\t3 For insertion at end\n");
		printf("\t4 For insertion at any position\n");
		printf("\t5 For deletion of first element\n");
		printf("\t6 For deletion of last element\n");
		printf("\t7 For deletion of element at any position\n");
        printf("\t8 For deletion of element for any key\n");
        printf("\t9 For counting number of nodes\n");
        printf("\t10 For searching an element\n");
        printf("\t11 For checking if list is empty or not\n");
		printf("\t12 To exit\n");
		printf("----------------------------------------------------\n");
		printf("\nEnter Choice : ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			traverse();
			break;
		case 2:
			insertAtFront();
			break;
		case 3:
			insertAtEnd();
			break;
		case 4:
			insertAtPosition();
			break;
		case 5:
			deleteFirst();
			break;
		case 6:
			deleteEnd();
			break;
		case 7:
			{
				int pos;
				printf("\nEnter index : ");
				scanf("%d", &pos);
				deletePosition(pos);
			}
			break;
		case 8:
			{
				int key;
				printf("\nEnter key : ");
				scanf("%d", &key);
				deleteKey(key);
			}
			break;
		case 9:
			printf("\nNumber of nodes = %d\n",countNodes());
			break;
		case 10:
			{
				int s;
				printf("Enter element to search for: ");
				scanf("%d",&s);
				printf("\nElement found at position(-1 if not found) = %d\n",search(s));
			}
			break;
		case 11:
			isEmpty()?printf("\nList is empty!\n"):printf("\nList is not empty!\n");
			break;
		case 12:
			freeList();
			return 0;
			break;
		default:
			printf("Incorrect Choice\n");
		}
	}
	return 0;
}
