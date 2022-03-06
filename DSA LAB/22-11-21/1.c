// Implement a dynamic array of size n. Each element in the array is the root pointer to an individual header linked list.
// The header node has the information about a unique Linked_List_ID and number of nodes in that linked list.
// Write code to insert and remove nodes from the lists as per user entered value and Linked_List_ID.
// Also, write a function which arranger all the pointers in the array as per the increasing number of nodes in its linked list.

//Written By Hans Pattnaik ©

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} node;

typedef struct headerLinkedList
{
    int numOfNodes;
    int llid;
    node *link;
} hll;

void addNode(hll *h, node **head, int data)
{
    node *headOfList = (*head);
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->link = NULL;
    if (!headOfList)
        headOfList = new_node, h->link = headOfList;
    else
    {
        while (headOfList->link)
            headOfList = headOfList->link;
        headOfList->link = new_node;
    }
}

void deleteNode(hll *h, node **head, int data)
{
    node *temp = *head, *pos = NULL;
    if (temp == NULL)
    {
        printf("No node with given data found to delete!\n");
        return;
    }
    if (temp->data == data)
        h->link = temp->link;
    else
    {
        while (temp)
        {
            if (temp->link->data == data)
            {
                pos = temp->link;
                temp->link = pos->link;
                free(pos);
                printf("Node deleted\n");
                return;
            }
            temp = temp->link;
        }
    }
}

void arrangeHeaders(hll a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].numOfNodes < a[j].numOfNodes)
            {
                hll temp;

                temp.llid = a[i].llid;
                temp.link = a[i].link;
                temp.numOfNodes = a[i].numOfNodes;

                a[i].llid = a[j].llid;
                a[i].link = a[j].link;
                a[i].numOfNodes = a[j].numOfNodes;

                a[j].llid = temp.llid;
                a[j].link = temp.link;
                a[j].numOfNodes = temp.numOfNodes;
            }
        }
    }
}

void displayHeaderNodes(hll a[], int n)
{
    for (int i = 0; i < n; i++)
        if (a[i].llid != -1)
            printf("Linked List Id = %d , Number of nodes = %d\n", a[i].llid, a[i].numOfNodes);
}

void displayNodeList(node *head)
{
    if (!head)
    {
        printf("List is empty.\n");
        return;
    }
    while (head)
    {
        printf("%d -> ", head->data);
        head = head->link;
    }
    printf("NULL\n");
}

int main()
{
    int n;
    printf("Enter n as size of array: ");
    scanf("%d", &n);
    hll *a = (hll *)malloc(sizeof(hll) * n);
    for (int i = 0; i < n; i++)
    {
        a[i].numOfNodes = 0;
        a[i].llid = -1;
        a[i].link = NULL;
    }
    while (1)
    {
        int choice;
        printf("\n---------MENU---------\n"
               "0)Exit.\n"
               "1)Add new header.\n"
               "2)Add node to a specific header.\n"
               "3)Delete node from a specific header.\n"
               "4)Print all nodes from a specific header.\n"
               "5)Print all the headers.\n"
               "Enter a choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            return 0;
            break;
        case 1:
        {
            int llid, i;
            printf("Enter the Linked List Id: ");
            scanf("%d", &llid);
            for (i = 0; i < n; i++)
            {
                if (a[i].llid == llid)
                {
                    printf("Linked List already present!\n");
                    llid = -1;
                    break;
                }
                else if (a[i].llid == -1)
                    break;
            }
            if (llid != -1)
                a[i].llid = llid; arrangeHeaders(a, n);
        }
        break;
        case 2:
        {
            int llid, data, i;
            printf("Enter Linked List Id and data value to add: ");
            scanf("%d %d", &llid, &data);
            for (i = 0; i < n; i++)
            {
                if (a[i].llid == llid)
                {
                    addNode(&a[i], &a[i].link, data);
                    a[i].numOfNodes++;
                    printf("node added\n");
                    arrangeHeaders(a, n);
                    break;
                }
                else if (i == n - 1)
                    i = -1;
            }
            if (i == -1)
                printf("Linked List Id doens't exist!\n");
        }
        break;
        case 3:
        {
            int llid, data, i;
            printf("Enter Linked List Id and data value to delete: ");
            scanf("%d %d", &llid, &data);
            for (i = 0; i < n; i++)
            {
                if (a[i].llid == llid)
                {
                    deleteNode(&a[i], &a[i].link, data);
                    a[i].numOfNodes--;
                    // printf("node deleted\n");
                    arrangeHeaders(a, n);
                    break;
                }
                else if (i == n - 1)
                    i = -1;
            }
            if (i == -1)
                printf("Linked List Id doens't exist!\n");
        }
        break;
        case 4:
        {
            int llid, i;
            printf("Enter Linked List Id to print: ");
            scanf("%d", &llid);
            for (i = 0; i < n; i++)
            {
                if (a[i].llid == llid)
                {
                    printf("Linked list for Linked List Id = %d is: \n", llid);
                    displayNodeList(a[i].link);
                    break;
                }
                else if (i == n - 1)
                    i = -1;
            }
            if (i == -1)
                printf("Linked List Id doens't exist!\n");
        }
        break;
        case 5:
            displayHeaderNodes(a, n);
            break;
        default:
            printf("Enter a correct choice!\n");
            break;
        }
    }
    return 0;
}
