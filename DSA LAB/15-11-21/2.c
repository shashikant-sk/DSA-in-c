// Wap to check weather a cycle exists in a single linked list. Also, edit remove the cycle to make the linked list
// proper. Use both recursive and non-recursive techniques.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int detectLoop(struct Node *head)
{
    struct Node *slowPtr = head, *fastPtr = head;
    while (slowPtr && fastPtr && fastPtr->next)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if (slowPtr == fastPtr)
            return 1;
    }
    return 0;
}

void removeLoopIterative(struct Node **head)
{
    struct Node *fast = *head, *slow = *head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);
    if (fast == *head)
    {
        while (slow->next != *head)
            slow = slow->next;
        slow->next = NULL;
        return;
    }
    fast = *head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}

void removeLoopRecursive()
{
    
}

void printList(struct Node *node)
{
    printf("\nLinked List --> ");
    while (node != NULL)
        printf("%d -> ", node->data),
            node = node->next;
    printf("NULL\n");
}

struct Node *newNode(int key)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = key;
    temp->next = NULL;
    return temp;
}

int main()
{
    struct Node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    printf("Before making loop....\n");
    printf("Loop Detected = ");
    detectLoop(head) ? printf("TRUE\n") : printf("FALSE\n");

    head->next->next->next->next->next = head->next->next; //making LOOP(5 connected to 3)

    //Loop in linked list...
    //1---2---3---4---5-
    //        |--------|

    printf("After making loop....\n");
    printf("Loop Detected = ");
    detectLoop(head) ? printf("TRUE\n") : printf("FALSE\n");

    //linked list after removing loop...
    //1-->2-->3-->4-->5-->NULL

    printf("Removing loop using iterative approach....\n");
    removeLoopIterative(&head);

    printf("Linked List after removing loop.....");
    printList(head);
    return 0;
}
