// Write a menu driven program to perform the following operations in a double linked list by using suitable user defined functions for each case.
// a) Traverse the list forward,  
// b) Traverse the list backward, 
// c) Check if the list is empty
// d) Insert a node at the certain position (at beginning/end/any position)
// e) Delete a node at the certain position (at beginning/end/any position)
// f) Count the total number of nodes, 
// g) Search for an element in the linked list
// Verify & validate each function from main method
#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node *prev, *next;
};
struct node* start = NULL;

void traverseForward(){
    if (start == NULL) {
		printf("\nList is empty\n");
		return;
	}
	struct node* temp;
	temp = start;
    printf(" NULL <->");
	while (temp != NULL) {
		printf(" %d <-> ", temp->info);
		temp = temp->next;
	}
    printf(" NULL \n");
}

void traverseBackward(){
    struct node *last,*node = start;
    while (node != NULL) {
        last = node;
        node = node->next;
    }
    printf(" NULL <->");
    while (last != NULL) {
        printf(" %d <-> ", last->info);
        last = last->prev;
    }
    printf(" NULL \n");
}

void isEmpty(){
    if(start==NULL)printf("\nList is empty!\n");
    else printf("\nList is not empty!\n");
}

void insertAtFront()
{
	int data;
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	temp->info = data;
	temp->prev = NULL;
	temp->next = start;
    if(start!=NULL)start->prev = temp;
	start = temp;
}

void insertAtEnd()
{
	int data;
	struct node *temp, *trav;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->next = NULL;
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	temp->info = data;
	temp->next = NULL;
	trav = start;
	if (start == NULL) {

		start = temp;
	}
	else {
		while (trav->next != NULL)
			trav = trav->next;
		temp->prev = trav;
		trav->next = temp;
	}
}

void insertAtPosition()
{
	int data, pos, i = 1;
	struct node *temp, *newnode;
	newnode = malloc(sizeof(struct node));
	newnode->next = NULL;
	newnode->prev = NULL;
	printf("\nEnter position : ");
	scanf("%d", &pos);
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	newnode->info = data;
	temp = start;
	if (start == NULL) {
		start = newnode;
		newnode->prev = NULL;
		newnode->next = NULL;
	}
	else if (pos == 1) {
		newnode->next = start;
		newnode->next->prev = newnode;
		newnode->prev = NULL;
		start = newnode;
	}
	else {
		while (i < pos - 1) {
			temp = temp->next;
			i++;
		}
		newnode->next = temp->next;
		newnode->prev = temp;
		temp->next = newnode;
		temp->next->prev = newnode;
	}
}

void deleteFirst()
{
	struct node* temp;
	if (start == NULL)
		printf("\nList is empty\n");
	else {
		temp = start;
		start = start->next;
		if (start != NULL)
			start->prev = NULL;
		free(temp);
	}
}

void deleteEnd()
{
	struct node* temp;
	if (start == NULL)
		printf("\nList is empty\n");
	temp = start;
	while (temp->next != NULL)
		temp = temp->next;
	if (start->next == NULL)
		start = NULL;
	else {
		temp->prev->next = NULL;
		free(temp);
	}
}

void deletePosition()
{
	int pos, i = 1;
	struct node *temp, *position;
	temp = start;
	if (start == NULL)
		printf("\nList is empty\n");
	else {
		printf("\nEnter position : ");
		scanf("%d", &pos);
		if (pos == 1) {
			position = start;
			start = start->next;
			if (start != NULL) {
				start->prev = NULL;
			}
			free(position);
			return;
		}
		while (i < pos - 1) {
			temp = temp->next;
			i++;
		}
		position = temp->next;
		if (position->next != NULL)
			position->next->prev = temp;
		temp->next = position->next;
		free(position);
	}
}

void countNodes(){
    int count=0;
	struct node* temp=start;
	while (temp != NULL) {
		count++;
		temp = temp->next;
	}
    printf("Number of nodes = %d\n",count);
}

void search(){
    int el,pos=0;
	struct node *temp=start;
	if (start == NULL)
		printf("\nList is empty\n");
	else {
		printf("\nEnter element to search for : ");
		scanf("%d", &el);
		while (temp != NULL) {
            pos++;
            if(el==temp->info)break;
            temp = temp->next;
        }
        if(temp!=NULL)
            printf("%d found at %d position\n",el,pos);
        else
            printf("Element not found!\n");
	}
}

int main()
{
	int choice;
	while (1) {
        printf("\n--------------MENU--------------\n");
		printf("\n\t1 To traverse the list forward\n");
        printf("\t2 To traverse the list backward\n");
        printf("\t3 For checking if the list is empty\n");
		printf("\t4 For insertion at starting\n");
		printf("\t5 For insertion at end\n");
		printf("\t6 For insertion at any position\n");
		printf("\t7 For deletion of first element\n");
		printf("\t8 For deletion of last element\n");
		printf("\t9 For deletion of element at any position\n");
        printf("\t10 For counting total number of nodes\n");
        printf("\t11 For searching an element\n");
		printf("\t12 To exit\n");
		printf("\nEnter Choice :\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			traverseForward();
			break;
        case 2:
			traverseBackward();
			break;
        case 3:
			isEmpty();
			break;
		case 4:
			insertAtFront();
			break;
		case 5:
			insertAtEnd();
			break;
		case 6:
			insertAtPosition();
			break;
		case 7:
			deleteFirst();
			break;
		case 8:
			deleteEnd();
			break;
		case 9:
			deletePosition();
			break;
        case 10:
			countNodes();
			break;
        case 11:
			search();
			break;
		case 12:
			return 0;
			break;
		default:
			printf("Incorrect Choice. Try Again \n");
			continue;
		}
	}
	return 0;
}
