// WAP to implement a doubly linked list by using singly linked.
#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int num;
    struct node *next;
};
 
void move(struct node *head){
    struct node *p, *q;
    int ch;
    p = q = head;
    printf("\nPointer at %d\n", head->num);
    do{
        printf("Select option:\n1. Move front\n2. Move back\n3. Exit\nYour choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: if(q->next != NULL){
                        q = q->next;
                        printf("\nPointer at %d\n", q->num);
                    } 
                    else
                        printf("\nPointer at last node %d. Cannot move ahead.\n", q->num);
                    break;
            case 2: while (p->next != q)
                        p = p->next;
                    if (p == q)
                        printf("\nPointer at first node %d. Cannot move behind.\n", q->num);
                    else
                        q = p;
                        p = head;
                        printf("\nPointer at %d\n", q->num);
                    break;
            case 3: return;
            default: printf("\nInvalid choice entered. Try again\n");
        }
    } while (1);
}
 
void create(struct node **head){
    int c, ch;
    struct node *temp, *rear;
    do{
        printf("Enter number: ");
        scanf("%d", &c);
        temp = (struct node *)malloc(sizeof(struct node));
        temp->num = c;
        temp->next = NULL;
        if (*head == NULL)
            *head = temp;
        else
            rear->next = temp;
        rear = temp;
        printf("Do you wish to continue [1/0]: ");
        scanf("%d", &ch);
    } while (ch != 0);
    printf("\n");
}
 
void display(struct node *head){
    printf("NULL <-> ");
    while (head != NULL){
        printf("%d <-> ", head->num);
        head = head->next;
    }
    printf("NULL\n");
}
 
void release(struct node **head){
    struct node *temp;
    while ((*head) != NULL){
        temp = *head;
        (*head) = (*head)->next;
        free(temp);
    }
}

int main()
{
    struct node *p = NULL, *q = NULL;
    int result, count;
    printf("Enter data into the list\n");
    create(&p);
    printf("Displaying list:\n");
    display(p);
    move(p);
    release (&p);
    return 0;
}
