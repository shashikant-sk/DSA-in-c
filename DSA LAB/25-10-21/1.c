// WAP to have a menu driven implementation of priority queue as per user's choice
// 1)Insertion
// 2)Deletion
// 3)Traversal
// 4)Display
#include <stdio.h>
#include <stdlib.h>

struct pqnode
{
    int data, priority;
    struct pqnode *next;
} *front = NULL, *rear = NULL;

int isEmpty()
{
    return (front == NULL);
}

void Enqueue(int data, int priority)
{
    struct pqnode *tmp, *tmp1, *tmp2;
    tmp = (struct pqnode *)malloc(sizeof(struct pqnode));
    tmp->data = data;
    tmp->priority = priority;
    tmp->next = NULL;
    if (front == NULL)
        front = tmp;
    else
    {
        tmp1 = front;
        while (tmp1->priority <= priority && tmp1)
        {
            tmp2 = tmp1;
            tmp1 = tmp1->next;
        }
        tmp2->next = tmp;
        tmp->next = tmp1;
        tmp = front;
        while (tmp->next)
            tmp = tmp->next;
    }
    rear = tmp;
}

void Dequeue()
{
    struct pqnode *tmp;
    int item, priority;
    if (isEmpty())
    {
        printf("\nQueue is Empty\n");
        return;
    }
    tmp = front;
    item = tmp->data;
    priority = tmp->priority;
    front = front->next;
    free(tmp);
    printf("\nThe deleted element is -> %d with priority = %d\n", item, priority);
}

void display()
{
    struct pqnode *ptr;
    ptr = front;
    if (isEmpty())
    {
        printf("\nQueue is Empty\n");
        return;
    }
    printf("\nQueue elements :\n\n");
    while (ptr != NULL)
    {
        printf("Element = %d , Priority = %d\n", ptr->data, ptr->priority);
        ptr = ptr->next;
    }
    printf("\n\n");
}

int main()
{
    while (1)
    {
        int choice;
        printf("\n------------------MENU------------------\n"
               "1)Insert an element\n"
               "2)Delete an element\n"
               "3)Display\n"
               "0)Exit\n"
               "Enter a choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            return 0;
            break;
        case 1:
        {
            int p, el;
            printf("Enter element and its priority: ");
            scanf("%d %d", &el, &p);
            Enqueue(el, p);
        }
        break;
        case 2:
            Dequeue();
            break;
        case 3:
            display();
            break;
        default:
            printf("\nEnter valid choice!\n");
            break;
        }
    }

    return 0;
}