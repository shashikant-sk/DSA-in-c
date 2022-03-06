// WAP to take n number of data values from the user, each data value has 3 parts, amount , quantity and unit price.
// Ask the user to take details of n data values and store in a linked list. User shall enter the amount and quantity.
// The unit price has to be calculated by you. Insert , delete , display and sort(asc using unit price).
// Implement using double linked list.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    float amount, quantity, uPrice;
    struct node *next, *prev;
};

void insert(struct node **start, float amount, float quantity)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->amount = amount;
    new_node->quantity = quantity;
    new_node->uPrice = amount / quantity;
    new_node->prev = NULL;
    new_node->next = NULL;

    if ((*start) == NULL)
        (*start) = new_node;
    else
    {
        struct node *temp = *start;
        while (temp->next)
        {
            temp = temp->next;
        }
        new_node->prev = temp;
        temp->next = new_node;
    }
}

void display(struct node *start)
{
    struct node *temp = start;
    printf("\nThe price list: \n");
    while (temp != NULL)
    {
        printf("Amount = %.2f , Quantity = %.2f , Unit Price = %.2f\n", temp->amount, temp->quantity, temp->uPrice);
        temp = temp->next;
    }
}

void _deleteNode(struct node **start, struct node *del)
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
    printf("\nFirst instance of given Item deleted successfully!\n");
}

void deleteNode(struct node **start, float amount, float quantity)
{
    if ((*start) == NULL)
    {
        printf("\nList is Empty!\n");
        return;
    }
    struct node *current = *start;
    while (current->next)
    {
        if (current->amount == amount && current->quantity == quantity)
        {
            _deleteNode(start, current);
            break;
        }
        current = current->next;
    }
}

void sort(struct node **start)
{
    struct node *temp = *start, *temp1 = NULL;
    while (temp->next)
    {
        temp1 = temp->next;
        while (temp1)
        {
            if (temp->uPrice > temp1->uPrice)
            {
                float amount = temp->amount, quantity = temp->quantity, uPrice = temp->uPrice;
                temp->amount = temp1->amount, temp->quantity = temp1->quantity, temp->uPrice = temp1->uPrice;
                temp1->amount = amount, temp1->quantity = quantity, temp1->uPrice = uPrice;
            }
            temp1 = temp1->next;
        }
        temp = temp->next;
    }
}

int main()
{
    struct node *head = NULL;
    while (1)
    {
        int choice;
        printf("\n--------MENU--------\n"
               "0)Exit.\n"
               "1)Push an item to list.\n"
               "2)Delete an item from list.\n"
               "3)To display the list.\n"
               "4)To sort the list in ascending order according to unit price.\n"
               "Enter a choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            return 0;
            break;
        case 1:
        {
            float amount, quantity;
            printf("Enter quantity and amount to insert: ");
            scanf("%f %f", &quantity, &amount);
            insert(&head, amount, quantity);
        }
        break;
        case 2:
        {
            float amount, quantity;
            printf("Enter quantity and amount to delete: ");
            scanf("%f %f", &quantity, &amount);
            deleteNode(&head, amount, quantity);
        }
        break;
        case 3:
            display(head);
            break;
        case 4:
            sort(&head);
            break;
        default:
            printf("Enter a valid choice!\n");
            break;
        }
    }
    return 0;
}
