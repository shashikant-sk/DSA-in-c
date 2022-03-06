// WAP to create a double circular double linked list of n nodes and display the 
// linked list by using suitable user defined functions for create and display operations.
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next,*prev;
};

void insert(struct node **start,int value){
    if (*start == NULL)
    {
        struct node* new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = value;
        new_node->next = new_node->prev = new_node;
        *start = new_node;
        return;
    }
    struct node *last = (*start)->prev;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = *start;
    (*start)->prev = new_node;
    new_node->prev = last;
    last->next = new_node;
}

void display(struct node *start){
    struct node *temp = start;
 
    printf("\nCircular DLL -> \n");
    while (temp->next != start){
        if(temp==start)printf("/");
        else if(temp->next->next == start)printf("\\");
        else printf("---------->");
        temp = temp->next;
    }
    printf("\n");
    temp = temp->next;
    while (temp->next != start)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("%d \n", temp->data);
    temp = temp->next;
    while (temp->next != start){
        if(temp==start)printf("\\");
        else if(temp->next->next == start)printf("/");
        else printf("<----------");
        temp = temp->next;
    }
    printf("\n\n");
}

int main(){
    struct node *start=NULL;
    insert(&start,1);
    insert(&start,2);
    insert(&start,3);
    insert(&start,4);
    insert(&start,5);
    display(start);
    return 0;
}
