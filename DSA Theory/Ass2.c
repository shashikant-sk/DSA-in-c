//WAP to implement Non-recursive algorithm for in-order traversal.
#include <stdio.h>
#include <stdlib.h>

typedef struct BST
{
    int data;
    struct BST *left, *right;
} BST;

BST* stack[100];
int top = -1;

BST* GetTop()
{
    return stack[top];
}

void push(BST* el)
{
    if (top < 99)
        stack[++top] = el;
}

void pop()
{
    if (top > -1)
        top--;
}

int Isempty()
{
    return (top == -1);
}

void insertBST(BST **root, int data)
{
    BST *newNode = (BST *)malloc(sizeof(BST));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    if (!(*root))
        *root = newNode;
    else
    {
        BST *prev = NULL, *tmp = *root;
        while (tmp)
        {
            prev = tmp;
            if (tmp->data > data)
                tmp = tmp->left;
            else if (tmp->data < data)
                tmp = tmp->right;
        }
        if (prev->data > data)
            prev->left = newNode;
        else
            prev->right = newNode;
    }
}

void createBST(BST **root)
{
    int choice = 1;
    do
    {
        int data = 0;
        printf("\nEnter a number to enter in BST: ");
        scanf("%d", &data);
        insertBST(root, data);
        printf("\nPress 1 to enter a value to BST or 0 to exit: ");
        scanf("%d", &choice);
    } while (choice == 1);
}

void Inorder(BST *root)
{
    BST *curr = root;

    while (curr != NULL || !Isempty())
    {
        while (curr != NULL)
        {
            push(curr);
            curr = curr->left;
        }
        curr = GetTop();
        pop();
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

int main()
{
    BST *root = NULL;
    while (1)
    {
        int choice;
        printf("\n----------------------------------------\n"
               "\tBinary Search Tree Menu\n"
               "----------------------------------------\n"
               "0. Quit\n"
               "1. Create\n"
               "2. Iterative In-Order Traversal\n"
               "----------------------------------------\n"
               "Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            return 0;
            break;
        case 1:
            createBST(&root);
            break;
        case 2:
            if (root == NULL)
            {
                printf("\nBST EMPTY!\n");
                break;
            }
            printf("In-order traversal: ");
            Inorder(root);
            printf("\n");
            break;
        default:
            printf("\nEnter a valid choice!\n");
            break;
        }
    }
    return 0;
}