// Given a double linked list, rotate the linked list counter-clockwise by k nodes. 
// Where k is a given positive integer. For example, if the given linked list is 10->20->30->40->50->60 and k is 4, 
// the list should be modified to 50->60->10->20->30->40. Assume that k is smaller than the count of nodes in linked list.
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
    printf("NULL <->");
    while (node != NULL) {
        printf(" %d <->", node->data);
        last = node;
        node = node->next;
    }
    printf(" NULL\n");
}

void rotateByK(struct node *node,int k){
    while(k--){
        struct node *temp = node;
        int t = temp->data;
        while(temp->next){
            temp->data = temp->next->data;
            temp = temp->next;
        }
        temp->data = t;
    }
}

int main(){
    struct node* head = NULL;
    insert_at_front(&head, 60);
    insert_at_front(&head, 50);
    insert_at_front(&head, 40);
    insert_at_front(&head, 30);
    insert_at_front(&head, 20);
    insert_at_front(&head, 10);
    printf("\nCreated DLL is: ");
    display(head);
    rotateByK(head,4);
    printf("\nRotated(by k=4) DLL is: ");
    display(head);
    printf("\n");
    return 0;
}
