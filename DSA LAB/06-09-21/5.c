// WAP to create a single circular double linked list of n nodes and display the 
// linked list by using suitable user defined functions for create and display operations.
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

void insert_at_end(struct node** start, int value)
{
	if (*start == NULL)
	{
		struct node* new_node = (struct node*)malloc(sizeof(struct node));
		new_node->data = value;
		new_node->next = new_node->prev = new_node;
		*start = new_node;
		return;
	}
	struct node *last = (*start)->prev;
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = value;
	new_node->next = *start;
	(*start)->prev = new_node;
	new_node->prev = last;
	last->next = new_node;
}

void display(struct node* start)
{
    struct node *temp = start;
    while (temp->next != start)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
}

int main(){
    struct node* head = NULL;
    insert_at_end(&head, 6);
    insert_at_end(&head, 7);
    insert_at_end(&head, 1);
    insert_at_end(&head, 3);
    insert_at_end(&head, 8);
    printf("\nCreated circular DLL is: \n");
    display(head);
    printf("\n^-----------------------^\n");
    printf("\n");
    return 0;
}