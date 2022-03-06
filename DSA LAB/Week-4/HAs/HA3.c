// WAP to remove the duplicates in a sorted double linked list.
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next,*prev;
};

void push(struct node** start, int new_data)
{
    struct node* new_node =(struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->prev = NULL;
 
    new_node->next = (*start);
 
    if ((*start) != NULL)
        (*start)->prev = new_node;
 
    (*start) = new_node;
}

void display(struct node *start){
    struct node *temp = start;
 
    printf("\nDLL -> ");
    printf("NULL <-> ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n\n");
}

void deleteNode(struct node** start, struct node* del)
{
    if (*start == NULL || del == NULL)
        return;

    if (*start == del)
        *start = del->next;
 
    if (del->next != NULL)
        del->next->prev = del->prev;
 
    if (del->prev != NULL)
        del->prev->next = del->next;
 
    free(del);
}

void removeDuplicates(struct node** start)
{
    if ((*start) == NULL)return;
 
    struct node* current = *start;
    struct node* next;
 
    while (current->next != NULL) {
        if (current->data == current->next->data)
            deleteNode(start, current->next);
        else
            current = current->next;
    }
}

int main(){
    struct node* head = NULL;
    push(&head, 12);
    push(&head, 12);
    push(&head, 10);
    push(&head, 8);
    push(&head, 8);
    push(&head, 6);
    push(&head, 4);
    push(&head, 4);
    push(&head, 4);
    push(&head, 4);
 
    printf("\nOriginal Doubly linked list:\n");
    display(head);

    removeDuplicates(&head);
    
    printf("Doubly linked list after removing duplicates:\n");
    display(head);
    return 0;
}
