// WAP to create a double linked list of n nodes and display the linked list by using suitable 
// user defined functions for create and display operations.
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

void insert_at_front(struct node** head, int new_data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head);
    new_node->prev = NULL;
    if ((*head) != NULL)
        (*head)->prev = new_node;
    (*head) = new_node;
}

void display(struct node* node)
{
    struct node* last;
    while (node != NULL) {
        printf(" %d <->", node->data);
        last = node;
        node = node->next;
    }
    printf(" NULL\n");
}

int main(){
    struct node* head = NULL;
    insert_at_front(&head, 6);
    insert_at_front(&head, 7);
    insert_at_front(&head, 1);
    insert_at_front(&head, 3);
    insert_at_front(&head, 8);
    printf("\nCreated DLL is: ");
    display(head);
    printf("\n");
    return 0;
}
